#include "head.h"

void Welcome(int sockfd, int *flag) // 初始登录
{
    PL date = {};
    int i = 0;
    int type = 0;
    char buf[25] = {};
    printf("已有账户登录输入“0”\n");
    printf("注册账户输入“1”\n");
    while (i != 3)
    {
        printf("请输入你需要的功能：");
        scanf("%d", &type);
        if (type == 0 || type == 1)
        {
            *flag = 1;
            break;
        }
        else
        {
            printf("输入错误\n");
            if (i < 2)
            {
                printf("还有%d次自动退出\n", 2 - i);
            }
            i++;
        }
    }
    if (*flag == 0)
    {
        return;
    }
    switch (type)
    {
    case 0:
        type0(date, sockfd, buf);
        while (strcmp(buf, "用户名存在") != 0)
        {
            printf("%s\n", buf);
            printf("是否需要继续输入用户名？\n");
            printf("输入“1”继续，输入其他内容退出:");
            scanf("%d", &i);
            if (i != 1)
            {
                *flag == 0;
                return;
            }
            type0(date, sockfd, buf);
        }
        printf("%s\n", buf);
        Lgcode(date, sockfd, flag);
        break;
    case 1:
        type1(date, sockfd, buf);
        while (strcmp(buf, "用户名可用") != 0)
        {
            printf("%s\n", buf);
            type1(date, sockfd, buf);
        }
        printf("%s\n", buf);
        Rgcode(date, sockfd);
        break;
    default:
        break;
    }
}

void type1(PL date, int sockfd, char *buf) // 注册分支
{
    printf("请注意：系统只保留输入的前19位！\n");
    printf("请输入你的用户名：");
    scanf("%19s", date.date);
    while (getchar() != '\n')
        ;
    printf("你的输入:%s\n", date.date);
    date.type = 1;
    date.size = sizeof(date.date);
    send(sockfd, &date, sizeof(date), 0);
    recv(sockfd, buf, 24, 0);
}

void type0(PL date, int sockfd, char *buf) // 登录分支
{
    char uid[20] = {};
    printf("请注意：系统只保留输入的前19位！\n");
    printf("请输入你的用户名：");
    scanf("%19s", uid);
    while (getchar() != '\n')
        ;
    printf("你的输入:%s\n", uid);
    date.type = 0;
    date.size = sizeof(uid);
    strcat(date.date, uid);
    send(sockfd, &date, sizeof(date), 0);
    recv(sockfd, buf, 24, 0);
}

void Rgcode(PL date, int sockfd) // 密码注册
{
    char code[20] = {};
    while (1)
    {
        printf("最多可输入19位，超过部分不被录入。\n");
        printf("请输入用户的密码：");
        scanf("%19s", date.date);
        while (getchar() != '\n')
            ;
        printf("请再次输入用户的密码：");
        scanf("%19s", code);
        while (getchar() != '\n')
            ;
        if (strcmp(date.date, code) == 0)
        {
            printf("用户注册成功！\n");
            break;
        }
        else
        {
            printf("密码输入不一请重新尝试！\n");
        }
    }
    send(sockfd, &date, sizeof(date), 0);
}

void Lgcode(PL date, int sockfd, int *flag) // 登录密码
{
    int i = 0;
    int f = 0;
    char buf[25] = {};
    while (i < 3)
    {
        printf("最多可输入19位，超过部分不被录入\n");
        printf("请输入用户的密码：");
        scanf("%19s", date.date);
        while (getchar() != '\n')
            ;
        send(sockfd, &date, sizeof(date), 0);
        recv(sockfd, buf, sizeof(date), 0);
        if (strcmp(buf, "密码正确") == 0)
        {
            printf("%s登录成功\n", buf);
            break;
        }
        if (i == 2)
        {
            strcat(date.date, "/exit");
            send(sockfd, &date, sizeof(date), 0);
            *flag == 0;
            break;
        }
        printf("%s\n", buf);
        printf("你还有%d次输入机会\n", 2 - i);
        printf("是否需要继续输入用户名？\n");
        printf("输入“1”继续，输入其他内容退出:");
        scanf("%d", &f);
        if (f != 1)
        {
            strcat(date.date, "/exit");
            send(sockfd, &date, sizeof(date), 0);
            *flag == 0;
            return;
        }
        i++;
    }
}
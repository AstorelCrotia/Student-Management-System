#include "head.h"

void Validation(int sockfd, PL date, int *flag, UD *user) // 验证用户名功�?
{
    *flag = 0;
    FILE *fp = fopen("User.txt", "r");
    if (fp == NULL)
    {
        Login();
        printf("文件日志读取失败\n");
        Logout();
        return;
    }
    while (fscanf(fp, "用户名：%s  密码：%s\n", user->uid, user->code) != EOF)
    {
        if (strcmp(date.date, user->uid) == 0)
        {
            send(sockfd, "用户名存在", 16, 0);
            *flag = 1;
            break;
        }
    }
    if (*flag == 0)
    {
        send(sockfd, "用户名不存在", 19, 0);
    }
    fclose(fp);
}

void Validationcode(int sockfd, PL date, int *flag, UD user) // 验证密码功能
{
    FILE *fp = fopen("User.txt", "r");
    if (fp == NULL)
    {
        Login();
        printf("文件日志读取失败\n");
        Logout();
        return;
    }
    while (1)
    {
        recv(sockfd, &date, sizeof(date), 0);
        if (strcmp(user.code, date.date) == 0)
        {
            send(sockfd, "密码正确", 13, 0);
        }
        else if(strcmp("/exit", date.date) == 0)
        {
            break;
        }
        else
        {
            send(sockfd, "密码不正确", 16, 0);
        }
    }
    fclose(fp);
}
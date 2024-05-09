#include "head.h"

void Registeruser(int sockfd, PL date,int *flag) // 注册用户�?
{
    UD user = {0};
    *flag = 0;
    FILE *fp = fopen("User.txt", "r");
    if (fp == NULL)
    {
        Login();
        printf("文件日志读取失败");
        Logout();
        return;
    }
    while (fscanf(fp, "用户名：%s  密码：%s\n", user.uid, user.code) != EOF)
    {
        if (strcmp(date.date, user.uid) == 0)
        {
            send(sockfd,"用户名已存在",19,0);
            *flag = 1;
            break;
        }
    }
    if(*flag == 0)
    {
        send(sockfd,"用户名可用",16,0);
    }
    fclose(fp);
}

void Registerwrite(UD user) // 注册内容写入文件
{
    FILE *fp = fopen("User.txt", "a");
    if (fp == NULL)
    {
        Login();
        printf("文件日志读取失败\n");
        Logout();
        return;
    }
    fclose(fp);
}
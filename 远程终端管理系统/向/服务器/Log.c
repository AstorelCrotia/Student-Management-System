#include "head.h"

void Login() // 文件日志写入
{
    freopen("logread.txt", "w", stdout);
}

void Logout() // 文件日志读取
{
    freopen("/dev/tty", "w", stdout);
    char buf[128] = {};
    FILE *fp = fopen("logread.txt", "r");
    if (fp == NULL)
    {
        printf("文件日志读取失败\n");
        return;
    }
    fgets(buf, 127, fp);
    printf("%s\n", buf);
    freopen("log.txt", "a", stdout);
    printf("%s\n", buf);
    freopen("/dev/tty", "w", stdout);
    fclose(fp);
}

void Logdate() // 数据接口
{
    FILE *fp = fopen("log.txt", "a");
    if (fp == NULL)
    {
        printf("文件日志读取失败\n");
        return;
    }
    fclose(fp);
}
#include "head.h"

void Initialization() // 系统初始化，写入超管
{
    User admin = {0};
    User tureadmin = {0};
    int flag = 0;
    FILE *file_write = fopen("admin.txt", "a");
    if (file_write == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    FILE *file_read = fopen("admin.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    strcpy(admin.uid, "admin");
    while (fscanf(file_read, "用户名：%s  密码：%s  余额：%f\n", tureadmin.uid, tureadmin.code, &tureadmin.balance) != EOF)
    {
        if (strcmp(admin.uid, tureadmin.uid) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        fclose(file_write);
        return;
    }
    strcpy(admin.code, "123");
    fprintf(file_write, "用户名：%s  密码：%s  余额：%.2f\n", admin.uid, admin.code, admin.balance);
    fclose(file_write);
    return;
}
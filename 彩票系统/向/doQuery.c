#include "head.h"

void conditionQueryuser() // 条件查询用户
{
    char input[20] = "\0";
    User uid = {0};
    int flag = 0;
    printf("============================\n");
    printf("请输入你要查询的用户名：");
    scanf("%19s", input);
    FILE *file_read = fopen("users.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    while (fread(&uid, sizeof(User), 1, file_read) == 1)
    {
        if (strcmp(input, uid.uid) == 0)
        {
            printf("============================\n");
            printf("|  用户名：%s             |\n", uid.uid);
            printf("|  密码：%s              |\n", uid.code);
            printf("|  账户余额：%.2f           |\n", uid.balance);
            printf("============================\n");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("============================\n");
        printf("|  用户名不存在！          |\n");
        printf("============================\n");
    }
}

void conditionQuerybuy() // 条件查询购票历史
{
    char input[20] = "\0";
    User uid = {0};
    int flag = 0;
    printf("============================\n");
    printf("请输入你要查询的用户名：");
    scanf("%19s", input);
    FILE *file_read = fopen("users.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    while (fread(&uid, sizeof(User), 1, file_read) == 1)
    {
        if (strcmp(input, uid.uid) == 0)
        {
            printf("============================\n");
            printf("|  用户名：%s             |\n", uid.uid);
            printf("|  密码：%s              |\n", uid.code);
            printf("|  账户余额：%d           |\n", uid.balance);
            printf("============================\n");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("============================\n");
        printf("|  用户名不存在！          |\n");
        printf("============================\n");
    }
}

void conditionQuerywin() // 条件查询历史开奖
{
}

void allQueryuser() // 查询所有用户信息
{
    User uid = {0};
    int i = 1;
    FILE *file_read = fopen("users.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    printf("============================\n");
    while (fread(&uid, sizeof(User), 1, file_read) == 1)
    {
        printf("|  第%d位用户：  ", i);
        printf("用户名：%s  ", uid.uid);
        printf("密码：%s  ", uid.code);
        printf("账户余额：%.2f     |\n", uid.balance);
        i++;
    }
    printf("============================\n");
}

void allnQueryubuy() // 查询所有历史购票
{
}

void allQuerywin() // 查询所有历史开奖
{
}

void Querymoney() // 查询彩票中心营收
{
}
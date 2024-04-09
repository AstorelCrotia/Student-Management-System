#include "head.h"

void Registeruser() // 注册用户
{
    User user = {0};
    User tureuid = {0};
    char code1[20] = "\0";
    int flag = 0;
    FILE *file_write = fopen("users.txt", "a");
    if (file_write == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    FILE *file_uid = fopen("users.txt", "r");
    if (file_uid == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    FILE *file_admin = fopen("admin.txt", "r");
    if (file_admin == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    printf("=============================================\n");
    printf("最多可输入19位，超过部分不被录入。");
    printf("请输入用户名:");
    scanf("%19s", user.uid);
    while (getchar() != '\n');
    while (1)
    {
        flag = 0;
        while (fread(&tureuid, sizeof(User), 1, file_uid) == 1)
        {
            if (strcmp(user.uid, tureuid.uid) == 0)
            {
                printf("============================\n");
                printf("|  用户名已存在！          |\n");
                printf("============================\n");
                flag = 1;
                break;
            }
        }
        while (fread(&tureuid, sizeof(User), 1, file_admin) == 1)
        {
            if (strcmp(user.uid, tureuid.uid) == 0)
            {
                printf("============================\n");
                printf("|  用户名已存在！          |\n");
                printf("============================\n");
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            printf("=============================================\n");
            printf("你可以输入“1”重新尝试输入，或输入其他退出：");
            scanf("%d", &flag);
            if (flag == 1)
            {
                printf("=============================================\n");
                printf("请输入用户名:");
                scanf("%19s", user.uid);
                while (getchar() != '\n');
            }
            else
            {
                break;
            }
        }
        else
        {
            flag = 1;
            break;
        }
    }
    fclose(file_uid);
    fclose(file_admin);
    if (flag != 1)
    {
        fclose(file_write);
        return;
    }
    while (1)
    {
        printf("============================\n");
        printf("最多可输入19位，超过部分不被录入。");
        printf("请输入用户的密码：");
        scanf("%19s", user.code);
        while (getchar() != '\n');
        printf("============================\n");
        printf("请再次输入用户的密码：");
        scanf("%19s", code1);
        while (getchar() != '\n');
        if (strcmp(user.code, code1) == 0)
        {
            strcpy(user.code, code1);
            printf("============================\n");
            printf("|  %s用户注册成功！     |\n",user.uid);
            printf("============================\n");
            break;
        }
        else
        {
            printf("============================\n");
            printf("|  密码输入不一请重新尝试！ |\n");
            printf("============================\n");
        }
    }
    fwrite(&user, sizeof(User), 1, file_write);
    fclose(file_write);
    return;
}

void Registeradmin() // 注册管理员
{
    User user = {0};
    User tureuid = {0};
    char code1[20] = "\0";
    int flag = 0;
    FILE *file_write = fopen("admin.txt", "a");
    if (file_write == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    FILE *file_uid = fopen("users.txt", "r");
    if (file_uid == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    FILE *file_admin = fopen("admin.txt", "r");
    if (file_admin == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    printf("=============================================\n");
    printf("最多可输入19位，超过部分不被录入。");
    printf("请输入用户名:");
    scanf("%19s", user.uid);
    while (getchar() != '\n');
    while (1)
    {
        flag = 0;
        while (fread(&tureuid, sizeof(User), 1, file_uid) == 1)
        {
            if (strcmp(user.uid, tureuid.uid) == 0)
            {
                printf("============================\n");
                printf("|  用户名已存在！          |\n");
                printf("============================\n");
                flag = 1;
                break;
            }
        }
        while (fread(&tureuid, sizeof(User), 1, file_admin) == 1)
        {
            if (strcmp(user.uid, tureuid.uid) == 0)
            {
                printf("============================\n");
                printf("|  用户名已存在！          |\n");
                printf("============================\n");
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            printf("=============================================\n");
            printf("你可以输入“1”重新尝试输入，或输入其他退出：");
            scanf("%d", &flag);
            if (flag == 1)
            {
                printf("=============================================\n");
                printf("请输入用户名:");
                scanf("%19s", user.uid);
                while (getchar() != '\n');
            }
            else
            {
                break;
            }
        }
        else
        {
            flag = 1;
            break;
        }
    }
    fclose(file_uid);
    fclose(file_admin);
    if (flag != 1)
    {
        fclose(file_write);
        return;
    }
    while (1)
    {
        printf("============================\n");
        printf("最多可输入19位，超过部分不被录入。");
        printf("请输入用户的密码：");
        scanf("%19s", user.code);
        while (getchar() != '\n');
        printf("============================\n");
        printf("请再次输入用户的密码：");
        scanf("%19s", code1);
        while (getchar() != '\n');
        if (strcmp(user.code, code1) == 0)
        {
            strcpy(user.code, code1);
            printf("============================\n");
            printf("|  用户注册成功！          |\n");
            printf("============================\n");
            break;
        }
        else
        {
            printf("============================\n");
            printf("|  密码输入不一请重新尝试！ |\n");
            printf("============================\n");
        }
    }
    fwrite(&user, sizeof(User), 1, file_write);
    fclose(file_write);
    return;
}

#include "head.h"

void Registeruser() // 注册用户
{
    User user = {0};
    User tureuid = {0};
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
    printf("请输入用户名:");
    scanf("%19s", user.uid);
    while (1)
    {
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
    printf("=============================================\n");
    printf("请输入密码:");
    scanf("%19s", user.code);
    fwrite(&user, sizeof(User), 1, file_write);
    fclose(file_write);
    return;
}

void Registeradmin() // 注册管理员
{
    User user = {0};
    User tureuid = {0};
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
    printf("请输入用户名:");
    scanf("%19s", user.uid);
    while (1)
    {
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
    printf("=============================================\n");
    printf("请输入密码:");
    scanf("%19s", user.code);
    fwrite(&user, sizeof(User), 1, file_write);
    fclose(file_write);
    return;
}

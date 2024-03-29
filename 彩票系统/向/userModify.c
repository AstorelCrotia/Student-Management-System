#include "head.h"

void usercodeModify(char *id) // 密码修改
{
    User *head = NULL;
    User *temp = NULL;
    User *user = (User *)malloc(sizeof(User));
    if (user == NULL)
    {
        printf("============================\n");
        printf("|  内存分配失败！          |\n");
        printf("============================\n");
        return;
    }
    char code1[20] = "\0";
    char code2[20] = "\0";
    FILE *file_read = fopen("users.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    while (fread(user, sizeof(User), 1, file_read) == 1)
    {
        user->next = NULL;
        if (head == NULL)
        {
            head = user;
            temp = user;
        }
        else
        {
            temp->next = user;
            temp = user;
        }
        user = (User *)malloc(sizeof(User));
        if (user == NULL)
        {
            printf("============================\n");
            printf("|  内存分配失败！          |\n");
            printf("============================\n");
            return;
        }
    }
    fclose(file_read);
    free(user);
    temp = head;
    while (temp != NULL)
    {
        if (strcmp(id, temp->uid) == 0)
        {
            while (1)
            {
                printf("============================\n");
                printf("请输入用户的新密码：");
                scanf("%19s", code1);
                printf("============================\n");
                printf("请再次输入用户的新密码：");
                scanf("%19s", code2);
                if (strcmp(code1, code2) == 0)
                {
                    strcpy(temp->code, code1);
                    printf("============================\n");
                    printf("|  修改密码成功！          |\n");
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
            break;
        }
        temp = temp->next;
    }
    FILE *file_write = fopen("users.txt", "w");
    if (file_write == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    temp = head;
    while (temp != NULL)
    {
        fwrite(temp, sizeof(User), 1, file_write);
        temp = temp->next;
    }
    fclose(file_write);
    temp = head;
    while (temp != NULL)
    {
        User *toFree = temp;
        temp = temp->next;
        free(toFree);
    }
    head = NULL;
}

void usermoneyModify(char *id, int flag) // 余额修改
{
    int i = 0;
    User *head = NULL;
    User *temp = NULL;
    User *user = (User *)malloc(sizeof(User));
    if (user == NULL)
    {
        printf("============================\n");
        printf("|  内存分配失败！          |\n");
        printf("============================\n");
        return;
    }
    float money = 0;
    FILE *file_read = fopen("users.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    while (fread(user, sizeof(User), 1, file_read) == 1)
    {
        user->next = NULL;
        if (head == NULL)
        {
            head = user;
            temp = user;
        }
        else
        {
            temp->next = user;
            temp = user;
        }
        user = (User *)malloc(sizeof(User));
        if (user == NULL)
        {
            printf("============================\n");
            printf("|  内存分配失败！          |\n");
            printf("============================\n");
            return;
        }
    }
    fclose(file_read);
    free(user);
    temp = head;
    if (flag == 1)
    {
        while (temp != NULL)
        {
            if (strcmp(id, temp->uid) == 0)
            {
                while (1)
                {
                    printf("============================\n");
                    printf("请输入要取出的数额：");
                    scanf("%f", &money);
                    if (money <= temp->balance)
                    {
                        temp->balance -= money;
                        printf("============================\n");
                        printf("|  提取余额成功！          |\n");
                        printf("============================\n");
                        i = 1;
                        break;
                    }
                    else
                    {
                        printf("============================\n");
                        printf("|  提取的余额不足！        |\n");
                        printf("============================\n");
                        i = 0;
                        break;
                    }
                }
                break;
            }
            temp = temp->next;
        }
        if (i == 0)
        {
            temp = head;
            while (temp != NULL)
            {
                User *toFree = temp;
                temp = temp->next;
                free(toFree);
            }
            head = NULL;
            return;
        }
        FILE *file_write = fopen("users.txt", "w");
        if (file_write == NULL)
        {
            printf("============================\n");
            printf("|  连接服务器失败！        |\n");
            printf("============================\n");
            return;
        }
        temp = head;
        while (temp != NULL)
        {
            fwrite(temp, sizeof(User), 1, file_write);
            temp = temp->next;
        }
        fclose(file_write);
        temp = head;
        while (temp != NULL)
        {
            User *toFree = temp;
            temp = temp->next;
            free(toFree);
        }
        head = NULL;
    }
    else if (flag == 2)
    {
        while (temp != NULL)
        {
            if (strcmp(id, temp->uid) == 0)
            {
                while (1)
                {
                    printf("============================\n");
                    printf("请输入要充值的数额：");
                    scanf("%f", &money);
                    temp->balance += money;
                    printf("============================\n");
                    printf("|  充值余额成功！          |\n");
                    printf("============================\n");
                    break;
                }
                break;
            }
            temp = temp->next;
        }
        FILE *file_write = fopen("users.txt", "w");
        if (file_write == NULL)
        {
            printf("============================\n");
            printf("|  连接服务器失败！        |\n");
            printf("============================\n");
            return;
        }
        temp = head;
        while (temp != NULL)
        {
            fwrite(temp, sizeof(User), 1, file_write);
            temp = temp->next;
        }
        fclose(file_write);
        temp = head;
        while (temp != NULL)
        {
            User *toFree = temp;
            temp = temp->next;
            free(toFree);
        }
        head = NULL;
    }
}

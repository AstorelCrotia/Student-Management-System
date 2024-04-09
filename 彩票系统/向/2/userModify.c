#include "head.h"

void usercodeModify(char *id) // 密码修改
{
    User *head = NULL;
    User *temp = (User *)malloc(sizeof(User));
    if (temp == NULL)
    {
        printf("============================\n");
        printf("|  内存分配失败！          |\n");
        printf("============================\n");
        return;
    }
    User user = {0};
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
    while (fscanf(file_read, "用户名：%s  密码：%s  余额：%f\n", user.uid, user.code, &user.balance) != EOF)
    {
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = (User *)malloc(sizeof(User));
            temp = temp->next;
            if (temp == NULL)
            {
                printf("============================\n");
                printf("|  内存分配失败！          |\n");
                printf("============================\n");
                break;
            }
        }
        strcpy(temp->uid, user.uid);
        strcpy(temp->code, user.code);
        temp->balance = user.balance;
        temp->next = NULL;
    }
    fclose(file_read);
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
                while (getchar() != '\n')
                    ;
                printf("============================\n");
                printf("请再次输入用户的新密码：");
                scanf("%19s", code2);
                while (getchar() != '\n')
                    ;
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
        fprintf(file_write, "用户名：%s  密码：%s  余额：%.2f\n", temp->uid, temp->code, temp->balance);
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
    User *temp = (User *)malloc(sizeof(User));
    if (temp == NULL)
    {
        printf("============================\n");
        printf("|  内存分配失败！          |\n");
        printf("============================\n");
        return;
    }
    User user = {0};
    float money = 0;
    FILE *file_read = fopen("users.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "用户名：%s  密码：%s  余额：%f\n", user.uid, user.code, &user.balance) != EOF)
    {
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = (User *)malloc(sizeof(User));
            temp = temp->next;
            if (temp == NULL)
            {
                printf("============================\n");
                printf("|  内存分配失败！          |\n");
                printf("============================\n");
                break;
            }
        }
        strcpy(temp->uid, user.uid);
        strcpy(temp->code, user.code);
        temp->balance = user.balance;
        temp->next = NULL;
    }
    fclose(file_read);
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
            fprintf(file_write, "用户名：%s  密码：%s  余额：%.2f\n", temp->uid, temp->code, temp->balance);
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
            fprintf(file_write, "用户名：%s  密码：%s  余额：%.2f\n", temp->uid, temp->code, temp->balance);
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

void buyModify(char *id, float money, int *sc) // 购买时余额修改
{
    User *head = NULL;
    User *temp = (User *)malloc(sizeof(User));
    if (temp == NULL)
    {
        printf("============================\n");
        printf("|  内存分配失败！          |\n");
        printf("============================\n");
        return;
    }
    User user = {0};
    FILE *file_read = fopen("users.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "用户名：%s  密码：%s  余额：%f\n", user.uid, user.code, &user.balance) != EOF)
    {
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = (User *)malloc(sizeof(User));
            temp = temp->next;
            if (temp == NULL)
            {
                printf("============================\n");
                printf("|  内存分配失败！          |\n");
                printf("============================\n");
                break;
            }
        }
        strcpy(temp->uid, user.uid);
        strcpy(temp->code, user.code);
        temp->balance = user.balance;
        temp->next = NULL;
    }
    fclose(file_read);
    temp = head;
    while (temp != NULL)
    {
        if (strcmp(id, temp->uid) == 0)
        {
            if (money <= temp->balance)
            {
                temp->balance -= money;
            }
            else
            {
                printf("============================\n");
                printf("|  账户的余额不足！        |\n");
                printf("============================\n");
                temp = head;
                while (temp != NULL)
                {
                    User *toFree = temp;
                    temp = temp->next;
                    free(toFree);
                }
                head = NULL;
                *sc = 0;
                return;
            }
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
        fprintf(file_write, "用户名：%s  密码：%s  余额：%.2f\n", temp->uid, temp->code, temp->balance);
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
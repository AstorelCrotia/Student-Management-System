#include "head.h"

void adminModify(int *sc) // 修改界面
{
    *sc = 0;
    while (*sc != 3)
    {
        *sc = 0;
        printf("====================================\n");
        printf("|  欢迎使用修改功能！            |\n");
        printf("|                                |\n");
        printf("|  请选择你需要的功能！          |\n");
        printf("|                                |\n");
        printf("|  修改用户密码输入“1”           |\n");
        printf("|                                |\n");
        printf("|  修改用户余额输入“2”           |\n");
        printf("|                                |\n");
        printf("|  退出系统输入其他              |\n");
        printf("====================================\n");
        printf("你的输入：");
        scanf(" %d", sc);
        switch (*sc)
        {
        case 1:
            admincodeModify();
            break;
        case 2:
            adminmoneyModify();
            break;
        default:
            *sc = 3;
            break;
        }
    }
}

void admincodeModify() // 密码修改
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
    char input[20] = "\0";
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
    printf("============================\n");
    printf("请输入你要修改的用户名：");
    scanf("%19s", input);
    while (getchar() != '\n')
        ;
    temp = head;
    while (temp != NULL)
    {
        if (strcmp(input, temp->uid) == 0)
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
            i = 1;
            break;
        }
        temp = temp->next;
        i = 0;
    }
    if (i == 0)
    {
        printf("================================\n");
        printf("|  没有找到用户名为%s的用户!    |\n", input);
        printf("================================\n");
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

void adminmoneyModify() // 余额修改
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
    char input[20] = "\0";
    float m1 = 0;
    float m2 = 0;
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
    printf("============================\n");
    printf("请输入你要修改的用户名：");
    scanf("%19s", input);
    while (getchar() != '\n')
        ;
    temp = head;
    while (temp != NULL)
    {
        if (strcmp(input, temp->uid) == 0)
        {
            while (1)
            {
                printf("============================\n");
                printf("请输入用户的新余额：");
                scanf("%f", &m1);
                printf("============================\n");
                printf("请再次输入用户的新余额：");
                scanf("%f", &m2);
                if (m1 == m2)
                {
                    temp->balance = m1;
                    printf("============================\n");
                    printf("|  修改余额成功！          |\n");
                    printf("============================\n");
                    break;
                }
                else
                {
                    printf("============================\n");
                    printf("|  余额输入不一请重新尝试！ |\n");
                    printf("============================\n");
                }
            }
            i = 1;
            break;
        }
        temp = temp->next;
        i = 0;
    }
    if (i == 0)
    {
        printf("================================\n");
        printf("|  没有找到用户名为%s的用户!    |\n", input);
        printf("================================\n");
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
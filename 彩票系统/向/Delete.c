#include "head.h"

void Delete(int *sc) // 删除界面
{
    *sc = 0;
    while (*sc != 2)
    {
        *sc = 0;
        printf("====================================\n");
        printf("|  欢迎使用删除功能！            |\n");
        printf("|                                |\n");
        printf("|  请选择你需要的功能！          |\n");
        printf("|                                |\n");
        printf("|  删除指定用户输入“1”           |\n");
        printf("|                                |\n");
        printf("|  退出系统输入其他              |\n");
        printf("====================================\n");
        printf("你的输入：");
        scanf(" %d", sc);
        switch (*sc)
        {
        case 1:
            Deleteuser();
            break;
        default:
            *sc = 2;
            break;
        }
    }
}

void Deleteuser() // 删除功能
{
    int i = 0;
    User *head = NULL;
    User *temp = NULL;
    User *delete = NULL;
    User *user = (User *)malloc(sizeof(User));
    if (user == NULL)
    {
        printf("============================\n");
        printf("|  内存分配失败！          |\n");
        printf("============================\n");
        return;
    }
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
            break;
        }
    }
    fclose(file_read);
    free(user);
    printf("============================\n");
    printf("请输入你要删除的用户名：");
    scanf("%19s", input);
    temp = head;
    if (strcmp(input, temp->uid) == 0)
    {
        delete = head;
        head = temp->next;
        i = 1;
    }
    else
    {
        while (temp != NULL)
        {
            if (strcmp(input, temp->next->uid) == 0)
            {
                delete = temp->next;
                temp->next = delete->next;
                i = 1;
                break;
            }
            temp = temp->next;
        }
    }
    if (i == 0)
    {
        printf("================================\n");
        printf("|  没有找到用户名为%s的用户!    |\n", input);
        printf("================================\n");
        temp = head;
        free(delete);
        while (temp != NULL)
        {
            User *toFree = temp;
            temp = temp->next;
            free(toFree);
        }
        free(head);
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
    FILE *file_wdelete = fopen("delete.txt", "a");
    if (file_wdelete == NULL)
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
    fwrite(delete, sizeof(User), 1, file_wdelete);
    fclose(file_write);
    fclose(file_wdelete);
    temp = head;
    free(delete);
    while (temp != NULL)
    {
        User *toFree = temp;
        temp = temp->next;
        free(toFree);
    }
    free(head);
    printf("============================\n");
    printf("|  %s用户已经删除！      |\n",input);
    printf("============================\n");
}
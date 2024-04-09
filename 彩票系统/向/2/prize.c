#include "head.h"

void Prize(Lottery *lottery, int *ran, float n) // 兑奖
{
    int num[6] = {0};
    float flag = 0;
    sscanf(lottery->usernumber, "%d-%d-%d-%d-%d:%d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
    for (int i = 0; i < 6; i++)
    {
        if (num[i] == *(ran+i))
        {
            lottery->win = 1;
            flag++;
        }
    }
    if (flag == 0)
    {
        return;
    }
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
            if (temp == NULL)
            {
                printf("============================\n");
                printf("|  内存分配失败！          |\n");
                printf("============================\n");
                break;
            }
            temp = temp->next;
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
        if (strcmp(lottery->uid, temp->uid) == 0)
        {
            temp->balance += (flag*n);
            revenue(-flag*n,lottery);
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
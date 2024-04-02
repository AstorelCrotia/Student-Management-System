#include "head.h"

void Prize(Lottery *lottery, int *ran, float n) // 兑奖
{
    int num[6] = {0};
    float flag = 0;
    sscanf(lottery->usernumber, "%d %d %d %d %d : %d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
    for (int i = 0; i < 6; i++)
    {
        if (num[i] == *(ran+i))
        {
            flag++;
        }
    }
    if (flag == 0)
    {
        return;
    }
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
        if (strcmp(lottery->uid, temp->uid) == 0)
        {
            temp->balance += (flag*n);
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
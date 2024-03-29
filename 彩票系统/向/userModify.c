#include "head.h"

void usercodeModify(char *id) // �����޸�
{
    User *head = NULL;
    User *temp = NULL;
    User *user = (User *)malloc(sizeof(User));
    if (user == NULL)
    {
        printf("============================\n");
        printf("|  �ڴ����ʧ�ܣ�          |\n");
        printf("============================\n");
        return;
    }
    char code1[20] = "\0";
    char code2[20] = "\0";
    FILE *file_read = fopen("users.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
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
            printf("|  �ڴ����ʧ�ܣ�          |\n");
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
                printf("�������û��������룺");
                scanf("%19s", code1);
                printf("============================\n");
                printf("���ٴ������û��������룺");
                scanf("%19s", code2);
                if (strcmp(code1, code2) == 0)
                {
                    strcpy(temp->code, code1);
                    printf("============================\n");
                    printf("|  �޸�����ɹ���          |\n");
                    printf("============================\n");
                    break;
                }
                else
                {
                    printf("============================\n");
                    printf("|  �������벻һ�����³��ԣ� |\n");
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
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
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

void usermoneyModify(char *id, int flag) // ����޸�
{
    int i = 0;
    User *head = NULL;
    User *temp = NULL;
    User *user = (User *)malloc(sizeof(User));
    if (user == NULL)
    {
        printf("============================\n");
        printf("|  �ڴ����ʧ�ܣ�          |\n");
        printf("============================\n");
        return;
    }
    float money = 0;
    FILE *file_read = fopen("users.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
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
            printf("|  �ڴ����ʧ�ܣ�          |\n");
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
                    printf("������Ҫȡ�������");
                    scanf("%f", &money);
                    if (money <= temp->balance)
                    {
                        temp->balance -= money;
                        printf("============================\n");
                        printf("|  ��ȡ���ɹ���          |\n");
                        printf("============================\n");
                        i = 1;
                        break;
                    }
                    else
                    {
                        printf("============================\n");
                        printf("|  ��ȡ�����㣡        |\n");
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
            printf("|  ���ӷ�����ʧ�ܣ�        |\n");
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
                    printf("������Ҫ��ֵ�����");
                    scanf("%f", &money);
                    temp->balance += money;
                    printf("============================\n");
                    printf("|  ��ֵ���ɹ���          |\n");
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
            printf("|  ���ӷ�����ʧ�ܣ�        |\n");
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

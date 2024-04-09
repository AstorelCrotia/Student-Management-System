#include "head.h"

void usercodeModify(char *id) // �����޸�
{
    User *head = NULL;
    User *temp = (User *)malloc(sizeof(User));
    if (temp == NULL)
    {
        printf("============================\n");
        printf("|  �ڴ����ʧ�ܣ�          |\n");
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
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "�û�����%s  ���룺%s  ��%f\n", user.uid, user.code, &user.balance) != EOF)
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
                printf("|  �ڴ����ʧ�ܣ�          |\n");
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
                printf("�������û��������룺");
                scanf("%19s", code1);
                while (getchar() != '\n')
                    ;
                printf("============================\n");
                printf("���ٴ������û��������룺");
                scanf("%19s", code2);
                while (getchar() != '\n')
                    ;
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
        fprintf(file_write, "�û�����%s  ���룺%s  ��%.2f\n", temp->uid, temp->code, temp->balance);
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
    User *temp = (User *)malloc(sizeof(User));
    if (temp == NULL)
    {
        printf("============================\n");
        printf("|  �ڴ����ʧ�ܣ�          |\n");
        printf("============================\n");
        return;
    }
    User user = {0};
    float money = 0;
    FILE *file_read = fopen("users.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "�û�����%s  ���룺%s  ��%f\n", user.uid, user.code, &user.balance) != EOF)
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
                printf("|  �ڴ����ʧ�ܣ�          |\n");
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
            fprintf(file_write, "�û�����%s  ���룺%s  ��%.2f\n", temp->uid, temp->code, temp->balance);
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
            fprintf(file_write, "�û�����%s  ���룺%s  ��%.2f\n", temp->uid, temp->code, temp->balance);
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

void buyModify(char *id, float money, int *sc) // ����ʱ����޸�
{
    User *head = NULL;
    User *temp = (User *)malloc(sizeof(User));
    if (temp == NULL)
    {
        printf("============================\n");
        printf("|  �ڴ����ʧ�ܣ�          |\n");
        printf("============================\n");
        return;
    }
    User user = {0};
    FILE *file_read = fopen("users.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "�û�����%s  ���룺%s  ��%f\n", user.uid, user.code, &user.balance) != EOF)
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
                printf("|  �ڴ����ʧ�ܣ�          |\n");
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
                printf("|  �˻������㣡        |\n");
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
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    temp = head;
    while (temp != NULL)
    {
        fprintf(file_write, "�û�����%s  ���룺%s  ��%.2f\n", temp->uid, temp->code, temp->balance);
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
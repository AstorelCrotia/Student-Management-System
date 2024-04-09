#include "head.h"

void Delete(int *sc) // ɾ������
{
    *sc = 0;
    while (*sc != 2)
    {
        *sc = 0;
        printf("====================================\n");
        printf("|  ��ӭʹ��ɾ�����ܣ�            |\n");
        printf("|                                |\n");
        printf("|  ��ѡ������Ҫ�Ĺ��ܣ�          |\n");
        printf("|                                |\n");
        printf("|  ɾ��ָ���û����롰1��           |\n");
        printf("|                                |\n");
        printf("|  �˳�ϵͳ��������              |\n");
        printf("====================================\n");
        printf("������룺");
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

void Deleteuser() // ɾ������
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
    User *delete = NULL;
    char input[20] = "\0";
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
    printf("============================\n");
    printf("��������Ҫɾ�����û�����");
    scanf("%19s", input);
    while (getchar() != '\n')
        ;
    temp = head;
    if (strcmp(input, temp->uid) == 0)
    {
        delete = head;
        head = temp->next;
        i = 1;
    }
    else
    {
        while (temp->next != NULL)
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
        printf("|  û���ҵ��û���Ϊ%s���û�!    |\n", input);
        printf("================================\n");
        temp = head;
        while (temp != NULL)
        {
            User *toFree = temp;
            temp = temp->next;
            free(toFree);
        }
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
    FILE *file_wdelete = fopen("delete.txt", "a");
    if (file_wdelete == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    fprintf(file_wdelete, "�û�����%s  ���룺%s  ��%.2f\n", delete->uid, delete->code, delete->balance);
    fclose(file_wdelete);
    temp = head;
    while (temp != NULL)
    {
        User *toFree = temp;
        temp = temp->next;
        free(toFree);
    }
    printf("============================\n");
    printf("|  %s�û��Ѿ�ɾ����      |\n", input);
    printf("============================\n");
}

void uDeleteuser(char *id) // ɾ������
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
    User *delete = NULL;
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
    if (strcmp(id, temp->uid) == 0)
    {
        delete = head;
        head = temp->next;
    }
    else
    {
        while (temp->next != NULL)
        {
            if (strcmp(id, temp->next->uid) == 0)
            {
                delete = temp->next;
                temp->next = delete->next;
                break;
            }
            temp = temp->next;
        }
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
    FILE *file_wdelete = fopen("delete.txt", "a");
    if (file_wdelete == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    fprintf(file_wdelete, "�û�����%s  ���룺%s  ��%.2f\n", delete->uid, delete->code, delete->balance);
    fclose(file_wdelete);
    temp = head;
    while (temp != NULL)
    {
        User *toFree = temp;
        temp = temp->next;
        free(toFree);
    }
    printf("============================\n");
    printf("|  %s�û��Ѿ�ɾ����      |\n", id);
    printf("============================\n");
}
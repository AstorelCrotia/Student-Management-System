#include "head.h"

void adminModify(int *sc) // �޸Ľ���
{
    *sc = 0;
    while (*sc != 3)
    {
        *sc = 0;
        printf("====================================\n");
        printf("|  ��ӭʹ���޸Ĺ��ܣ�            |\n");
        printf("|                                |\n");
        printf("|  ��ѡ������Ҫ�Ĺ��ܣ�          |\n");
        printf("|                                |\n");
        printf("|  �޸��û��������롰1��           |\n");
        printf("|                                |\n");
        printf("|  �޸��û�������롰2��           |\n");
        printf("|                                |\n");
        printf("|  �˳�ϵͳ��������              |\n");
        printf("====================================\n");
        printf("������룺");
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

void admincodeModify() // �����޸�
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
    char input[20] = "\0";
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
    printf("============================\n");
    printf("��������Ҫ�޸ĵ��û�����");
    scanf("%19s", input);
    while (getchar() != '\n');
    temp = head;
    while (temp != NULL)
    {
        if (strcmp(input, temp->uid) == 0)
        {
            while (1)
            {
                printf("============================\n");
                printf("�������û��������룺");
                scanf("%19s", code1);
                while (getchar() != '\n');
                printf("============================\n");
                printf("���ٴ������û��������룺");
                scanf("%19s", code2);
                while (getchar() != '\n');
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
            i = 1;
            break;
        }
        temp = temp->next;
        i = 0;
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

void adminmoneyModify() // ����޸�
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
    char input[20] = "\0";
    float m1 = 0;
    float m2 = 0;
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
    printf("============================\n");
    printf("��������Ҫ�޸ĵ��û�����");
    scanf("%19s", input);
    while (getchar() != '\n');
    temp = head;
    while (temp != NULL)
    {
        if (strcmp(input, temp->uid) == 0)
        {
            while (1)
            {
                printf("============================\n");
                printf("�������û�������");
                scanf("%f", &m1);
                printf("============================\n");
                printf("���ٴ������û�������");
                scanf("%f", &m2);
                if (m1==m2)
                {
                    temp->balance = m1;
                    printf("============================\n");
                    printf("|  �޸����ɹ���          |\n");
                    printf("============================\n");
                    break;
                }
                else
                {
                    printf("============================\n");
                    printf("|  ������벻һ�����³��ԣ� |\n");
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
        printf("|  û���ҵ��û���Ϊ%s���û�!    |\n", input);
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
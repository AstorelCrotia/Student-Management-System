#include "head.h"

void Registeruser() // ע���û�
{
    User user = {0};
    User tureuid = {0};
    char code1[20] = "\0";
    int flag = 0;
    FILE *file_write = fopen("users.txt", "a");
    if (file_write == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    FILE *file_uid = fopen("users.txt", "r");
    if (file_uid == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    FILE *file_admin = fopen("admin.txt", "r");
    if (file_admin == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    printf("=============================================\n");
    printf("��������19λ���������ֲ���¼�롣");
    printf("�������û���:");
    scanf("%19s", user.uid);
    while (getchar() != '\n')
        ;
    while (1)
    {
        flag = 0;
        while (fscanf(file_uid, "�û�����%s  ���룺%s  ��%f\n", tureuid.uid, tureuid.code, &tureuid.balance) != EOF)
        {
            if (strcmp(user.uid, tureuid.uid) == 0)
            {
                printf("============================\n");
                printf("|  �û����Ѵ��ڣ�          |\n");
                printf("============================\n");
                flag = 1;
                break;
            }
        }
        rewind(file_uid);
        while (fscanf(file_admin, "�û�����%s  ���룺%s  ��%f\n", tureuid.uid, tureuid.code, &tureuid.balance) != EOF)
        {
            if (strcmp(user.uid, tureuid.uid) == 0)
            {
                printf("============================\n");
                printf("|  �û����Ѵ��ڣ�          |\n");
                printf("============================\n");
                flag = 1;
                break;
            }
        }
        rewind(file_admin);
        if (flag == 1)
        {
            printf("=============================================\n");
            printf("��������롰1�����³������룬�����������˳���");
            scanf("%d", &flag);
            if (flag == 1)
            {
                printf("=============================================\n");
                printf("�������û���:");
                scanf("%19s", user.uid);
                while (getchar() != '\n')
                    ;
            }
            else
            {
                break;
            }
        }
        else
        {
            flag = 1;
            break;
        }
    }
    fclose(file_uid);
    fclose(file_admin);
    if (flag != 1)
    {
        fclose(file_write);
        return;
    }
    while (1)
    {
        printf("============================\n");
        printf("��������19λ���������ֲ���¼�롣");
        printf("�������û������룺");
        scanf("%19s", user.code);
        while (getchar() != '\n')
            ;
        printf("============================\n");
        printf("���ٴ������û������룺");
        scanf("%19s", code1);
        while (getchar() != '\n')
            ;
        if (strcmp(user.code, code1) == 0)
        {
            strcpy(user.code, code1);
            printf("============================\n");
            printf("|  %s�û�ע��ɹ���     |\n", user.uid);
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
    fprintf(file_write, "�û�����%s  ���룺%s  ��%.2f\n", user.uid, user.code, user.balance);
    fclose(file_write);
    return;
}

void Registeradmin() // ע�����Ա
{
    User user = {0};
    User tureuid = {0};
    char code1[20] = "\0";
    int flag = 0;
    FILE *file_write = fopen("admin.txt", "a");
    if (file_write == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    FILE *file_uid = fopen("users.txt", "r");
    if (file_uid == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    FILE *file_admin = fopen("admin.txt", "r");
    if (file_admin == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    printf("=============================================\n");
    printf("��������19λ���������ֲ���¼�롣");
    printf("�������û���:");
    scanf("%19s", user.uid);
    while (getchar() != '\n')
        ;
    while (1)
    {
        flag = 0;
        while (fscanf(file_uid, "�û�����%s  ���룺%s  ��%f\n", tureuid.uid, tureuid.code, &tureuid.balance) != EOF)
        {
            if (strcmp(user.uid, tureuid.uid) == 0)
            {
                printf("============================\n");
                printf("|  �û����Ѵ��ڣ�          |\n");
                printf("============================\n");
                flag = 1;
                break;
            }
        }
        while (fscanf(file_admin, "�û�����%s  ���룺%s  ��%f\n", tureuid.uid, tureuid.code, &tureuid.balance) != EOF)
        {
            if (strcmp(user.uid, tureuid.uid) == 0)
            {
                printf("============================\n");
                printf("|  �û����Ѵ��ڣ�          |\n");
                printf("============================\n");
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            printf("=============================================\n");
            printf("��������롰1�����³������룬�����������˳���");
            scanf("%d", &flag);
            if (flag == 1)
            {
                printf("=============================================\n");
                printf("�������û���:");
                scanf("%19s", user.uid);
                while (getchar() != '\n')
                    ;
            }
            else
            {
                break;
            }
        }
        else
        {
            flag = 1;
            break;
        }
    }
    fclose(file_uid);
    fclose(file_admin);
    if (flag != 1)
    {
        fclose(file_write);
        return;
    }
    while (1)
    {
        printf("============================\n");
        printf("��������19λ���������ֲ���¼�롣");
        printf("�������û������룺");
        scanf("%19s", user.code);
        while (getchar() != '\n')
            ;
        printf("============================\n");
        printf("���ٴ������û������룺");
        scanf("%19s", code1);
        while (getchar() != '\n')
            ;
        if (strcmp(user.code, code1) == 0)
        {
            strcpy(user.code, code1);
            printf("============================\n");
            printf("|  �û�ע��ɹ���          |\n");
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
    fprintf(file_write, "�û�����%s  ���룺%s  ��%.2f\n", user.uid, user.code, user.balance);
    fclose(file_write);
    return;
}

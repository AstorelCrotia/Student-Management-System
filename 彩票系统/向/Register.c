#include "head.h"

void Registeruser() // ע���û�
{
    User user = {0};
    User tureuid = {0};
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
    printf("�������û���:");
    scanf("%19s", user.uid);
    while (1)
    {
        while (fread(&tureuid, sizeof(User), 1, file_uid) == 1)
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
        while (fread(&tureuid, sizeof(User), 1, file_admin) == 1)
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
    printf("=============================================\n");
    printf("����������:");
    scanf("%19s", user.code);
    fwrite(&user, sizeof(User), 1, file_write);
    fclose(file_write);
    return;
}

void Registeradmin() // ע�����Ա
{
    User user = {0};
    User tureuid = {0};
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
    printf("�������û���:");
    scanf("%19s", user.uid);
    while (1)
    {
        while (fread(&tureuid, sizeof(User), 1, file_uid) == 1)
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
        while (fread(&tureuid, sizeof(User), 1, file_admin) == 1)
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
    printf("=============================================\n");
    printf("����������:");
    scanf("%19s", user.code);
    fwrite(&user, sizeof(User), 1, file_write);
    fclose(file_write);
    return;
}

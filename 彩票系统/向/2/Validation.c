#include "head.h"

void Validation(char *id, int *group) // ��֤�û�������
{
    printf("============================\n");
    printf("�������û���:");
    scanf("%19s", id);
    while (getchar() != '\n')
        ;
    User tureuid = {0};
    User tureadmin = {0};
    int i = 0;
    int flag = 0;
    char code[20] = "\0";
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
    while (i != 3)
    {
        flag = 0;
        while (fscanf(file_uid, "�û�����%s  ���룺%s  ��%f\n", tureuid.uid, tureuid.code, &tureuid.balance) != EOF)
        {
            if (strcmp(id, tureuid.uid) == 0)
            {
                printf("============================\n");
                printf("|  �û������ڣ�            |\n");
                printf("============================\n");
                *group = 1;
                flag = 2;
                break;
            }
        }
        rewind(file_uid);
        while (fscanf(file_admin, "�û�����%s  ���룺%s  ��%f\n", tureadmin.uid, tureadmin.code, &tureadmin.balance) != EOF)
        {
            if (strcmp(id, tureadmin.uid) == 0)
            {
                printf("============================\n");
                printf("|  �û������ڣ�            |\n");
                printf("============================\n");
                *group = 2;
                flag = 2;
                break;
            }
        }
        rewind(file_admin);
        if (flag == 2)
        {
            break;
        }
        else
        {
            printf("=============================================\n");
            printf("|  �û��������ڣ�                         |\n");
            printf("|  ���ǵ�%d����������㻹��%d�λ���       |\n", i + 1, 2 - i);
            printf("=============================================\n");
            printf("��������롰1���������룬�����������˳���");
            scanf("%d", &flag);
            while (getchar() != '\n')
                ;
            if (flag == 1)
            {
                printf("=============================================\n");
                printf("�������û���:");
                scanf("%19s", id);
                while (getchar() != '\n')
                    ;
                i++;
            }
            else
            {
                break;
            }
        }
    }
    if (*group == 1)
    {
        i = 0;
        flag = 0;
        printf("=============================================\n");
        printf("���������룺");
        scanf("%19s", code);
        while (getchar() != '\n')
            ;
        while (i != 3)
        {
            if (strcmp(code, tureuid.code) == 0)
            {
                printf("=============================================\n");
                printf("��ӭ��¼��\n");
                flag = 2;
                break;
            }
            if (flag == 2)
            {
                break;
            }
            else
            {
                if (i == 3)
                {
                    *group = 0;
                    printf("============================\n");
                    printf("|  �˳�����              |\n");
                    printf("============================\n");
                    break;
                }
                printf("=============================================\n");
                printf("|  ���벻��ȷ��                            |\n");
                printf("|  ���ǵ�%d����������㻹��%d�λ���       |\n", i + 1, 2 - i);
                printf("=============================================\n");
                printf("��������롰1���������룬�����������˳���");
                scanf("%d", &flag);
                while (getchar() != '\n')
                    ;
                if (flag == 1)
                {
                    printf("=============================================\n");
                    printf("����������:");
                    scanf("%19s", code);
                    while (getchar() != '\n')
                        ;
                    i++;
                }
                else
                {
                    *group = 0;
                    break;
                }
            }
        }
        if (i == 3)
        {
            *group = 0;
        }
    }
    else if (*group == 2)
    {
        i = 0;
        flag = 0;
        printf("=============================================\n");
        printf("���������룺");
        scanf("%19s", code);
        while (getchar() != '\n')
            ;
        while (i != 3)
        {
            if (strcmp(code, tureadmin.code) == 0)
            {
                printf("=============================================\n");
                printf("��ӭ��¼��\n");
                flag = 2;
                break;
            }
            rewind(file_admin);
            if (flag == 2)
            {
                break;
            }
            else
            {
                if (i == 3)
                {
                    *group = 0;
                    printf("============================\n");
                    printf("|  �˳�����              |\n");
                    printf("============================\n");
                    break;
                }
                printf("=============================================\n");
                printf("|  ���벻��ȷ��                            |\n");
                printf("|  ���ǵ�%d����������㻹��%d�λ���       |\n", i + 1, 2 - i);
                printf("=============================================\n");
                printf("��������롰1���������룬�����������˳���");
                scanf("%d", &flag);
                while (getchar() != '\n')
                    ;
                if (flag == 1)
                {
                    printf("=============================================\n");
                    printf("����������:");
                    scanf("%19s", code);
                    while (getchar() != '\n')
                        ;
                    i++;
                }
                else
                {
                    *group = 0;
                    break;
                }
            }
        }
        if (i == 3)
        {
            *group = 0;
        }
    }
    fclose(file_uid);
    fclose(file_admin);
}
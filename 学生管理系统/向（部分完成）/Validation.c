#include "head.h"

void Validation(char *username, int *usergroup, int *sc) // ��֤�û�������
{
    Student turestudent = {0};
    Administrator tureadmin = {0};
    int i = 1;
    int flag = 0;
    char code[20] = "\0";
    FILE *file_student = fopen("Students.txt", "r");
    if (file_student == NULL)
    {
        printf("���ӷ�����ʧ�ܣ�\n");
        *sc = 1;
        return;
    }
    FILE *file_admin = fopen("Admin.txt", "r");
    if (file_admin == NULL)
    {
        printf("���ӷ�����ʧ�ܣ�\n");
        *sc = 1;
        return;
    }
    while (i != 3)
    {
        flag = 0;
        while (fread(&turestudent, sizeof(Student), 1, file_student) == 1)
        {
            if (strcmp(username, turestudent.username) == 0)
            {
                printf("�û������ڣ�\n");
                *usergroup = 2;
                flag = 2;
                break;
            }
        }
        rewind(file_student);
        while (fread(&tureadmin, sizeof(Administrator), 1, file_admin) == 1)
        {
            if (strcmp(username, tureadmin.username) == 0)
            {
                printf("�û������ڣ�\n");
                *usergroup = 1;
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
            printf("�û��������ڣ�\n");
            printf("���ǵ�%d����������㻹��%d�λ���\n", i, 3 - i);
            printf("��������롰1���������룬���������˳���");
            scanf("%d", &flag);
            if (flag == 1)
            {
                printf("�������û���:");
                scanf("%19s", username);
                i++;
            }
            else
            {
                break;
            }
        }
        if (i == 3)
        {
            printf("�������Σ������˳�!\n");
        }
    }
    if (*usergroup == 2)
    {
        i = 1;
        flag = 0;
        printf("���������룺");
        scanf("%19s", code);
        while (i != 3)
        {
            while (fread(&turestudent, sizeof(Student), 1, file_student) == 1)
            {
                if (strcmp(code, turestudent.code) == 0)
                {
                    printf("��ӭ��¼��\n");
                    flag = 2;
                    break;
                }
                rewind(file_student);
            }
            if (flag == 2)
            {
                break;
            }
            else
            {
                printf("���벻��ȷ��\n");
                printf("���ǵ�%d����������㻹��%d�λ���\n", i, 3 - i);
                printf("��������롰1���������룬���������˳���");
                scanf("%d", &flag);
                if (flag == 1)
                {
                    printf("����������:");
                    scanf("%19s", code);
                    i++;
                }
                else
                {
                    *usergroup = 0;
                    break;
                }
            }
            if (i == 3)
            {
                *usergroup = 0;
                printf("�������Σ������˳�!\n");
            }
        }
    }
    else if (*usergroup == 1)
    {
        i = 1;
        flag = 0;
        printf("���������룺");
        scanf("%19s", code);
        while (i != 3)
        {
            while (fread(&tureadmin, sizeof(Administrator), 1, file_admin) == 1)
            {
                if (strcmp(code, tureadmin.code) == 0)
                {
                    printf("��ӭ��¼��\n");
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
                printf("���벻��ȷ��\n");
                printf("���ǵ�%d����������㻹��%d�λ���\n", i, 3 - i);
                printf("��������롰1���������룬���������˳���");
                scanf("%d", &flag);
                if (flag == 1)
                {
                    printf("����������:");
                    scanf("%19s", code);
                    i++;
                }
                else
                {
                    *usergroup = 0;
                    break;
                }
            }
            if (i == 3)
            {
                *usergroup = 0;
                printf("�������Σ������˳�!\n");
            }
        }
    }
    fclose(file_student);
    fclose(file_admin);
}
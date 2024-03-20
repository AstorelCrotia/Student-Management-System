#include "head.h"

void Validation(char *username, int *usergroup,int *sc) // ��֤����
{
    Student *turestudent = NULL;
    Administrator *tureadmin = NULL;
    int flag = 0;
    int i = 1;
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
        while (fread(turestudent, sizeof(Student), 1, file_student) == 1)
        {
            if (strcmp(username, turestudent->username) == 0)
            {
                printf("��ӭ��¼��\n");
                *usergroup = 2;
                flag = 2;
                break;
            }
        }
        rewind(file_student);
        while (fread(tureadmin, sizeof(Administrator), 1, file_admin) == 1)
        {
            if (strcmp(username, tureadmin->username) == 0)
            {
                printf("��ӭ��¼��\n");
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
            scanf("%d",&flag);
            if (flag == 1)
            {
                printf("�������û���:");
                scanf("%s", username);
            }
            else
            {
                break;
            }
        }
        i++;
    }
    fclose(file_student);
    fclose(file_admin);
    free(tureadmin);
    free(turestudent);
}
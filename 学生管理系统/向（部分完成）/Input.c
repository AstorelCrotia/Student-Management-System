#include "head.h"

void Input(int usergroup) // ¼��
{
    int sc = 0;
    printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
    printf("��ѡ������Ҫ�Ĺ��ܣ���\n");
    printf("¼��ѧ����Ϣ�����롰1��        ¼���¹���Ա�����롰2��\n");
    printf("�˳�¼�빦����������:");
    scanf("%d", &sc);
    if (sc == 2)
    {
        Administrator adminuser = {0};
        char input = '0';
        int flag = 0;
        while (1)
        {
            flag = 0;
            FILE *file_read = fopen("Admin.txt", "r");
            if (file_read == NULL)
            {
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("����������ʧ��\n");
                return;
            }
            Administrator admin = {0};
            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
            printf("������Ҫ¼����û�����");
            scanf("%s", admin.username);
            while (fread(&adminuser, sizeof(Administrator), 1, file_read) == 1)
            {
                if (strcmp(admin.username, adminuser.username) == 0)
                {
                    printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                    printf("�û����Ѿ����ڣ�\n");
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("���������룺");
                scanf("%19s", admin.code);
            }
            FILE *file_write = fopen("Admin.txt", "a");
            if (file_write == NULL)
            {
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("���ӷ�����ʧ��\n");
                return;
            }
            fwrite(&admin, sizeof(Administrator), 1, file_write);
            fclose(file_write);
            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
            printf("�Ƿ��������Y/N�� \n");
            scanf(" %c", &input);
            if (input == 'n' || input == 'N')
            {
                break;
            }
        }
    }
    else if (sc == 1)
    {
        Student studentuser = {0};
        Student *head = NULL;
        Student *temp = NULL;
        char input = '0';
        int flag = 0;
        while (1)
        {
            flag = 0;
            FILE *file_read = fopen("Students.txt", "r");
            if (file_read == NULL)
            {
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("����������ʧ��\n");
                return;
            }
            Student student = {0};
            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
            printf("������Ҫ¼���ѧ��ѧ�ţ�");
            scanf("%s", student.username);
            while (fread(&studentuser, sizeof(Student), 1, file_read) == 1)
            {
                if (strcmp(student.username, studentuser.username) == 0)
                {
                    printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                    printf("�û����Ѿ����ڣ�\n");
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("������ѧ����������");
                scanf("%19s", student.name);
                printf("������ѧ�����Ա�");
                scanf("%9s", student.gender);
                printf("������ѧ�������룺");
                scanf("%19s", student.code);
                printf("������ѧ���İ༶��");
                scanf("%19s", student.class);
                printf("������ѧ������ѧ�ɼ���");
                scanf("%f", &student.math);
                printf("������ѧ�������ĳɼ���");
                scanf("%f", &student.chinese);
                printf("������ѧ����Ӣ��ɼ���");
                scanf("%f", &student.english);
                printf("������ѧ�������䣺");
                scanf("%d", &student.age);
            }
            FILE *file_write = fopen("Students.txt", "a");
            if (file_write == NULL)
            {
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("���ӷ�����ʧ��\n");
                return;
            }
            fwrite(&student, sizeof(Student), 1, file_write);
            fclose(file_write);
            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
            printf("�Ƿ��������Y/N�� \n");
            scanf(" %c", &input);
            if (input == 'n' || input == 'N')
            {
                break;
            }
        }
    }
    else
    {
        return;
    }
}
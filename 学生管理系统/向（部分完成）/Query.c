#include "head.h"

void Query(int usergroup) // ��ѯ
{
    int sc = 0;
    char input[20] = "\0";
    if (usergroup == 1)
    {
        while(1)
        {
            sc = 0;
            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
            printf("��ѡ������Ҫ�Ĺ��ܣ���\n");
            printf("��ѯѧ����Ϣ�����롰1��        ��ѯ����Ա��Ϣ�����롰2��\n");
            printf("�˳���ѯ������������:");
            scanf("%d", &sc);
            if (sc == 1)
            {
                Student *head = NULL;
                Student *temp = (Student *)malloc(sizeof(Student));
                Student s1 = {0};
                FILE *file_read = fopen("Students.txt", "r");
                if (file_read == NULL)
                {
                    printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                    printf("����������ʧ��\n");
                    break;
                }
                while (fread(&s1, sizeof(Student), 1, file_read) == 1)
                {
                    if (head == NULL)
                    {
                        head = s1;
                        temp = s1;
                    }
                    else
                    {
                        temp->next = s1;
                        temp = s1;
                    }
                }
                temp = head;
                sc = 0;
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("��ѡ������Ҫ�Ĺ��ܣ���\n");
                printf("����ָ����ѧ����Ϣ��ѯ���롰1��        ȫ����ʾ���롰2��\n");
                printf("�˳���ѯ������������:");
                scanf("%d", &sc);
                if (sc == 1)
                {
                    sc = 0;
                    printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                    printf("��ѡ������Ҫ�Ĺ��ܣ���\n");
                    printf("����ѧ��������ѯ���롰1��           ����ѧ����ѧ�ɼ���ѯ���롰2�� \n");
                    printf("����ѧ�����ĳɼ���ѯ���롰3��        ����ѧ��Ӣ��ɼ���ѯ���롰4�� \n");
                    printf("����ѧ���ɼ�������ѯ���롰5��        �˳���ѯ������������ \n");
                    scanf("%d", &sc);
                    switch (sc)
                    {
                    case 1:
                        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                        printf("������Ҫ��ѯ��������");
                        scanf("%19s", input);
                        while (temp->next != NULL)
                        {
                            if (strcmp(input, temp->name) == 0)
                            {
                                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                                printf("��ѧ����id��%d����ѧ����������%s����ѧ�����Ա�%s����ѧ�������䣺%d��\n", s1.username, s1.name, s1.gender, s1.age);
                                printf("��ѧ���İ༶��%s����ѧ���ĳɼ����Σ�%d��\n", s1.class, s1.rank);
                                printf("��ѧ������ѧ�ɼ���%d����ѧ�������ĳɼ���d����ѧ����Ӣ��ɼ���d��\n", s1.math, s1.chinese, s1.english);
                                printf("�û����Ѿ����ڣ�\n");
                                flag = 1;
                                break;
                            }
                        }
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    default:
                        break;
                    }
                }
                else if (sc == 2)
                {
                }
                else
                {
                    break;
                }
            }
            else if (sc == 2)
            {
                sc = 0;
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("��ѡ������Ҫ�Ĺ��ܣ���\n");
                printf("����ָ���Ĺ���Ա��Ϣ��ѯ���롰1��      ȫ����ʾ���롰2��\n");
                printf("�˳���ѯ������������:");
                scanf("%d", &sc);
                if (sc == 1)
                {
                }
                else if (sc == 2)
                {
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    else if (usergroup == 2)
    {
    }
    else
    {
        return;
    }
}
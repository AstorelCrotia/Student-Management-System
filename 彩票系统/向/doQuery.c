#include "head.h"

void conditionQueryuser() // ������ѯ�û�
{
    int rk = 0;
    int i = 0;
    int sc = 0;
    char input[20] = "\0";
    float score = 0;
    if (usergroup == 1)
    {
        while (1)
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
                Student *temp = NULL;
                Student *s1 = (Student *)malloc(sizeof(Student));
                if (s1 == NULL)
                {
                    printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                    printf("�ڴ����ʧ��\n");
                    break;
                }
                FILE *file_read = fopen("Students.txt", "r");
                if (file_read == NULL)
                {
                    printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                    printf("����������ʧ��\n");
                    break;
                }
                while (fread(s1, sizeof(Student), 1, file_read) == 1)
                {
                    s1->next = NULL;
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
                    s1 = (Student *)malloc(sizeof(Student));
                    if (s1 == NULL)
                    {
                        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                        printf("�ڴ����ʧ��\n");
                        break;
                    }
                }
                fclose(file_read);
                temp = head;
                if (temp == NULL)
                {
                    printf("���ݻ�ȡʧ��\n");
                    free(s1);
                    return;
                }
                free(s1);
                Student s2 = {0};
                Student *end = NULL;
                while (1)
                {
                    int flag = 0;
                    while (temp->next != end)
                    {
                        if (temp->sum < temp->next->sum)
                        {
                            s2 = *temp;
                            *temp = *(temp->next);
                            *(temp->next) = s2;
                            flag = 1;
                        }
                        temp = temp->next;
                    }
                    if (flag == 0)
                    {
                        break;
                    }
                    end = temp;
                    temp = head;
                }
                temp = head;
                int i = 1;
                while (temp != NULL)
                {
                    temp->rank = i;
                    temp = temp->next;
                    i++;
                }
                // temp = head;
                // while (temp != NULL)
                //{
                //     Student *toFree = temp;
                //     temp = temp->next;
                //     free(toFree);
                // }
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
                    printf("����ѧ���ɼ�������ѯ���롰5��        �˳���ѯ������������:");
                    scanf("%d", &sc);
                    switch (sc)
                    {
                    case 1:
                        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                        printf("������Ҫ��ѯ��������");
                        scanf("%19s", input);
                        temp = head;
                        while (temp != NULL)
                        {
                            if (strcmp(input, temp->name) == 0)
                            {
                                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                                printf("��ѧ����id��%s����ѧ����������%s����ѧ�����Ա�%s����ѧ�������䣺%d��\n", temp->username, temp->name, temp->gender, temp->age);
                                printf("��ѧ���İ༶��%s����ѧ���ĳɼ����Σ�%d��\n", temp->class, temp->rank);
                                printf("��ѧ������ѧ�ɼ���%.1f����ѧ�������ĳɼ���%.1f����ѧ����Ӣ��ɼ���%.1f��\n", temp->math, temp->chinese, temp->english);
                                sc = 1;
                                break;
                            }
                            temp = temp->next;
                            sc = 0;
                        }
                        if (sc == 0)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("û���ҵ���������ѧ��!\n");
                        }
                        break;
                    case 2:
                        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                        printf("������Ҫ��ѯ����ѧ�ɼ���");
                        scanf("%.1f", &score);
                        temp = head;
                        while (temp != NULL)
                        {
                            if (score == temp->math)
                            {
                                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                                printf("��ѧ����id��%s����ѧ����������%s����ѧ�����Ա�%s����ѧ�������䣺%d��\n", temp->username, temp->name, temp->gender, temp->age);
                                printf("��ѧ���İ༶��%s����ѧ���ĳɼ����Σ�%d��\n", temp->class, temp->rank);
                                printf("��ѧ������ѧ�ɼ���%.1f����ѧ�������ĳɼ���%.1f����ѧ����Ӣ��ɼ���%.1f��\n", temp->math, temp->chinese, temp->english);
                                sc = 1;
                                break;
                            }
                            temp = temp->next;
                            sc = 0;
                        }
                        if (sc == 0)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("û���ҵ���ѧ�ɼ�Ϊ%.1f��ѧ��!\n", score);
                        }
                        break;
                    case 3:
                        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                        printf("������Ҫ��ѯ�����ĳɼ���");
                        scanf("%.1f", &score);
                        temp = head;
                        while (temp != NULL)
                        {
                            if (score == temp->chinese)
                            {
                                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                                printf("��ѧ����id��%s����ѧ����������%s����ѧ�����Ա�%s����ѧ�������䣺%d��\n", temp->username, temp->name, temp->gender, temp->age);
                                printf("��ѧ���İ༶��%s����ѧ���ĳɼ����Σ�%d��\n", temp->class, temp->rank);
                                printf("��ѧ������ѧ�ɼ���%.1f����ѧ�������ĳɼ���%.1f����ѧ����Ӣ��ɼ���%.1f��\n", temp->math, temp->chinese, temp->english);
                                sc = 1;
                                break;
                            }
                            temp = temp->next;
                            sc = 0;
                        }
                        if (sc == 0)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("û���ҵ����ĳɼ�Ϊ%.1f��ѧ��!\n", score);
                        }
                        break;
                    case 4:
                        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                        printf("������Ҫ��ѯ��Ӣ��ɼ���");
                        scanf("%.1f", &score);
                        temp = head;
                        while (temp != NULL)
                        {
                            if (score == temp->english)
                            {
                                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                                printf("��ѧ����id��%s����ѧ����������%s����ѧ�����Ա�%s����ѧ�������䣺%d��\n", temp->username, temp->name, temp->gender, temp->age);
                                printf("��ѧ���İ༶��%s����ѧ���ĳɼ����Σ�%d��\n", temp->class, temp->rank);
                                printf("��ѧ������ѧ�ɼ���%.1f����ѧ�������ĳɼ���%.1f����ѧ����Ӣ��ɼ���%.1f��\n", temp->math, temp->chinese, temp->english);
                                sc = 1;
                                break;
                            }
                            temp = temp->next;
                            sc = 0;
                        }
                        if (sc == 0)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("û���ҵ�Ӣ��ɼ�Ϊ%.1f��ѧ��!\n", score);
                        }
                        break;
                    case 5:
                        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                        printf("������Ҫ��ѯ��������");
                        scanf("%d", &rk);
                        temp = head;
                        while (temp != NULL)
                        {
                            if (rk == temp->rank)
                            {
                                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                                printf("��ѧ����id��%s����ѧ����������%s����ѧ�����Ա�%s����ѧ�������䣺%d��\n", temp->username, temp->name, temp->gender, temp->age);
                                printf("��ѧ���İ༶��%s����ѧ���ĳɼ����Σ�%d��\n", temp->class, temp->rank);
                                printf("��ѧ������ѧ�ɼ���%.1f����ѧ�������ĳɼ���%.1f����ѧ����Ӣ��ɼ���%.1f��\n", temp->math, temp->chinese, temp->english);
                                sc = 1;
                                break;
                            }
                            temp = temp->next;
                            sc = 0;
                        }
                        if (sc == 0)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("û���ҵ���������ѧ��!\n");
                        }
                        break;
                    default:
                        break;
                    }
                }
                else if (sc == 2)
                {
                    i = 1;
                    temp = head;
                    while (temp != NULL)
                    {
                        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                        printf("��%dλѧ��Ϊ\n",i);
                        printf("ѧ����id��%s��ѧ����������%s��ѧ�����Ա�%s��ѧ�������䣺%d��\n", temp->username, temp->name, temp->gender, temp->age);
                        printf("ѧ���İ༶��%s��ѧ���ĳɼ����Σ�%d��\n", temp->class, temp->rank);
                        printf("ѧ������ѧ�ɼ���%.1f��ѧ�������ĳɼ���%.1f��ѧ����Ӣ��ɼ���%.1f��\n", temp->math, temp->chinese, temp->english);
                        temp = temp->next;
                        i++;
                    }
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
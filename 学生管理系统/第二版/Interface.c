#include "head.h"

void Interface(int usergroup, char *username) // ����
{
    int sc = 0;
    char flag = '\0';
    if (usergroup == 1)
    {
        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
        printf("��ӭ����Ա%s��¼ѧ������ϵͳ��\n", username);
        printf("��ѡ������Ҫ�Ĺ��ܣ���\n");
        printf("��ѯ�������롰1��        �޸Ĺ������롰2��\n");
        printf("¼�빦�����롰3��        ɾ���������롰4��\n");
        printf("�˳�����ϵͳ��������:");
        scanf("%d", &sc);
        switch (sc)
        {
        case 1:
            while (1)
            {
                Query(usergroup);
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("�Ƿ������ѯ����Y/N�� ");
                scanf(" %c", &flag);
                if (flag == 'n' || flag == 'N')
                {
                    break;
                }
            }
            break;
        case 2:
            while (1)
            {
                // Modify(usergroup, username);
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("�Ƿ�����޸ģ���Y/N�� ");
                scanf(" %c", &flag);
                if (flag == 'n' || flag == 'N')
                {
                    break;
                }
            }
            break;
        case 3:
            while (1)
            {
                Input(usergroup);
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("�Ƿ����¼�룺��Y/N�� ");
                scanf(" %c", &flag);
                if (flag == 'n' || flag == 'N')
                {
                    break;
                }
            }
            break;
        case 4:
            while (1)
            {
                // Delete(usergroup, username);
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("�Ƿ����ɾ������Y/N�� ");
                scanf(" %c", &flag);
                if (flag == 'n' || flag == 'N')
                {
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    else if (usergroup == 2)
    {
        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
        printf("��ӭѧ��%s��¼ѧ������ϵͳ��\n", username);
        printf("��ѡ������Ҫ�Ĺ��ܣ���\n");
        printf("��ѯ�������롰1��        �޸��������롰2��\n");
        printf("�˳�����ϵͳ��������:");
        scanf("%d", &sc);
        switch (sc)
        {
        case 1:
            while (1)
            {
                Query(usergroup);
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("�Ƿ������ѯ����Y/N�� ");
                scanf(" %c", &flag);
                if (flag == 'n' || flag == 'N')
                {
                    break;
                }
            }
            break;
        case 2:
            while (1)
            {
                // Modify(usergroup, username);
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("�Ƿ�����޸ģ���Y/N�� ");
                scanf(" %c", &flag);
                if (flag == 'n' || flag == 'N')
                {
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    else
    {
        return;
    }
}
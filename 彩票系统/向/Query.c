#include "head.h"

void adminQuery(int *sc) // ����Ա��ѯ
{
    *sc = 0;
    while (*sc != 8)
    {
        *sc = 0;
        printf("====================================\n");
        printf("|  ��ӭʹ�ò�ѯ���ܣ�            |\n");
        printf("|                                |\n");
        printf("|  ��ѡ������Ҫ�Ĺ��ܣ�          |\n");
        printf("|                                |\n");
        printf("|  ������ѯ�û���Ϣ���롰1��       |\n");
        printf("|                                |\n");
        printf("|  ������ѯ��Ʊ��ʷ���롰2��       |\n");
        printf("|                                |\n");
        printf("|  ������ѯ��ʷ�������롰3��       |\n");
        printf("|                                |\n");
        printf("|  ��ѯ�����û���Ϣ���롰4��       |\n");
        printf("|                                |\n");
        printf("|  ��ѯ������ʷ��Ʊ���롰5��       |\n");
        printf("|                                |\n");
        printf("|  ��ѯ������ʷ�н����롰6��       |\n");
        printf("|                                |\n");
        printf("|  ��ѯ��Ʊ����Ӫ�����롰7��       |\n");
        printf("|                                |\n");
        printf("|  �˳�ϵͳ��������              |\n");
        printf("====================================\n");
        printf("������룺");
        scanf(" %d", sc);
        switch (*sc)
        {
        case 1:
            conditionQueryuser();
            break;
        case 2:
            conditionQuerybuy();
            break;
        case 3:
            conditionQuerywin();
            break;
        case 4:
            allQueryuser();
            break;
        case 5:
            allnQueryubuy();
            break;
        case 6:
            allQuerywin();
            break;
        case 7:
            Querymoney();
            break;
        default:
            *sc = 8;
            break;
        }
    }
}

void userQuery(int *sc, char *id) // �û���ѯ
{
    *sc = 0;
    while (*sc != 6)
    {
        *sc = 0;
        printf("====================================\n");
        printf("|  ��ӭʹ�ò�ѯ���ܣ�            |\n");
        printf("|                                |\n");
        printf("|  ��ѡ������Ҫ�Ĺ��ܣ�          |\n");
        printf("|                                |\n");
        printf("|  ��ѯ�Լ�����Ϣ���롰1��         |\n");
        printf("|                                |\n");
        printf("|  ��ѯ�Լ���ʷ��Ʊ���롰2��       |\n");
        printf("|                                |\n");
        printf("|  ��ѯ�Լ���ʷ�н����롰3��       |\n");
        printf("|                                |\n");
        printf("|  �˳�ϵͳ��������              |\n");
        printf("====================================\n");
        printf("������룺");
        scanf(" %d", sc);
        switch (*sc)
        {
        case 1:
            Showuser(id);
            break;
        case 2:
            conditionQueryuserbuy(id);
            break;
        case 3:
            userQuerywin(id);
            break;
        default:
            *sc = 6;
            break;
        }
    }
}

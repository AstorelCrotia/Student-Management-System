#include "head.h"

void conditionQueryuser() // ������ѯ�û�
{
    char input[20] = "\0";
    User uid = {0};
    int flag = 0;
    printf("============================\n");
    printf("��������Ҫ��ѯ���û�����");
    scanf("%19s", input);
    FILE *file_read = fopen("users.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    while (fread(&uid, sizeof(User), 1, file_read) == 1)
    {
        if (strcmp(input, uid.uid) == 0)
        {
            printf("============================\n");
            printf("|  �û�����%s             |\n", uid.uid);
            printf("|  ���룺%s              |\n", uid.code);
            printf("|  �˻���%.2f           |\n", uid.balance);
            printf("============================\n");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("============================\n");
        printf("|  �û��������ڣ�          |\n");
        printf("============================\n");
    }
    fclose(file_read);
}

void conditionQuerybuy() // ������ѯ��Ʊ��ʷ
{
}

void conditionQuerywin() // ������ѯ��ʷ����
{
}

void allQueryuser() // ��ѯ�����û���Ϣ
{
    User uid = {0};
    int i = 1;
    FILE *file_read = fopen("users.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    printf("============================\n");
    while (fread(&uid, sizeof(User), 1, file_read) == 1)
    {
        printf("|  ��%dλ�û���  ", i);
        printf("�û�����%s  ", uid.uid);
        printf("���룺%s  ", uid.code);
        printf("�˻���%.2f     |\n", uid.balance);
        i++;
    }
    printf("============================\n");
    fclose(file_read);
}

void allnQueryubuy() // ��ѯ������ʷ��Ʊ
{
}

void allQuerywin() // ��ѯ������ʷ����
{
}

void Querymoney() // ��ѯ��Ʊ����Ӫ��
{
}

void Showuser(char *id)// �û���ѯ�Լ���Ϣ
{
    User uid = {0};
    FILE *file_read = fopen("users.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    while (fread(&uid, sizeof(User), 1, file_read) == 1)
    {
        if (strcmp(id, uid.uid) == 0)
        {
            printf("============================\n");
            printf("|  �û�����%s             |\n", uid.uid);
            printf("|  ���룺%s              |\n", uid.code);
            printf("|  �˻���%.2f           |\n", uid.balance);
            printf("============================\n");
            break;
        }
    }
    fclose(file_read);
}
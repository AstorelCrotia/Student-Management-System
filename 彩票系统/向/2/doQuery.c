#include "head.h"

void conditionQueryuser() // ������ѯ�û�
{
    char input[20] = "\0";
    User uid = {0};
    int flag = 0;
    printf("============================\n");
    printf("��������Ҫ��ѯ���û�����");
    scanf("%19s", input);
    while (getchar() != '\n')
        ;
    FILE *file_read = fopen("users.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "�û�����%s  ���룺%s  ��%f\n", uid.uid, uid.code, &uid.balance) != EOF)
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
    char input[20] = "\0";
    Lottery uid = {0};
    int flag = 0;
    printf("============================\n");
    printf("��������Ҫ��ѯ���û�����");
    scanf("%19s", input);
    while (getchar() != '\n')
        ;
    FILE *file_read = fopen("history.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "��Ʊid��%s  �����û���%s  �ںţ�%s  ��Ʊ���ͣ�%d  �û����룺%s  �н����룺%s  �Ƿ񿪽���%d  �Ƿ��н���%d  �������ڣ�%s  �������ڣ�%s\n",
                  uid.tid, uid.uid, uid.did, &uid.category, uid.usernumber, uid.winnumber,
                  &uid.draw, &uid.win, uid.buydate, uid.windate) != EOF)
    {
        if (strcmp(input, uid.uid) == 0)
        {
            printf("============================\n");
            printf("|  �ʺţ�%s             |\n", uid.tid);
            printf("|  �ںţ�%s             |\n", uid.did);
            if (uid.category == 1)
            {
                printf("|  ���ͣ�bbg��             |\n");
            }
            else if (uid.category == 2)
            {
                printf("|  ���ͣ�A��             |\n");
            }
            else
            {
                printf("|  ���ͣ�B��             |\n");
            }
            printf("|  �û����룺%s             |\n", uid.usernumber);
            printf("|  �н����룺%s             |\n", uid.winnumber);
            if (uid.win == 1)
            {
                printf("|  �Ƿ��н����н���          |\n");
            }
            else
            {
                printf("|  �Ƿ��н���û�У�          |\n");
            }
            printf("|  �������ڣ�%s         |\n", uid.buydate);
            printf("|  �������ڣ�%s         |\n", uid.windate);
            printf("============================\n");
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("============================\n");
        printf("|  �û�������ʷ��Ϣ��       |\n");
        printf("============================\n");
    }
    fclose(file_read);
}

void conditionQuerywin() // ������ѯ��ʷ����
{
    char input[20] = "\0";
    Lottery uid = {0};
    int flag = 0;
    printf("============================\n");
    printf("��������Ҫ��ѯ���ںţ�");
    scanf("%19s", input);
    while (getchar() != '\n')
        ;
    FILE *file_read = fopen("history.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "��Ʊid��%s  �����û���%s  �ںţ�%s  ��Ʊ���ͣ�%d  �û����룺%s  �н����룺%s  �Ƿ񿪽���%d  �Ƿ��н���%d  �������ڣ�%s  �������ڣ�%s\n",
                  uid.tid, uid.uid, uid.did, &uid.category, uid.usernumber, uid.winnumber,
                  &uid.draw, &uid.win, uid.buydate, uid.windate) != EOF)
    {
        if (strcmp(input, uid.did) == 0)
        {
            printf("============================\n");
            printf("|  �ʺţ�%s             |\n", uid.tid);
            printf("|  ���ţ�%s             |\n", uid.uid);
            if (uid.category == 1)
            {
                printf("|  ���ͣ�bbg��             |\n");
            }
            else if (uid.category == 2)
            {
                printf("|  ���ͣ�A��             |\n");
            }
            else
            {
                printf("|  ���ͣ�B��             |\n");
            }
            printf("|  �û����룺%s             |\n", uid.usernumber);
            printf("|  �н����룺%s             |\n", uid.winnumber);
            if (uid.win == 1)
            {
                printf("|  �Ƿ��н����н���          |\n");
            }
            else
            {
                printf("|  �Ƿ��н���û�У�          |\n");
            }
            printf("|  �������ڣ�%s         |\n", uid.buydate);
            printf("|  �������ڣ�%s         |\n", uid.windate);
            printf("============================\n");
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("============================\n");
        printf("|  �޸��ںţ�              |\n");
        printf("============================\n");
    }
    fclose(file_read);
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
    while (fscanf(file_read, "�û�����%s  ���룺%s  ��%f\n", uid.uid, uid.code, &uid.balance) != EOF)
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
    Lottery uid = {0};
    FILE *file_read = fopen("history.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "��Ʊid��%s  �����û���%s  �ںţ�%s  ��Ʊ���ͣ�%d  �û����룺%s  �н����룺%s  �Ƿ񿪽���%d  �Ƿ��н���%d  �������ڣ�%s  �������ڣ�%s\n",
                  uid.tid, uid.uid, uid.did, &uid.category, uid.usernumber, uid.winnumber,
                  &uid.draw, &uid.win, uid.buydate, uid.windate) != EOF)
    {
        printf("============================\n");
        printf("|  �ʺţ�%s             |\n", uid.tid);
        printf("|  ���ţ�%s             |\n", uid.uid);
        printf("|  �ںţ�%s             |\n", uid.did);
        if (uid.category == 1)
        {
            printf("|  ���ͣ�bbg��             |\n");
        }
        else if (uid.category == 2)
        {
            printf("|  ���ͣ�A��             |\n");
        }
        else
        {
            printf("|  ���ͣ�B��             |\n");
        }
        printf("|  �û����룺%s             |\n", uid.usernumber);
        printf("|  �н����룺%s             |\n", uid.winnumber);
        if (uid.win == 1)
        {
            printf("|  �Ƿ��н����н���          |\n");
        }
        else
        {
            printf("|  �Ƿ��н���û�У�          |\n");
        }
        printf("|  �������ڣ�%s         |\n", uid.buydate);
        printf("|  �������ڣ�%s         |\n", uid.windate);
        printf("============================\n");
    }
    fclose(file_read);
}

void allQuerywin() // ��ѯ������ʷ����
{
    Lottery uid = {0};
    int flag = 0;
    FILE *file_read = fopen("history.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    printf("============================\n");
    while (fscanf(file_read, "��Ʊid��%s  �����û���%s  �ںţ�%s  ��Ʊ���ͣ�%d  �û����룺%s  �н����룺%s  �Ƿ񿪽���%d  �Ƿ��н���%d  �������ڣ�%s  �������ڣ�%s\n",
                  uid.tid, uid.uid, uid.did, &uid.category, uid.usernumber, uid.winnumber,
                  &uid.draw, &uid.win, uid.buydate, uid.windate) != EOF)
    {
        if (uid.win == 1)
        {
            printf("============================\n");
            printf("|  �ʺţ�%s             |\n", uid.tid);
            printf("|  ���ţ�%s             |\n", uid.uid);
            printf("|  �ںţ�%s             |\n", uid.tid);
            if (uid.category == 1)
            {
                printf("|  ���ͣ�bbg��             |\n");
            }
            else if (uid.category == 2)
            {
                printf("|  ���ͣ�A��             |\n");
            }
            else
            {
                printf("|  ���ͣ�B��             |\n");
            }
            printf("|  �û����룺%s             |\n", uid.usernumber);
            printf("|  �н����룺%s             |\n", uid.winnumber);
            printf("|  �������ڣ�%s             |\n", uid.buydate);
            printf("|  �������ڣ�%s             |\n", uid.windate);
            printf("============================\n");
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("============================\n");
        printf("|  ���н��ţ�              |\n");
        printf("============================\n");
    }
    fclose(file_read);
}

void Querymoney() // ��ѯ��Ʊ����Ӫ��
{
    Revenue uid = {0};
    float balance = 0;
    FILE *file_read = fopen("revenue.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "�����û���%s  ����ʱ�䣺%s  ��Ʊ���ͣ�%d  ������%f\n",
            uid.uid,uid.buydate,&uid.category,&uid.money) != EOF)
    {
        printf("============================\n");
        printf("|  �����û���%s             |\n", uid.uid);
        if (uid.category == 1)
        {
            printf("|  ���ͣ�bbg��             |\n");
        }
        else if (uid.category == 2)
        {
            printf("|  ���ͣ�A��             |\n");
        }
        else
        {
            printf("|  ���ͣ�B��             |\n");
        }
        printf("|  ������%s               |\n", uid.buydate);
        printf("|  ������%.2f             |\n", uid.money);
        balance += uid.money;
        printf("|  �ʽ���%.2f             |\n", balance);
        printf("============================\n");
    }
    fclose(file_read);
}

void Showuser(char *id) // �û���ѯ�Լ���Ϣ
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
    while (fscanf(file_read, "�û�����%s  ���룺%s  ��%f\n", uid.uid, uid.code, &uid.balance) != EOF)
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

void conditionQueryuserbuy(char *id) // ������ѯ��Ʊ��ʷ
{
    Lottery uid = {0};
    int flag = 0;
    FILE *file_read = fopen("history.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "��Ʊid��%s  �����û���%s  �ںţ�%s  ��Ʊ���ͣ�%d  �û����룺%s  �н����룺%s  �Ƿ񿪽���%d  �Ƿ��н���%d  �������ڣ�%s  �������ڣ�%s\n",
                  uid.tid, uid.uid, uid.did, &uid.category, uid.usernumber, uid.winnumber,
                  &uid.draw, &uid.win, uid.buydate, uid.windate) != EOF)
    {
        if (strcmp(id, uid.uid) == 0)
        {
            printf("============================\n");
            printf("|  �ʺţ�%s             |\n", uid.tid);
            printf("|  �ںţ�%s             |\n", uid.did);
            if (uid.category == 1)
            {
                printf("|  ���ͣ�bbg��             |\n");
            }
            else if (uid.category == 2)
            {
                printf("|  ���ͣ�A��             |\n");
            }
            else
            {
                printf("|  ���ͣ�B��             |\n");
            }
            printf("|  �û����룺%s             |\n", uid.usernumber);
            printf("|  �н����룺%s             |\n", uid.winnumber);
            if (uid.win == 1)
            {
                printf("|  �Ƿ��н����н���          |\n");
            }
            else
            {
                printf("|  �Ƿ��н���û�У�          |\n");
            }
            printf("|  �������ڣ�%s             |\n", uid.buydate);
            printf("|  �������ڣ�%s             |\n", uid.windate);
            printf("============================\n");
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("============================\n");
        printf("|  �û�������ʷ��Ϣ��       |\n");
        printf("============================\n");
    }
    fclose(file_read);
}

void userQuerywin(char *id) // ��ѯ������ʷ����
{
    Lottery uid = {0};
    int flag = 0;
    FILE *file_read = fopen("history.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    printf("============================\n");
    while (fscanf(file_read, "��Ʊid��%s  �����û���%s  �ںţ�%s  ��Ʊ���ͣ�%d  �û����룺%s  �н����룺%s  �Ƿ񿪽���%d  �Ƿ��н���%d  �������ڣ�%s  �������ڣ�%s\n",
                  uid.tid, uid.uid, uid.did, &uid.category, uid.usernumber, uid.winnumber,
                  &uid.draw, &uid.win, uid.buydate, uid.windate) != EOF)
    {
        if (uid.win == 1 && strcmp(id, uid.uid) == 0)
        {
            printf("============================\n");
            printf("|  �ʺţ�%s             |\n", uid.tid);
            printf("|  ���ţ�%s             |\n", uid.uid);
            printf("|  �ںţ�%s             |\n", uid.did);
            if (uid.category == 1)
            {
                printf("|  ���ͣ�bbg��             |\n");
            }
            else if (uid.category == 2)
            {
                printf("|  ���ͣ�A��             |\n");
            }
            else
            {
                printf("|  ���ͣ�B��             |\n");
            }
            printf("|  �û����룺%s             |\n", uid.usernumber);
            printf("|  �н����룺%s             |\n", uid.winnumber);
            printf("|  �������ڣ�%s             |\n", uid.buydate);
            printf("|  �������ڣ�%s             |\n", uid.windate);
            printf("============================\n");
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("============================\n");
        printf("|  ���н��ţ�              |\n");
        printf("============================\n");
    }
    fclose(file_read);
}
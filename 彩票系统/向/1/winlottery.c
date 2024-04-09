#include "head.h"

void winlottery(int *sc) // ��Ʊ����
{
    printf("====================================\n");
    printf("|  ��ѡ����Ҫ�����Ĳ�Ʊ��         |\n");
    printf("|                                |\n");
    printf("|  bbg�����롰1��                  |\n");
    printf("|                                |\n");
    printf("|  A�����롰2��                    |\n");
    printf("|                                |\n");
    printf("|  B�����롰3��                    |\n");
    printf("|                                |\n");
    printf("|  �˳�ϵͳ��������              |\n");
    printf("====================================\n");
    printf("������룺");
    scanf("%d", sc);
    switch (*sc)
    {
    case 1:
        winlotteryin1();
        break;
    case 2:
        winlotteryin2();
        break;
    case 3:
        winlotteryin3();
        break;
    default:
        break;
    }
}

void winlotteryin1() // ��Ʊ����д��1
{
    int randomNum[6] = {0};
    char randomStr[20] = "\0";
    srand(time(NULL));
    for (int i = 0; i < 6; i++)
    {
        randomNum[i] = rand() % 100;
    }
    snprintf(randomStr, sizeof(randomStr), "%02d %02d %02d %02d %02d : %02d", randomNum[0], randomNum[1], randomNum[2], randomNum[3], randomNum[4], randomNum[5]);
    Lottery *head = NULL;
    Lottery *temp = NULL;
    Lottery *lottery = (Lottery *)malloc(sizeof(Lottery));
    if (lottery == NULL)
    {
        printf("============================\n");
        printf("|  �ڴ����ʧ�ܣ�          |\n");
        printf("============================\n");
        return;
    }
    FILE *file_read = fopen("lottery1.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    while (fread(lottery, sizeof(Lottery), 1, file_read) == 1)
    {
        lottery->next = NULL;
        if (head == NULL)
        {
            head = lottery;
            temp = lottery;
        }
        else
        {
            temp->next = lottery;
            temp = lottery;
        }
        lottery = (Lottery *)malloc(sizeof(Lottery));
        if (lottery == NULL)
        {
            printf("============================\n");
            printf("|  �ڴ����ʧ�ܣ�          |\n");
            printf("============================\n");
            return;
        }
    }
    fclose(file_read);
    free(lottery);
    temp = head;
    while (temp != NULL)
    {
        InwinDate(temp);
        didDate(temp);
        temp->draw = 1;
        strcpy(temp->winnumber, randomStr);
        Prize(temp, randomNum, 12);
        temp = temp->next;
    }
    FILE *file_write = fopen("lottery1.txt", "w");
    if (file_write == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    fclose(file_write);
    file_write = fopen("history.txt", "a");
    if (file_write == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    temp = head;
    while (temp != NULL)
    {
        fwrite(temp, sizeof(Lottery), 1, file_write);
        temp = temp->next;
    }
    fclose(file_write);
    temp = head;
    while (temp != NULL)
    {
        Lottery *toFree = temp;
        temp = temp->next;
        free(toFree);
    }
    head = NULL;
}

void winlotteryin2() // ��Ʊ����д��2
{
    int randomNum[6] = {0};
    char randomStr[20] = "\0";
    srand(time(NULL));
    for (int i = 0; i < 6; i++)
    {
        randomNum[i] = rand() % 100;
    }
    snprintf(randomStr, sizeof(randomStr), "%02d %02d %02d %02d %02d : %02d", randomNum[0], randomNum[1], randomNum[2], randomNum[3], randomNum[4], randomNum[5]);
    Lottery *head = NULL;
    Lottery *temp = NULL;
    Lottery *lottery = (Lottery *)malloc(sizeof(Lottery));
    if (lottery == NULL)
    {
        printf("============================\n");
        printf("|  �ڴ����ʧ�ܣ�          |\n");
        printf("============================\n");
        return;
    }
    FILE *file_read = fopen("lottery2.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    while (fread(lottery, sizeof(Lottery), 1, file_read) == 1)
    {
        lottery->next = NULL;
        if (head == NULL)
        {
            head = lottery;
            temp = lottery;
        }
        else
        {
            temp->next = lottery;
            temp = lottery;
        }
        lottery = (Lottery *)malloc(sizeof(Lottery));
        if (lottery == NULL)
        {
            printf("============================\n");
            printf("|  �ڴ����ʧ�ܣ�          |\n");
            printf("============================\n");
            return;
        }
    }
    fclose(file_read);
    free(lottery);
    temp = head;
    while (temp != NULL)
    {
        InwinDate(temp);
        didDate(temp);
        temp->draw = 1;
        strcpy(temp->winnumber, randomStr);
        Prize(temp, randomNum, 8);
        temp = temp->next;
    }
    FILE *file_write = fopen("lottery2.txt", "w");
    if (file_write == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    fclose(file_write);
    file_write = fopen("history.txt", "a");
    if (file_write == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    temp = head;
    while (temp != NULL)
    {
        fwrite(temp, sizeof(Lottery), 1, file_write);
        temp = temp->next;
    }
    fclose(file_write);
    temp = head;
    while (temp != NULL)
    {
        Lottery *toFree = temp;
        temp = temp->next;
        free(toFree);
    }
    head = NULL;
}

void winlotteryin3() // ��Ʊ����д��3
{
    int randomNum[6] = {0};
    char randomStr[20] = "\0";
    srand(time(NULL));
    for (int i = 0; i < 6; i++)
    {
        randomNum[i] = rand() % 100;
    }
    snprintf(randomStr, sizeof(randomStr), "%02d %02d %02d %02d %02d : %02d", randomNum[0], randomNum[1], randomNum[2], randomNum[3], randomNum[4], randomNum[5]);
    Lottery *head = NULL;
    Lottery *temp = NULL;
    Lottery *lottery = (Lottery *)malloc(sizeof(Lottery));
    if (lottery == NULL)
    {
        printf("============================\n");
        printf("|  �ڴ����ʧ�ܣ�          |\n");
        printf("============================\n");
        return;
    }
    FILE *file_read = fopen("lottery3.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    while (fread(lottery, sizeof(Lottery), 1, file_read) == 1)
    {
        lottery->next = NULL;
        if (head == NULL)
        {
            head = lottery;
            temp = lottery;
        }
        else
        {
            temp->next = lottery;
            temp = lottery;
        }
        lottery = (Lottery *)malloc(sizeof(Lottery));
        if (lottery == NULL)
        {
            printf("============================\n");
            printf("|  �ڴ����ʧ�ܣ�          |\n");
            printf("============================\n");
            return;
        }
    }
    fclose(file_read);
    free(lottery);
    temp = head;
    while (temp != NULL)
    {
        InwinDate(temp);
        didDate(temp);
        temp->draw = 1;
        strcpy(temp->winnumber, randomStr);
        Prize(temp, randomNum, 4);
        temp = temp->next;
    }
    FILE *file_write = fopen("lottery3.txt", "w");
    if (file_write == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    fclose(file_write);
    file_write = fopen("history.txt", "a");
    if (file_write == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    temp = head;
    while (temp != NULL)
    {
        fwrite(temp, sizeof(Lottery), 1, file_write);
        temp = temp->next;
    }
    fclose(file_write);
    temp = head;
    while (temp != NULL)
    {
        Lottery *toFree = temp;
        temp = temp->next;
        free(toFree);
    }
    head = NULL;
}
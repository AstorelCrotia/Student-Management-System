#include "head.h"

void winlottery(int *sc) // 彩票开奖
{
    printf("====================================\n");
    printf("|  请选择你要开奖的彩票！         |\n");
    printf("|                                |\n");
    printf("|  bbg彩输入“1”                  |\n");
    printf("|                                |\n");
    printf("|  A彩输入“2”                    |\n");
    printf("|                                |\n");
    printf("|  B彩输入“3”                    |\n");
    printf("|                                |\n");
    printf("|  退出系统输入其他              |\n");
    printf("====================================\n");
    printf("你的输入：");
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

void winlotteryin1() // 彩票开奖写入1
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
        printf("|  内存分配失败！          |\n");
        printf("============================\n");
        return;
    }
    FILE *file_read = fopen("lottery1.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
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
            printf("|  内存分配失败！          |\n");
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
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    fclose(file_write);
    file_write = fopen("history.txt", "a");
    if (file_write == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
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

void winlotteryin2() // 彩票开奖写入2
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
        printf("|  内存分配失败！          |\n");
        printf("============================\n");
        return;
    }
    FILE *file_read = fopen("lottery2.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
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
            printf("|  内存分配失败！          |\n");
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
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    fclose(file_write);
    file_write = fopen("history.txt", "a");
    if (file_write == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
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

void winlotteryin3() // 彩票开奖写入3
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
        printf("|  内存分配失败！          |\n");
        printf("============================\n");
        return;
    }
    FILE *file_read = fopen("lottery3.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
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
            printf("|  内存分配失败！          |\n");
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
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    fclose(file_write);
    file_write = fopen("history.txt", "a");
    if (file_write == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
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
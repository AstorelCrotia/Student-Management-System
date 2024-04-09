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
    // int randomNum[6] = {0};
    // char randomStr[20] = "\0";
    // srand(time(NULL));
    // for (int i = 0; i < 6; i++)
    // {
    //     randomNum[i] = rand() % 100;
    // }
    // snprintf(randomStr, sizeof(randomStr), "%02d-%02d-%02d-%02d-%02d:%02d", randomNum[0], randomNum[1], randomNum[2], randomNum[3], randomNum[4], randomNum[5]);
    int randomNum[6] = {10,10,10,10,10,10};
    char randomStr[20] = "10-10-10-10-10:10";
    Lottery *head = NULL;
    Lottery lottery = {0};
    Lottery *current = (Lottery *)malloc(sizeof(Lottery));
    if (current == NULL)
    {
        printf("============================\n");
        printf("|  内存分配失败！          |\n");
        printf("============================\n");
        return;
    }
    current->next = NULL;
    FILE *file_read = fopen("lottery1.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "彩票id：%s  购买用户：%s  期号：%s  彩票类型：%d  用户号码：%s  中奖号码：%s  是否开奖：%d  是否中奖：%d  购买日期：%s  开奖日期：%s\n",
                  lottery.tid, lottery.uid, lottery.did, &lottery.category, lottery.usernumber, lottery.winnumber,
                  &lottery.draw, &lottery.win, lottery.buydate, lottery.windate) != EOF)
    {
        if (head == NULL)
        {
            head = current;
        }
        else
        {
            current->next = (Lottery *)malloc(sizeof(Lottery));
            if (current == NULL)
            {
                printf("============================\n");
                printf("|  内存分配失败！          |\n");
                printf("============================\n");
                return;
            }
            current = current->next;
        }
        strcpy(current->tid, lottery.tid);
        strcpy(current->uid, lottery.uid);
        strcpy(current->did, lottery.did);
        current->category = lottery.category;
        strcpy(current->usernumber, lottery.usernumber);
        strcpy(current->winnumber, lottery.winnumber);
        current->draw = lottery.draw;
        current->win = lottery.win;
        strcpy(current->buydate, lottery.buydate);
        strcpy(current->windate, lottery.windate);
        current->next = NULL;
    }
    fclose(file_read);
    current = head;
    while (current != NULL)
    {
        InwinDate(current);
        current->draw = 1;
        strcpy(current->winnumber, randomStr);
        Prize(current, randomNum, 12);
        current = current->next;
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
    current = head;
    while (current != NULL)
    {
        fprintf(file_write, "彩票id：%s  购买用户：%s  期号：%s  彩票类型：%d  用户号码：%s  中奖号码：%s  是否开奖：%d  是否中奖：%d  购买日期：%s  开奖日期：%s\n",
                current->tid, current->uid, current->did, current->category, current->usernumber, current->winnumber,
                current->draw, current->win, current->buydate, current->windate);
        current = current->next;
    }
    fclose(file_write);
    current = head;
    while (current != NULL)
    {
        Lottery *toFree = current;
        current = current->next;
        free(toFree);
    }
    head = NULL;
    printf("============================\n");
    printf("|  开奖结束！            |\n");
    printf("============================\n");
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
    snprintf(randomStr, sizeof(randomStr), "%02d-%02d-%02d-%02d-%02d:%02d", randomNum[0], randomNum[1], randomNum[2], randomNum[3], randomNum[4], randomNum[5]);
    Lottery *head = NULL;
    Lottery lottery = {0};
    Lottery *current = (Lottery *)malloc(sizeof(Lottery));
    if (current == NULL)
    {
        printf("============================\n");
        printf("|  内存分配失败！          |\n");
        printf("============================\n");
        return;
    }
    current->next = NULL;
    FILE *file_read = fopen("lotter2.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "彩票id：%s  购买用户：%s  期号：%s  彩票类型：%d  用户号码：%s  中奖号码：%s  是否开奖：%d  是否中奖：%d  购买日期：%s  开奖日期：%s\n",
                  lottery.tid, lottery.uid, lottery.did, &lottery.category, lottery.usernumber, lottery.winnumber,
                  &lottery.draw, &lottery.win, lottery.buydate, lottery.windate) != EOF)
    {
        if (head == NULL)
        {
            head = current;
        }
        else
        {
            current->next = (Lottery *)malloc(sizeof(Lottery));
            if (current == NULL)
            {
                printf("============================\n");
                printf("|  内存分配失败！          |\n");
                printf("============================\n");
                return;
            }
            current = current->next;
        }
        strcpy(current->tid, lottery.tid);
        strcpy(current->uid, lottery.uid);
        strcpy(current->did, lottery.did);
        current->category = lottery.category;
        strcpy(current->usernumber, lottery.usernumber);
        strcpy(current->winnumber, lottery.winnumber);
        current->draw = lottery.draw;
        current->win = lottery.win;
        strcpy(current->buydate, lottery.buydate);
        strcpy(current->windate, lottery.windate);
        current->next = NULL;
    }
    fclose(file_read);
    current = head;
    while (current != NULL)
    {
        InwinDate(current);
        current->draw = 1;
        strcpy(current->winnumber, randomStr);
        Prize(current, randomNum, 12);
        current = current->next;
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
    current = head;
    while (current != NULL)
    {
        fprintf(file_write, "彩票id：%s  购买用户：%s  期号：%s  彩票类型：%d  用户号码：%s  中奖号码：%s  是否开奖：%d  是否中奖：%d  购买日期：%s  开奖日期：%s\n",
                current->tid, current->uid, current->did, current->category, current->usernumber, current->winnumber,
                current->draw, current->win, current->buydate, current->windate);
        current = current->next;
    }
    fclose(file_write);
    current = head;
    while (current != NULL)
    {
        Lottery *toFree = current;
        current = current->next;
        free(toFree);
    }
    head = NULL;
    printf("============================\n");
    printf("|  开奖结束！            |\n");
    printf("============================\n");
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
    snprintf(randomStr, sizeof(randomStr), "%02d-%02d-%02d-%02d-%02d:%02d", randomNum[0], randomNum[1], randomNum[2], randomNum[3], randomNum[4], randomNum[5]);
    Lottery *head = NULL;
    Lottery lottery = {0};
    Lottery *current = (Lottery *)malloc(sizeof(Lottery));
    if (current == NULL)
    {
        printf("============================\n");
        printf("|  内存分配失败！          |\n");
        printf("============================\n");
        return;
    }
    current->next = NULL;
    FILE *file_read = fopen("lottery3.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "彩票id：%s  购买用户：%s  期号：%s  彩票类型：%d  用户号码：%s  中奖号码：%s  是否开奖：%d  是否中奖：%d  购买日期：%s  开奖日期：%s\n",
                  lottery.tid, lottery.uid, lottery.did, &lottery.category, lottery.usernumber, lottery.winnumber,
                  &lottery.draw, &lottery.win, lottery.buydate, lottery.windate) != EOF)
    {
        if (head == NULL)
        {
            head = current;
        }
        else
        {
            current->next = (Lottery *)malloc(sizeof(Lottery));
            if (current == NULL)
            {
                printf("============================\n");
                printf("|  内存分配失败！          |\n");
                printf("============================\n");
                return;
            }
            current = current->next;
        }
        strcpy(current->tid, lottery.tid);
        strcpy(current->uid, lottery.uid);
        strcpy(current->did, lottery.did);
        current->category = lottery.category;
        strcpy(current->usernumber, lottery.usernumber);
        strcpy(current->winnumber, lottery.winnumber);
        current->draw = lottery.draw;
        current->win = lottery.win;
        strcpy(current->buydate, lottery.buydate);
        strcpy(current->windate, lottery.windate);
        current->next = NULL;
    }
    fclose(file_read);
    current = head;
    while (current != NULL)
    {
        InwinDate(current);
        current->draw = 1;
        strcpy(current->winnumber, randomStr);
        Prize(current, randomNum, 12);
        current = current->next;
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
    current = head;
    while (current != NULL)
    {
        fprintf(file_write, "彩票id：%s  购买用户：%s  期号：%s  彩票类型：%d  用户号码：%s  中奖号码：%s  是否开奖：%d  是否中奖：%d  购买日期：%s  开奖日期：%s\n",
                current->tid, current->uid, current->did, current->category, current->usernumber, current->winnumber,
                current->draw, current->win, current->buydate, current->windate);
        current = current->next;
    }
    fclose(file_write);
    current = head;
    while (current != NULL)
    {
        Lottery *toFree = current;
        current = current->next;
        free(toFree);
    }
    head = NULL;
    printf("============================\n");
    printf("|  开奖结束！            |\n");
    printf("============================\n");
}
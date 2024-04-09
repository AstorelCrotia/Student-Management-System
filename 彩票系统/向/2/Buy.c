#include "head.h"

void Buy(int *sc, char *id) // 购买彩票
{
    Lottery lottery = {0};
    char T1[25] = "bbg";
    char T2[25] = "00A";
    char T3[25] = "00B";
    printf("====================================\n");
    printf("|  请选择你要购买的彩票！         |\n");
    printf("|                                |\n");
    printf("|  bbg彩(30元)输入“1”            |\n");
    printf("|                                |\n");
    printf("|  A彩(20元)输入“2”              |\n");
    printf("|                                |\n");
    printf("|  B彩(10元)输入“3”              |\n");
    printf("|                                |\n");
    printf("|  退出系统输入其他              |\n");
    printf("====================================\n");
    printf("你的输入：");
    scanf("%d", sc);
    switch (*sc)
    {
    case 1:
        strcat(T1, id);
        buyModify(id, 30, sc);
        if (*sc == 0)
        {
            return;
        }
        strcpy(lottery.tid, T1);
        Buyin(&lottery, id, 1);
        break;
    case 2:
        strcat(T2, id);
        buyModify(id, 20, sc);
        if (*sc == 0)
        {
            return;
        }
        strcpy(lottery.tid, T2);
        Buyin(&lottery, id, 2);
        break;
    case 3:
        strcat(T3, id);
        buyModify(id, 10, sc);
        if (*sc == 0)
        {
            return;
        }
        strcpy(lottery.tid, T3);
        Buyin(&lottery, id, 3);
        break;
    default:
        break;
    }
}

void Buyin(Lottery *lottery, char *id, int sc) // 购买写入
{
    int Num[6] = {0};
    strcpy(lottery->uid, id);
    lottery->category = sc;
    for (int i = 0; i < 6; i++)
    {
        printf("====================================\n");
        printf("接收范围0~99，个位数自动补0。");
        printf("请输入你选择的第%d位号码：", i + 1);
        scanf("%2d", &Num[i]);
        while (getchar() != '\n')
            ;
    }
    snprintf(lottery->usernumber, sizeof(lottery->usernumber), "%02d-%02d-%02d-%02d-%02d:%02d", Num[0], Num[1], Num[2], Num[3], Num[4], Num[5]);
    lottery->draw = 0;
    lottery->win = 0;
    strcpy(lottery->winnumber, "none");
    strcpy(lottery->windate, "none");
    if (sc == 1)
    {
        Lottery oldlottery = {0};
        FILE *file_read = fopen("lottery1.txt", "r");
        if (file_read == NULL)
        {
            printf("============================\n");
            printf("|  连接服务器失败！        |\n");
            printf("============================\n");
            return;
        }
        fscanf(file_read, "彩票id：%s  购买用户：%s  期号：%s  彩票类型：%d  用户号码：%s  中奖号码：%s  是否开奖：%d  是否中奖：%d  购买日期：%s  开奖日期：%s\n",
               oldlottery.tid, oldlottery.uid, oldlottery.did, &oldlottery.category, oldlottery.usernumber, oldlottery.winnumber,
               &oldlottery.draw, &oldlottery.win, oldlottery.buydate, oldlottery.windate);
        fclose(file_read);
        FILE *file_write = fopen("lottery1.txt", "a");
        if (file_write == NULL)
        {
            printf("============================\n");
            printf("|  连接服务器失败！        |\n");
            printf("============================\n");
            return;
        }
        InbuyDate(lottery);
        didDate(lottery, &oldlottery);
        revenue(30, lottery);
        fprintf(file_write, "彩票id：%s  购买用户：%s  期号：%s  彩票类型：%d  用户号码：%s  中奖号码：%s  是否开奖：%d  是否中奖：%d  购买日期：%s  开奖日期：%s\n",
                lottery->tid, lottery->uid, lottery->did, lottery->category, lottery->usernumber, lottery->winnumber,
                lottery->draw, lottery->win, lottery->buydate, lottery->windate);
        fclose(file_write);
        printf("====================================\n");
        printf("|  购买成功！                     |\n");
        printf("|                                |\n");
        printf("|  购买的期号为：%s               |\n", lottery->did);
        printf("|                                |\n");
        printf("|  购买的号码为：%s               |\n", lottery->usernumber);
        printf("====================================\n");
    }
    else if (sc == 2)
    {
        Lottery oldlottery = {0};
        FILE *file_read = fopen("lottery2.txt", "r");
        if (file_read == NULL)
        {
            printf("============================\n");
            printf("|  连接服务器失败！        |\n");
            printf("============================\n");
            return;
        }
        fscanf(file_read, "彩票id：%s  购买用户：%s  期号：%s  彩票类型：%d  用户号码：%s  中奖号码：%s  是否开奖：%d  是否中奖：%d  购买日期：%s  开奖日期：%s\n",
               oldlottery.tid, oldlottery.uid, oldlottery.did, &oldlottery.category, oldlottery.usernumber, oldlottery.winnumber,
               &oldlottery.draw, &oldlottery.win, oldlottery.buydate, oldlottery.windate);
        fclose(file_read);
        FILE *file_write = fopen("lottery2.txt", "a");
        if (file_write == NULL)
        {
            printf("============================\n");
            printf("|  连接服务器失败！        |\n");
            printf("============================\n");
            return;
        }
        InbuyDate(lottery);
        didDate(lottery, &oldlottery);
        revenue(20, lottery);
        fprintf(file_write, "彩票id：%s  购买用户：%s  期号：%s  彩票类型：%d  用户号码：%s  中奖号码：%s  是否开奖：%d  是否中奖：%d  购买日期：%s  开奖日期：%s\n",
                lottery->tid, lottery->uid, lottery->did, lottery->category, lottery->usernumber, lottery->winnumber, lottery->draw, lottery->win, lottery->buydate, lottery->windate);
        fclose(file_write);
        printf("====================================\n");
        printf("|  购买成功！                     |\n");
        printf("|                                |\n");
        printf("|  购买的期号为：%s               |\n", lottery->did);
        printf("|                                |\n");
        printf("|  购买的号码为：%s               |\n", lottery->usernumber);
        printf("====================================\n");
    }
    else
    {
        Lottery oldlottery = {0};
        FILE *file_read = fopen("lottery3.txt", "r");
        if (file_read == NULL)
        {
            printf("============================\n");
            printf("|  连接服务器失败！        |\n");
            printf("============================\n");
            return;
        }
        fscanf(file_read, "彩票id：%s  购买用户：%s  期号：%s  彩票类型：%d  用户号码：%s  中奖号码：%s  是否开奖：%d  是否中奖：%d  购买日期：%s  开奖日期：%s\n",
               oldlottery.tid, oldlottery.uid, oldlottery.did, &oldlottery.category, oldlottery.usernumber, oldlottery.winnumber,
               &oldlottery.draw, &oldlottery.win, oldlottery.buydate, oldlottery.windate);
        fclose(file_read);
        FILE *file_write = fopen("lottery3.txt", "a");
        if (file_write == NULL)
        {
            printf("============================\n");
            printf("|  连接服务器失败！        |\n");
            printf("============================\n");
            return;
        }
        InbuyDate(lottery);
        didDate(lottery, &oldlottery);
        revenue(10, lottery);
        fprintf(file_write, "彩票id：%s  购买用户：%s  期号：%s  彩票类型：%d  用户号码：%s  中奖号码：%s  是否开奖：%d  是否中奖：%d  购买日期：%s  开奖日期：%s\n",
                lottery->tid, lottery->uid, lottery->did, lottery->category, lottery->usernumber, lottery->winnumber, lottery->draw, lottery->win, lottery->buydate, lottery->windate);
        fclose(file_write);
        printf("====================================\n");
        printf("|  购买成功！                     |\n");
        printf("|                                |\n");
        printf("|  购买的期号为：%s               |\n", lottery->did);
        printf("|                                |\n");
        printf("|  购买的号码为：%s               |\n", lottery->usernumber);
        printf("====================================\n");
    }
    return;
}
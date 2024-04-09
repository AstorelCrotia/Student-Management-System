#include "head.h"

void revenue(float money, Lottery *lottery) // 营收操作
{
    Revenue revenue = {0};
    FILE *file_write = fopen("revenue.txt", "a");
    if (file_write == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    strcpy(revenue.uid, lottery->uid);
    strcpy(revenue.buydate, lottery->buydate);
    revenue.category = lottery->category;
    revenue.money = money;
    fprintf(file_write, "发生用户：%s  发生时间：%s  彩票类型：%d  发生金额：%.2f\n",
            revenue.uid,revenue.buydate,revenue.category,revenue.money);
    fclose(file_write);
}
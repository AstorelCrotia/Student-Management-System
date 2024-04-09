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
    revenue.buydate = lottery->buydate;
    revenue.category = lottery->category;
    revenue.money = money;
    fwrite(&revenue, sizeof(Revenue), 1, file_write);
    fclose(file_write);
}
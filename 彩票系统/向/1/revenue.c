#include "head.h"

void revenue(float money, Lottery *lottery) // Ӫ�ղ���
{
    Revenue revenue = {0};
    FILE *file_write = fopen("revenue.txt", "a");
    if (file_write == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
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
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
    strcpy(revenue.buydate, lottery->buydate);
    revenue.category = lottery->category;
    revenue.money = money;
    fprintf(file_write, "�����û���%s  ����ʱ�䣺%s  ��Ʊ���ͣ�%d  ������%.2f\n",
            revenue.uid,revenue.buydate,revenue.category,revenue.money);
    fclose(file_write);
}
#include "head.h"

void Buy(int *sc, char *id) // �����Ʊ
{
    Lottery lottery = {0};
    char T1[25] = "bbg";
    char T2[25] = "00A";
    char T3[25] = "00B";
    int Num[6] = {0};
    printf("====================================\n");
    printf("|  ��ѡ����Ҫ����Ĳ�Ʊ��         |\n");
    printf("|                                |\n");
    printf("|  bbg��(30Ԫ)���롰1��            |\n");
    printf("|                                |\n");
    printf("|  A��(20Ԫ)���롰2��              |\n");
    printf("|                                |\n");
    printf("|  B��(10Ԫ)���롰3��              |\n");
    printf("|                                |\n");
    printf("|  �˳�ϵͳ��������              |\n");
    printf("====================================\n");
    printf("������룺");
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
        break;
    case 2:
        strcat(T2, id);
        buyModify(id, 20, sc);
        if (*sc == 0)
        {
            return;
        }
        strcpy(lottery.tid, T2);
        break;
    case 3:
        strcat(T3, id);
        buyModify(id, 10, sc);
        if (*sc == 0)
        {
            return;
        }
        strcpy(lottery.tid, T3);
        break;
    default:
        break;
    }
    if (*sc == 1 || *sc == 2 || *sc == 3)
    {
        strcpy(lottery.uid, id);
        lottery.category = *sc;
        for (int i = 0; i < 6; i++)
        {
            printf("====================================\n");
            printf("��������ѡ��ĵ�%dλ����(���շ�Χ0~99)��", i + 1);
            scanf("%2d", &Num[i]);
            while (getchar() != '\n')
                ;
        }
        snprintf(lottery.number, sizeof(lottery.number), "%02d %02d %02d %02d %02d : %02d", Num[0], Num[1], Num[2], Num[3], Num[4], Num[5]);
        lottery.draw = 0;
        lottery.win = 0;
        FILE *file_write = fopen("lottery.txt", "a");
        if (file_write == NULL)
        {
            printf("============================\n");
            printf("|  ���ӷ�����ʧ�ܣ�        |\n");
            printf("============================\n");
            return;
        }
        InbuyDate(&lottery);
        fwrite(&lottery, sizeof(Lottery), 1, file_write);
        fclose(file_write);
        return;
    }
}

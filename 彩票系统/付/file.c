#include "head.h"

void w_wininformation_file(struct news temp)
{
    FILE *fp1;
    if ((fp1 = fopen("wininformation.txt", "at")) == NULL)
    {
        printf("无法操作文件，任意键退出!\n");
        getchar();
        exit(1);
    }
    fprintf(fp1, "%d期  鼠：%d  猫：%d  狗：%d  总额：%d  %d年%d月%d日%d时%d分%d秒\n", temp.dayth, temp.mouse_ticket, temp.cat_ticket, temp.dog_ticket, temp.sum, temp.year, temp.month, temp.day, temp.hour, temp.min, temp.sec);
    fclose(fp1);
}

void r_wininformation_file()
{
    struct news temp;
    FILE *fp1;
    if ((fp1 = fopen("wininformation.txt", "rt")) == NULL)
    {
        printf("读取文件失败！任意键退出！\n");
        getchar();
        exit(1);
    }
    printf("各期彩票信息：\n");
    while (!feof(fp1))
    {
        fscanf(fp1, "%d期  鼠：%d  猫：%d  狗：%d  总额：%d  %d年%d月%d日%d时%d分%d秒\n", &temp.dayth, &temp.mouse_ticket, &temp.cat_ticket, &temp.dog_ticket, &temp.sum, &temp.year, &temp.month, &temp.day, &temp.hour, &temp.min, &temp.sec);
        printf("%d期  鼠：%d  猫：%d  狗：%d  总额：%d  %d年%d月%d日%d时%d分%d秒\n", temp.dayth, temp.mouse_ticket, temp.cat_ticket, temp.dog_ticket, temp.sum, temp.year, temp.month, temp.day, temp.hour, temp.min, temp.sec);
    }
    fclose(fp1);
}

void w_winer_file(struct buy_ticket *temp)
{
    FILE *fp = fopen("winer.txt", "at");
    if (fp == NULL)
    {
        printf("文件读取失败!任意键退出！\n");
        getchar();
        exit(1);
    }

    fprintf(fp, "ID：%d\t姓名：%s\t期号：%d\t类型：%d\t号码：%d\t数量：%d\t中奖金额：%d\n", &temp->person_id, temp->person_name, &temp->ticket_dayth, &temp->ticket_type, &temp->ticket_number, &temp->ticket_amount, &temp->ticket_winmoney);
    fclose(fp);
}

void r_winner_file()
{
    struct buy_ticket *temp = NULL;
    temp = (struct buy_ticket *)malloc(sizeof(struct buy_ticket));
    FILE *fp1;
    if ((fp1 = fopen("winer.txt", "rt")) == NULL)
    {
        printf("文件读取失败!任意键退出！\n");
        getchar();
        exit(0);
    }
    printf("各期中奖人信息\n");
    while (!feof(fp1))
    {
        fscanf(fp1,"ID：%d\t姓名：%s\t期号：%d\t类型：%d\t号码：%d\t数量：%d\t中奖金额：%d\n", &temp->person_id, temp->person_name, &temp->ticket_dayth, &temp->ticket_type, &temp->ticket_number, &temp->ticket_amount, &temp->ticket_winmoney);
        printf("ID：%d\t姓名：%s\t期号：%d\t类型：%d\t号码：%d\t数量：%d\t中奖金额：%d\n", temp->person_id, temp->person_name, temp->ticket_dayth, temp->ticket_type, temp->ticket_number, temp->ticket_amount, temp->ticket_winmoney);
    }
    fclose(fp1);
}
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
        fscanf(fp1, "ID：%d\t姓名：%s\t期号：%d\t类型：%d\t号码：%d\t数量：%d\t中奖金额：%d\n", &temp->person_id, temp->person_name, &temp->ticket_dayth, &temp->ticket_type, &temp->ticket_number, &temp->ticket_amount, &temp->ticket_winmoney);
        printf("ID：%d\t姓名：%s\t期号：%d\t类型：%d\t号码：%d\t数量：%d\t中奖金额：%d\n", temp->person_id, temp->person_name, temp->ticket_dayth, temp->ticket_type, temp->ticket_number, temp->ticket_amount, temp->ticket_winmoney);
    }
    fclose(fp1);
}

struct Person *person_creat_head(struct Person *h)
{
    struct Person *newuser = NULL;
    newuser = (struct Person *)malloc(sizeof(struct Person));
    if (newuser == NULL)
    {
        printf("分配空间错误！\n");
        exit(0);
    }
    newuser->id = 0;
    newuser->balance = admin_init_money;
    strcpy(newuser->password, "admin");
    strcpy(newuser->name, "admin");
    newuser->next = NULL;
    return newuser;
}

void w_user_file(struct Person *h)
{
    FILE *fp1;
    if ((fp1 = fopen("user.txt", "wt")) == NULL)
    {
        printf("打开文件错误！任意键退出...\n");
        getchar();
        exit(1);
    }
    fprintf(fp1, "ID：%d\t姓名：%s\t密码：%s\t余额：%d\n", h->id, h->name, h->password, h->balance);
    while (h->next != NULL)
    {
        fprintf(fp1, "ID：%d\t姓名：%s\t密码：%s\t余额：%d\n", h->next->id, h->next->name, h->next->password, h->next->balance);
        h = h->next;
    }
    fclose(fp1);
}

struct Person *r_user_file(struct Person *h)
{
    struct Person *newperson = NULL;
    struct Person *p = h, *temp = NULL;

    FILE *fp;
    if ((fp = fopen("user.txt", "rt")) == NULL)
    {
        printf("文件读取失败！任意键退出...");
        getchar();
        exit(1);
    }
    fscanf(fp, "ID：%d\t姓名：%s\t密码：%s\t余额：%d\n", &h->id, h->name, h->password, &h->balance);
    while (!feof(fp))
    {
        newperson = (struct Person *)malloc(sizeof(struct Person));
        if (newperson == NULL)
        {
            printf("分配空间错误！\n");
            exit(0);
        }
        newperson->next = NULL;
        fscanf(fp, "ID：%d\t姓名：%s\t密码：%s\t余额：%d\n", &newperson->id, newperson->name, newperson->password, &newperson->balance);
        p->next = newperson;
        temp = p;
        p = newperson;
        len_user++;
    }
    fclose(fp);
    temp->next = NULL;
    free(p);
    len = temp->id;
    return temp;
}

void w_buy_file(struct buy_ticket *buy_h)
{
    FILE *fp1;
    if ((fp1 = fopen("buy.txt", "wt")) == NULL)
    {
        printf("打开文件失败！任意键退出...\n");
        getchar();
        exit(1);
    }
    fprintf(fp1, "鼠：%d\t猫：\t%d狗：\t%d可买期号：%d\n", buy_h->mouse_ID, buy_h->cat_ID, buy_h->dog_ID, buy_h->ticket_dayth);
    while (buy_h->next != NULL)
    {
        fprintf(fp1, "ID：%d\t姓名：%s\t期号：%d\t类型：%d\t号码：%d\t数量：%d\t中奖金额：%d\n", buy_h->person_id, buy_h->person_name, buy_h->ticket_dayth, buy_h->ticket_type, buy_h->ticket_number, buy_h->ticket_amount, buy_h->ticket_winmoney);
        buy_h = buy_h->next;
    }
    fclose(fp1);
}

struct buy_ticket *r_buy_file(struct buy_ticket *buy_h)
{
    struct buy_ticket *newuser = NULL;
    struct buy_ticket *buy_p = buy_h, *temp = NULL;

    FILE *fp;
    if ((fp = fopen("buy.txt", "rt")) == NULL)
    {
        printf("文件打开失败！任意键退出...\n");
        getchar();
        exit(1);
    }
    fscanf(fp, "鼠：%d\t猫：\t%d狗：\t%d可买期号：%d\n", &buy_h->mouse_ID, &buy_h->cat_ID, &buy_h->dog_ID, &buy_h->ticket_dayth);
    while (!feof(fp))
    {
        newuser = (struct buy_ticket *)malloc(sizeof(struct buy_ticket));
        if (newuser == NULL)
        {
            printf("打开文件失败！\n");
            exit(0);
        }
        newuser->next = NULL;
        fscanf(fp, "ID：%d\t姓名：%s\t期号：%d\t类型：%d\t号码：%d\t数量：%d\t中奖金额：%d\n", &newuser->person_id, newuser->person_name, &newuser->ticket_dayth, &newuser->ticket_type, &newuser->ticket_number, &newuser->ticket_amount, &newuser->ticket_winmoney);
        buy_p->next = newuser;
        temp = buy_p;
        buy_p = newuser;
        len_buy++;
    }
    fclose(fp);
    return buy_p;
}

void w_visit_file(int visit)
{
	FILE *fp1;
	if((fp1 = fopen("visit.txt","wt")) == NULL)
	{
		printf("打开文件失败！任意键退出...\n");
		getchar();
		exit(1);
	}
	fprintf(fp1,"%d",visit);
	fclose(fp1);
}

int r_visit_file()
{
    int visit;
    FILE *fp1;
    if((fp1 = fopen("visit.txt","rt")) == NULL)
	{
		printf("打开文件失败！任意键退出...\n");
		getchar();
		exit(1);
	}
	fscanf(fp1,"%d",&visit);
	fclose(fp1);
	return visit;
}

struct buy_ticket * buy_creat_head(struct buy_ticket *buy_h)
{
	struct buy_ticket *newuser=NULL;
	newuser = (struct buy_ticket *)malloc(sizeof(struct buy_ticket));
	if(newuser == NULL)
	{
		printf("产生头节点时空间分配错误！\n");
		exit(0);
	}
	newuser->mouse_ID = 0;			
	newuser->cat_ID = 0;		
	newuser->dog_ID = 0;		
	newuser->ticket_dayth = 1201;	//初始化为1201
	newuser->ticket_winmoney = 0;	//初始中奖为0
	newuser->next = NULL;
	return newuser;
}
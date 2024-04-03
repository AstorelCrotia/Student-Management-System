#include "head.h"

void w_wininformation_file(struct news temp)
{
    FILE *fp1;
    if ((fp1 = fopen("wininformation.txt", "at")) == NULL)
    {
        printf("无法操作文件，任意键退出...\n");
        getchar();
        exit(1);
    }
    fprintf(fp1, "%d期  鼠：%d  猫：%d  狗：%d  总金额:%d  %d年%d月%d日%d时%d分%d秒\n", temp.dayth, temp.mouse_ticket, temp.cat_ticket, temp.dog_ticket, temp.sum, temp.year, temp.month, temp.day, temp.hour, temp.min, temp.sec);
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
        fscanf(fp1, "%d期  鼠：%d  猫：%d  狗：%d  总金额:%d  %d年%d月%d日%d时%d分%d秒\n", &temp.dayth, &temp.mouse_ticket, &temp.cat_ticket, &temp.dog_ticket, &temp.sum, &temp.year, &temp.month, &temp.day, &temp.hour, &temp.min, &temp.sec);
        printf("%d期  鼠：%d  猫：%d  狗：%d  总金额:%d  %d年%d月%d日%d时%d分%d秒\n", temp.dayth, temp.mouse_ticket, temp.cat_ticket, temp.dog_ticket, temp.sum, temp.year, temp.month, temp.day, temp.hour, temp.min, temp.sec);
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
    fprintf(fp, "%d %s %d %d %d %d %d \n",
            temp->person_id,
            temp->person_name,
            temp->ticket_dayth,
            temp->ticket_type,
            temp->ticket_number,
            temp->ticket_amount,
            temp->ticket_winmoney);
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
    printf("\t\tID\t姓名\t期号\t类型\t\t号码\t数量\t中奖金额\n");
    while (!feof(fp1))
    {
        fscanf(fp1, "\t\t%d %s %d %d %d %d %d\n",
               &temp->person_id,
               temp->person_name,
               &temp->ticket_dayth,
               &temp->ticket_type,
               &temp->ticket_number,
               &temp->ticket_amount,
               &temp->ticket_winmoney);
        printf("\t\t%d\t%s\t%d",
               temp->person_id,
               temp->person_name,
               temp->ticket_dayth);
        if (temp->ticket_type == mouse_ticket)
            printf("\t鼠鼠彩票");
        else if (temp->ticket_type == cat_ticket)
            printf("\t猫猫彩票");
        else
            printf("\t狗狗彩票");
        printf("\t%d\t%d\t%d\n", temp->ticket_number, temp->ticket_amount, temp->ticket_winmoney);
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
    fprintf(fp1,"%d %s %s %d\n",
				h->id, 
				h->name, 
				h->password, 
				h->balance);
	while(h->next != NULL)
	{
		fprintf(fp1,"%d %s %s %d\n",
				h->next->id, 
				h->next->name, 
				h->next->password, 
				h->next->balance);
		h = h->next;
	}
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
    fscanf(fp,"%d %s %s %d",
				&h->id, 
				h->name, 
				h->password, 
				&h->balance);
	while(!feof(fp))
	{					
		newperson = (struct Person *)malloc(sizeof(struct Person));
		if(newperson == NULL)
		{
			printf("产生新节点时空间非配错误！\n");
			exit(0);
		}
		newperson->next = NULL;
		fscanf(fp,"%d %s %s %d",
				&newperson->id, 
				newperson->name, 
				newperson->password, 
				&newperson->balance);
		p->next = newperson;
		temp = p;
		p = newperson;
		len_user++;		//用户数加一
	}
	fclose(fp);
	temp->next = NULL;	//最有一个读出有问题，将最后一个节点释放
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
    fprintf(fp1,"%d %d %d %d\n",
					buy_h->person_id,		
					buy_h->ticket_number,	
					buy_h->ticket_amount,	
					buy_h->ticket_dayth		
				);
	while(buy_h->next != NULL)
	{
		fprintf(fp1,"%d %s %d %d %d %d %d %d %d\n",
										buy_h->next->person_id,
										buy_h->next->person_name,
										buy_h->next->ticket_dayth,
										buy_h->next->ticket_type,
										buy_h->next->ticket_number,
										buy_h->next->ticket_amount,
										buy_h->next->ticket_status,
										buy_h->next->ticket_win,
										buy_h->next->ticket_sum);
		buy_h = buy_h->next;
	}
    fclose(fp1);
}

struct buy_ticket *r_buy_file(struct buy_ticket *buy_h)
{
    struct buy_ticket *newuser = NULL;
    struct buy_ticket *buy_p = buy_h;

    FILE *fp;
    if ((fp = fopen("buy.txt", "rt")) == NULL)
    {
        printf("文件打开失败！任意键退出...\n");
        getchar();
        exit(1);
    }
   fscanf(fp,"%d %d %d %d\n",
				&buy_h->person_id,		
				&buy_h->ticket_number,	
				&buy_h->ticket_amount,	
				&buy_h->ticket_dayth	
			);
	while(!feof(fp))
	{					
		newuser = (struct buy_ticket *)malloc(sizeof(struct buy_ticket));
		if(newuser == NULL)
		{
			printf("产生新节点时空间非配错误！\n");
			exit(0);
		}
		newuser->next = NULL;
		fscanf(fp,"%d %s %d %d %d %d %d %d %d\n",
										&newuser->person_id,
										newuser->person_name,
										&newuser->ticket_dayth,
										&newuser->ticket_type,
										&newuser->ticket_number,
										&newuser->ticket_amount,
										&newuser->ticket_status,
										&newuser->ticket_win,
										&newuser->ticket_sum);
		buy_p->next = newuser;
		buy_p = newuser;
		len_buy++;				//购票信息个数加1
	}
	fclose(fp);
    return buy_p;
}

void w_visit_file(int visit)
{
    FILE *fp1;
    if ((fp1 = fopen("visit.txt", "wt")) == NULL)
    {
        printf("打开文件失败！任意键退出...\n");
        getchar();
        exit(1);
    }
    fprintf(fp1, "%d", visit);
    fclose(fp1);
}

int r_visit_file()
{
    int visit;
    FILE *fp1;
    if ((fp1 = fopen("visit.txt", "rt")) == NULL)
    {
        printf("打开文件失败！任意键退出...\n");
        getchar();
        exit(1);
    }
    fscanf(fp1, "%d", &visit);
    fclose(fp1);
    return visit;
}

struct buy_ticket *buy_creat_head(struct buy_ticket *buy_h)
{
    struct buy_ticket *newuser = NULL;
    newuser = (struct buy_ticket *)malloc(sizeof(struct buy_ticket));
    if (newuser == NULL)
    {
        printf("产生头节点时空间分配错误！\n");
        exit(0);
    }
    newuser->person_id = 0;
    newuser->ticket_number = 0;
    newuser->ticket_sum = 0;
    newuser->ticket_dayth = 1201; 
    newuser->ticket_winmoney = 0; 
    newuser->next = NULL;
    return newuser;
}
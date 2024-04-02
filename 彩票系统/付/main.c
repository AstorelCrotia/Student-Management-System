#include "head.h"
#include <time.h>

int main()
{
    len = 0;
    len_buy = 0;
    len_user = 0;

    struct Person *p = NULL, *h = NULL;
    FILE *fp;
    h = person_creat_head(h);
    if ((fp = fopen("user.txt", "rt")) == NULL)
    {
        p = h;
    }
    else
    {
        fclose(fp);
        p = r_user_file(h);
    }

    struct buy_ticket *buy_h=NULL,*buy_p=NULL;
    buy_h=buy_creat_head(buy_h);
    buy_p=buy_h;
    if((fp=fopen("buy.txt","rt"))==NULL)
    {
        buy_p=buy_h;
    }
    else
    {
        fclose(fp);
        buy_p=r_buy_file(buy_h);
    }

    int visit;
    if((fp=fopen("buy.txt","rt"))==NULL)
    {
        visit =0;
    }
    else
    {
        fclose(fp);
        visit = r_visit_file();
    }
    visit++;
    w_visit_file(visit);
    printf("*********欢迎来到一夜暴富动物彩票机*********\n");
    printf("******欢迎光临，您是今天第%d位访客**********\n");
    time_t start,end;
    double dif;
    time(&start);
    while(dif<5)
    {
        time(&end);
        dif=difftime(end,start);
    }
    while(1)
	{
		ticketdayth = buy_h->ticket_dayth;	//头节点的dayth保存期号，彩民可以购买的期号
		printf("1、管理员登录\t2、彩民登陆\t3、用户注册\t4、退出系统\n");
		scanf("%d",&choice);
		getchar();							//防止输入字符时进入死循环
		switch(choice)
		{
			case 0:							
					if(save_flag ==1)
					{
						printf("信息更改，是否保存到文件！y/n\n");
						if(getchar() == 'y')
						{
							w_user_file(h);		
						}

					}
						w_buy_file(buy_h);		
						printf("欢迎购买！祝您洪福齐天！\n");				
					exit(0);
				break;
			case 1:								
					admin_signin(h,buy_h);							
				break;
			case 2:								
					buy_p = signin(h,buy_p,buy_h);	
				break;
			case 3:								
					p = signup(h,p);
				break;	
			default:
				printf("选择无效！任意键返回菜单！\n");
				getchar();
				break;
		}
		choice = 9;						//跳入输入有误，如果用户没输数字，会进入default
	}
    return 0;
}
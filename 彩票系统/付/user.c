#include<stdlib.h>
#include"head.h"

struct person * add_user(struct person *H,struct person *p)
{
	char passwd1[8],passwd2[8];
	char name[20];
	int i=0,flag = 1;			//用户名是否存在1,存在
	struct person *newnode=NULL;
	while(1)
    {
		printf("请输入姓名(不准包含数字)：");
		scanf("%s",name);
		flag = check_username(H,name);
		if(flag == 0)			//0，用户名不存在
			{
				i = 0;
				break;
			}

		else
			{
				printf("\n用户名已存在！");
				i++;
				if(i == 3)		//限定输入次数
				{
					key_error();
					printf("\n输入超过3次！任意键返回主菜单！ \n");
					getchar();
					getchar();
					break;
				}
			}
	}
	if(!flag)
	{
		while(1)
		{
		    printf("请输入密码:");
            GetPasscode(passwd1);
            printf("\n请再次输入密码:");
            GetPasscode(passwd2);	
			i++;
			if(i == 3)			//限定输入次数
			{
				printf("\n输入超过3次！任意键返回主菜单！ \n");
				getchar();
				getchar();
				break;
			}

			if(strcmp(passwd1,passwd2) == 0)
			{
				break;			//密码正确则退出
			}
			else
				printf("两次密码输入不匹配！请重新设置密码！\n");	
		}
		if(i!=3)				//注册成功
		{
			len++;
			len_user++;
			//注册成功在申请结点
			save_flag = 1;		//信息更新提示
			newnode = (struct person *)malloc(sizeof(struct person));
				if(newnode == NULL)
				{
					printf("产生头节点时空间非配错误！\n");
					exit(0);
				}
				newnode->next = NULL;
			newnode->id = len;
			strcpy(newnode->passwd,passwd1);			//密码
			strcpy(newnode->name,name);					//姓名
			newnode->person_money = user_init_money;	//初始金额
			apply_success();							//注册成功提示在菜单
			printf("*********************************\n");
			printf("************注册成功！************");
			printf("*******恭喜！%s (先生/女士)*******",newnode->name);
			printf("*********系统将赠送您%d元*********",user_init_money);
			printf("*********************************\n\n");
			printf("任意键返回...");
			getchar();
			getchar();
			p->next = newnode;
			p = newnode;
		}
	}
	return p;
}

struct buy_ticket * person_menu2(struct person *H,struct buy_ticket *buy_p,struct buy_ticket *buy_H)
{
	char name_test[20];				//用户登录暂存
	char passwd_test[8];			//用户密码暂存
    char passwd_test2[8];
	struct person *p = H;
	int i = 0;
	while(1)
	{
		printf("请输入用户名：");
		scanf("%s",name_test);
        printf("请输入密码：");
        scanf("%s",passwd_test2);
		strcpy(passwd_test, passwd_test2);	
		while(p->next !=NULL)
		{
			if(strcmp(p->next->name,name_test) == 0 && strcmp(p->next->passwd,passwd_test) == 0)
			{
				break;
			}
			p = p->next;
		}
		if(p->next ==NULL)			//用户名或密码错误
		{
			i++;
			if(i>=3)				//错误3次以上，退出
			{
				key_error();
				printf("\n错误次数超过3次！任意键返回主菜单！\n");
				getchar();
				getchar();
				break;
			}
			printf("用户名或密码错误！请重新输入：\n");
		}
		else
		{
			i =0;
			break;
		}
		p = H;						//p指向头节点
	}
	if(i == 0)
	{
		while(menu_select != 0)		//menu_select==0 ,则退出当前菜单
		{
			menu2();
			scanf("%d",&menu_select);
			getchar();				//防止输入字符时进入死循环
			switch(menu_select)
			{
				case 0:				//返回主菜单
						menu_select = 0;
						return buy_p;
					break;
				case 1:				//购票
									//buy_p,最后一个购买信息，p->next当前用户节点,H,管理员信息
						buy_p = user_buy_tickey(buy_p,p->next,H);
					break;
				case 2:				//查看信息
						printf("您的个人信息为：");
						printf("id：%d\t姓名：%d\t密码：%d\t金额(元)：%d\n",p->next->id, p->next->name, p->next->passwd, p->next->person_money);
						user_view_ticket(p->next,buy_H);
						printf("任意键继续");
						getchar();
					break;
				case 3:				//修改信息
									//p->next,用户结点,p是上一节点
						userself_updata(H,p->next);	
					break;
				default:
					printf("选择有误！任意键返回菜单！\n");
					getchar();
					menu_select = 0;//主菜单入口参数
					break;	
			}
		}
	}
}
void user_view_ticket(struct person *p,struct buy_ticket *buy_H)
{
	struct buy_ticket *temp = buy_H;
	printf("\n上期中奖号码：");
	printf("体育彩票:%d\t慈善彩票:%dt救灾彩票:%d\t下期彩票：%d\n"temp->person_id,temp->ticket_number,temp->ticket_amount,temp->ticket_dayth);		
	printf("\n\t您的购票信息：");
	printf("\tID\t姓名\t期号\t  类型\t\t号码\t数量\t开奖状态  中奖情况  购票金额 \n");
	while(temp->next !=NULL)
	{
		if(temp->next->person_id == p->id)			//是本人的信息才显示
		{
			printf("\t%d\t%s\t%d",
						temp->next->person_id,
						temp->next->person_name,
						temp->next->ticket_dayth);
			if(temp->next->ticket_type == sport_ticket)
				printf("\t体育彩票");
			else if(temp->next->ticket_type == love_ticket)
				printf("\t慈善彩票");
			else
				printf("\t救灾彩票");
			printf("\t%d\t%d",
							temp->next->ticket_number,
							temp->next->ticket_amount);
			if(temp->next->ticket_status)
					printf("\t未开奖");
			else
					printf("\t已开奖");
			if(temp->next->ticket_win)
				printf("    中  奖");
			else
				printf("    未中奖");
			printf("\t%d\n",temp->next->ticket_sum);
		}
		temp = temp->next;
	}
}
void userself_updata(struct person *H,struct person *p)
{
    char old_pass[8];
	char passwd_test[8];
	char passwd_test1[8];
	char admin_passwd[8];
	char name[20];
	int i = 0,flag = 1;				//用户名是否存在标志 1，存在

	while(menu_select !=0)
	{
		menu23();
		scanf("%d",&menu_select);
		getchar();					//防止输入字符时进入死循环
		switch(menu_select)
		{
			case 0:					//返回上一级
				break;
			case 1:					//修改姓名
					while(1)
					{
						printf("请输入新用户名：");
						scanf("%s",name);
						flag = check_username(H,name);	//用户名是否存在，1存在
						if(!flag)
						{
							getchar();
							printf("确认修改用户名 (y/n)?");
							if(getchar() == 'y')
							{
								save_flag = 1;			//信息更新提示
								strcpy(p->name,name);
								printf("修改成功！任意键返回！");
								getchar();
							}
							else
							{
								printf("已放弃修改！任意键返回！");
								getchar();
							}
							break;
						}
						else
						{
							printf("\n用户名已存在！（可以用%sA）\n",name);
							i++;
							if(i == 3)					//限定输入次数
							{
								printf("\n输入超过3次！任意键返回主菜单！ \n");
								getchar();
								getchar();
								break;
							}
						}	
					}
					i = 0;								//case2会用到
				break;
			case 2:										//修改密码
                    printf("请输入原密码：");
                    scanf("%s",old_pass);
					strcpy(admin_passwd,old_pass);	
					if(strcmp(admin_passwd,p->passwd) == 0)
					{
						while(1)
						{
							if(i>2)						//输入3次，则放弃更新
							{
								printf("错误次数超过3次！任意键返回");
								getchar();
								getchar();
								break;
							}	
							strcpy(passwd_test,getpass("请输入新密码："));	
							strcpy(passwd_test1,getpass("请再次输入密码："));				
							if(strcmp(passwd_test1,passwd_test)== 0)
							{
								save_flag = 1;			//信息已经更新
								strcpy(p->passwd,passwd_test1);
								printf("密码已更新！任意键返回！");
								getchar();
								break;
							}
							else
							{
								i++;
								printf("两次密码不匹配！请重新输入！\n");
							}
	
						}	
					}
					else
					{
						printf("密码错误！任意键返回！");
						getchar();
					}
				break;
			default:	
					menu_select = 0;
					printf("\n选择有误！任意键返回菜单！");
					getchar();			
				break;
		}
		if(menu_select == 0)
		{
			menu_select =2;					//上级菜单menu13入口参数为3
			break;							//退出while(),不退出会死循环
		}
	}
}

int check_username(struct person *H,char name[20])
{
	while(H->next != NULL)
	{
		if(strcmp(H->next->name,name)==0)
			return 1;	//有此用户名
		H = H->next;
	}
	return 0;			//无此用户名
}

struct buy_ticket * user_buy_tickey(struct buy_ticket *p,struct person *user,struct person *H)
{
	struct buy_ticket *newnode=NULL;
	while(menu_select !=0)		
	{
		newnode = (struct buy_ticket *)malloc(sizeof(struct buy_ticket));
		if(newnode == NULL)
		{
			printf("产生头节点时空间非配错误！\n");
			exit(0);
		}
		newnode->next = NULL;

		printf("您的账户余额为：%d元\n",user->person_money);
		if(user->person_money < ticket_value)		//余额不够买一张的话退出
		{
			printf("余额不足！任意键退出！");
			getchar();
			return p;
		}
		menu21();
		scanf("%d",&newnode->ticket_type); 			//选择票类型
		getchar();
		if(newnode->ticket_type == 0)				//0返回上一级
				return p;
		printf("请输入彩票号码（1-20）：");
		scanf("%d",&newnode->ticket_number);		//彩票号码
		printf("请输入够买数量：");					//彩票数量
		scanf("%d",&newnode->ticket_amount);
		newnode->person_id = user->id;				//id
		strcpy(newnode->person_name,user->name);	//姓名
		newnode->ticket_dayth = ticketdayth;		//期号
		newnode->ticket_status = 1;					//开奖状态为一，未开
		newnode->ticket_win = 0;					//1为中奖，0为未中奖
		newnode->ticket_sum = newnode->ticket_amount * ticket_value;//ticket_value为彩票单价
		if(newnode->ticket_sum > user->person_money)//余额不足
		{
			printf("账户余额不足，任意键返回！");
			getchar();
		}
		else					//购票成功
		{
			len_buy++;			//购票信息加1
			p->next = newnode;
			p = newnode;
			user->person_money =user->person_money - newnode->ticket_sum;		//余额减去花费
			H->person_money += newnode->ticket_sum;								//奖池金额增加
			
			/***********以下彩票画面*****************/				
			printf("\n**********购 票 成 功**********\n");
			printf("*********************************");
			if(newnode->ticket_type == sport_ticket)
				printf("\t\t*\t  %s\t\t*\n","sport_ticket");
			else if(newnode->ticket_type == love_ticket)
				printf("\t\t*\t  %s\t\t*\n","love_ticket");
			else
				printf("\t\t*\t  %s\t\t*\n","disastor_ticket");
			printf("彩票期号：%d 期\n",newnode->ticket_dayth);
			printf("彩票号码：%d \n",newnode->ticket_number);
			printf("彩票数量：%d 柱\\n",newnode->ticket_amount);
			printf("总 金 额：%d 元\n",newnode->ticket_sum);
			if(newnode->ticket_status)
			printf("开奖状态：未开奖\n");
			else
			{
				if(!newnode->ticket_win)	
				{
					printf("开奖状态：已开奖\n");
					printf("未中奖，下次好运！\n");
				}
				else
				{
					printf(" 开奖状态：已开奖\n");
					printf("恭喜你中奖了，金额为：%d\t\t*\n",newnode->ticket_amount*ticket_win_money);
				}			
				
			}
			printf("  任意键返回-->");
			getchar();
			getchar();
		}	
	}
	return p;
}

void w_user_file(struct person *H)
{
	FILE *fp1;
	if((fp1 = fopen("user.txt","wt")) == NULL)
	{
		printf("w_user_file无法创建文件user.txt--任意键退出!\n");
		getchar();
		exit(1);
	}
	fprintf(fp1,"%d %s %s %d\n",
				H->id, 
				H->name, 
				H->passwd, 
				H->person_money);
	while(H->next != NULL)
	{
		fprintf(fp1,"%d %s %s %d\n",
				H->next->id, 
				H->next->name, 
				H->next->passwd, 
				H->next->person_money);
		H = H->next;
	}
	fclose(fp1);
}
struct person *r_user_file(struct person *H)
{
	struct person *newnode = NULL;
	struct person *p = H,*temp = NULL;
	
	FILE *fp;
	if((fp=fopen("user.txt","rt")) == NULL)
	{
		printf("r_user_file无法打开文件user.txt--任意键退出!\n");
		getchar();
		exit(1);
	}
	fscanf(fp,"%d %s %s %d",
				&H->id, 
				H->name, 
				H->passwd, 
				&H->person_money);
	while(!feof(fp))
	{					
		newnode = (struct person *)malloc(sizeof(struct person));
		if(newnode == NULL)
		{
			printf("产生新节点时空间非配错误！\n");
			exit(0);
		}
		newnode->next = NULL;
		fscanf(fp,"%d %s %s %d",
				&newnode->id, 
				newnode->name, 
				newnode->passwd, 
				&newnode->person_money);
		p->next = newnode;
		temp = p;
		p = newnode;
		len_user++;		//用户数加一
	}
	fclose(fp);
	temp->next = NULL;	//最有一个读出有问题，将最后一个节点释放
	free(p);
	len = temp->id;
	return temp;
}

void w_buy_file(struct buy_ticket *buy_H)
{
	FILE *fp1;
	if((fp1 = fopen("buy.txt","wt")) == NULL)
	{
		printf("w_buy_file无法创建文件buy.txt--任意键退出!\n");
		getchar();
		exit(1);
	}
	fprintf(fp1,"%d %d %d %d\n",
					buy_H->person_id,		//上一期体彩中奖号码
					buy_H->ticket_number,	//上一期慈善中奖号码
					buy_H->ticket_amount,	//上一期救灾中奖号码
					buy_H->ticket_dayth		//可买的期号
				);
	while(buy_H->next != NULL)
	{
		fprintf(fp1,"%d %s %d %d %d %d %d %d %d\n",
										buy_H->next->person_id,
										buy_H->next->person_name,
										buy_H->next->ticket_dayth,
										buy_H->next->ticket_type,
										buy_H->next->ticket_number,
										buy_H->next->ticket_amount,
										buy_H->next->ticket_status,
										buy_H->next->ticket_win,
										buy_H->next->ticket_sum);
		buy_H = buy_H->next;
	}
	fclose(fp1);
}

struct buy_ticket *r_buy_file(struct buy_ticket *buy_H)
{
	struct buy_ticket *newnode = NULL;
	struct buy_ticket *buy_p = buy_H,*temp = NULL;
	
	FILE *fp;
	if((fp=fopen("buy.txt","rt")) == NULL)
	{
		printf("r_buy_file无法打开文件buy.txt--任意键退出!\n");
		getchar();
		exit(1);
	}
	fscanf(fp,"%d %d %d %d\n",
				&buy_H->person_id,		//上一期体彩中奖号码
				&buy_H->ticket_number,	//上一期慈善中奖号码
				&buy_H->ticket_amount,	//上一期救灾中奖号码
				&buy_H->ticket_dayth	//可买的期号
			);
	while(!feof(fp))
	{					
		newnode = (struct buy_ticket *)malloc(sizeof(struct buy_ticket));
		if(newnode == NULL)
		{
			printf("产生新节点时空间非配错误！\n");
			exit(0);
		}
		newnode->next = NULL;
		fscanf(fp,"%d %s %d %d %d %d %d %d %d\n",
										&newnode->person_id,
										newnode->person_name,
										&newnode->ticket_dayth,
										&newnode->ticket_type,
										&newnode->ticket_number,
										&newnode->ticket_amount,
										&newnode->ticket_status,
										&newnode->ticket_win,
										&newnode->ticket_sum);
		buy_p->next = newnode;
		temp = buy_p;
		buy_p = newnode;
		len_buy++;				//购票信息个数加1
	}
	fclose(fp);
	return buy_p;
}

void w_wininformation_file(struct news temp)
{
	FILE *fp1;
	if((fp1 = fopen("wininformation.txt","at")) == NULL)
	{
		printf("w_wininformation_file无法创建文件wininformation.txt--任意键退出!\n");
		getchar();
		exit(1);
	}
	fprintf(fp1,"%d %d %d %d %d %d %d %d %d %d %d\n",
										temp.dayth,
										temp.sport_ticket,
										temp.love_ticket,
										temp.disastor_ticket,
										temp.sum,
										temp.year,
										temp.month,
										temp.day,
										temp.hour,
										temp.min,
										temp.sec
										);
	fclose(fp1);
}


void r_wininformation_file()
{
	struct news temp;
	FILE *fp1;
	if((fp1 = fopen("wininformation.txt","rt")) == NULL)
	{
		printf("r_wininformation_file无法创建文件wininformation.txt--任意键退出!\n");
		getchar();
		exit(1);
	}
	printf("\t\t期号  体育彩票  慈善彩票  救灾彩票  中出金额\t日期\n");
	while(!feof(fp1))
	{
		fscanf(fp1,"%d %d %d %d %d %d %d %d %d %d %d\n",
										&temp.dayth,
										&temp.sport_ticket,
										&temp.love_ticket,
										&temp.disastor_ticket,
										&temp.sum,
										&temp.year,
										&temp.month,
										&temp.day,
										&temp.hour,
										&temp.min,
										&temp.sec
										);
		printf("\t\t%d\t%d\t  %d\t  %d\t\t%d\t%d年%d月%d日  %d-%d-%d\n",
										temp.dayth,
										temp.sport_ticket,
										temp.love_ticket,
										temp.disastor_ticket,
										temp.sum,
										temp.year,
										temp.month,
										temp.day,
										temp.hour,
										temp.min,
										temp.sec
										);
	}
	fclose(fp1);
}

void w_winer_file(struct buy_ticket *temp)
{
	FILE *fp1;
	if((fp1 = fopen("winer.txt","at")) == NULL)
	{
		printf("w_winer_file无法创建文件winer.txt--任意键退出!\n");
		getchar();
		exit(1);
	}
	fprintf(fp1,"%d %s %d %d %d %d %d \n",
										temp->person_id,
										temp->person_name,
										temp->ticket_dayth,
										temp->ticket_type,
										temp->ticket_number,
										temp->ticket_amount,
										temp->ticket_winmoney);
	fclose(fp1);
}

void r_winer_file()
{
	struct buy_ticket *temp = NULL;
	temp = (struct buy_ticket *)malloc(sizeof(struct buy_ticket));
	FILE *fp1;
	if((fp1 = fopen("winer.txt","rt")) == NULL)
	{
		printf("文件无法打开或无历史中奖人信息--任意键退出!\n");
		getchar();
		exit(0);
	}
	printf("\n\t\t各期中奖人信息：\n");
	printf("\t\t————————————————————————————————————————————\n");
	printf("\t\tID\t姓名\t期号\t类型\t\t号码\t数量\t中奖金额\n");
	while(!feof(fp1))
	{
		fscanf(fp1,"\t\t%d %s %d %d %d %d %d\n",
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
		if(temp->ticket_type == sport_ticket)
			printf("\t体育彩票");
		else if(temp->ticket_type == love_ticket)
			printf("\t慈善彩票");
		else
			printf("\t救灾彩票");
		printf("\t%d\t%d\t%d\n",temp->ticket_number,temp->ticket_amount,temp->ticket_winmoney);
	}
	fclose(fp1);
}

void w_visit_file(int visit)
{
	FILE *fp1;
	if((fp1 = fopen("visit.txt","wt")) == NULL)
	{
		printf("w_visit_file无法创建文件visit.txt--任意键退出!\n");
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
		printf("r_visit_file无法创建文件visit.txt--任意键退出!\n");
		getchar();
		exit(1);
	}
	fscanf(fp1,"%d",&visit);
	fclose(fp1);
	return visit;
}

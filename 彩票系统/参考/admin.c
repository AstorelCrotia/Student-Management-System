
/************************************
*功  能：	管理员相关
*
*************************************/

#include"fun.h"
#include<time.h>
/********************menu1菜单-管理员登录**************
*功  能:		管理员登录
*参  数：	H ：用户注册链表头结点
*参  数：	buy_H : 购票信息链表头节点
*
*****************************************************/
void admin_menu1(struct person *H,struct buy_ticket *buy_H)	//管理员登录
{
	char name_test[20];					//用户登录暂存
	char passwd_test[8];				//用户密码暂存
	int i = 0;

	do			
	{
		printf("请输入用户名： ");
		scanf("%s",name_test);	

		strcpy(passwd_test, getpass("请输入管理员密码："));	
		printf("\n");
		if(strcmp(H->name,name_test) != 0 || strcmp(H->passwd,passwd_test) != 0)
			{
				i++;
				if(i>=3)
				{
					key_error();
					printf("\n@_@---> 密码错误次数超过3次！任意键返回主菜单");
					getchar();			//一个用于吸收scanf后的回车
					getchar();
					break;
				}
				printf("\n用户名或者密码错误！请重新输入：\n");
			}
		else
			{
				i=0;
				break;
			}
	}while(1);
	if(i == 0)							//密码正确
	{
		while(menu_select != 0)			//menu_select==0 ,则退出当前菜单
		{
			menu1();
			scanf("%d",&menu_select);
			getchar();					//防止输入字符时进入死循环
			switch(menu_select)
			{
				case 0:					//返回主菜单
						menu_select = 0;
					break;
				case 1:					//摇号
						make_prize(H,buy_H);//摇号顺便比较
					break;
				case 2:					//管理员查看信息
						admin_view(H,buy_H);	
					break;
				case 3:					//修改信息
						admin_updata(H);
					break;
				case 4:					//删除信息
						admin_deldata(H,buy_H);
					break;
				case 5:					//排序
						admin_sort(H,buy_H);
					break;
				default:
					printf("\n@_@---> 选择有误！任意键返回菜单！");
					getchar();
					menu_select = 0;
					break;	
			}
		}
	}
}
/*****************管理员摇号***********************
*功  能：	管理员摇号，并统计获奖情况
*参  数：	H ：用户信息头结点，奖池金额在头结点
*参  数：	buy_H ：购票信息头结点，比较获奖情况
*注  意：	每期中奖信息往文件存时并没有建链表
**********************************************/
void make_prize(struct person *H, struct buy_ticket *buy_H)
{
	struct news	prize;
	int flag = 0;					//是否有人中奖；1有0无
	struct buy_ticket *temp = buy_H;
	int x = 0, y = 0, z = 0;		//x,y,z三种彩票中奖号码
	printf("是否开始第%d期的摇奖(y/n)?",buy_H->ticket_dayth);
	if(getchar() == 'y')			//开始摇奖
	{
		srand((unsigned)time(NULL));
		x = rand()%20+1;			//体彩
		y = rand()%20+1;			//慈善
		z = rand()%20+1;			//救灾彩票
		buy_H->person_id = x;		//体彩
		buy_H->ticket_number = y;	//慈善
		buy_H->ticket_amount = z;	//救灾彩票
		buy_H->ticket_sum = 0;		//初始化当期获奖总金额
		luck_draw();				//系统摇奖中···
		/*------下-延时函数-------------*/
		time_t start,end;						//定义时间开始与结束
		double dif;
		time (&start);
		while(dif <5)							//时间小于5s一直在循环
		{
			time (&end);
			dif = difftime (end,start);
		}
		/*------上-延时函数-------------*/
		/*------下-显示时间---------------*/
		struct tm *tm_ptr;
		time_t the_time;
		(void) time(&the_time);
		tm_ptr=localtime(&the_time);
		/*------上-显示时间---------------*/
		
		printf("\n\t\t第%d期的中奖号码为：\n",buy_H->ticket_dayth);
		printf("\t\t————————————————————————————————\n");
		printf("\t\t体育彩票： %d\n",x);
		printf("\t\t慈善彩票： %d\n",y);
		printf("\t\t救灾彩票： %d\n\n",z);
		printf("\t\t抽奖时间:%02d年%02d月%02d日  %02d-%02d-%02d\n",
												tm_ptr->tm_year-100,	//年
												tm_ptr->tm_mon+1,		//月
												tm_ptr->tm_mday,		//日
												tm_ptr->tm_hour,		//时
												tm_ptr->tm_min,			//分
												tm_ptr->tm_sec);		//秒
		printf("\t\t————————————————————————————————\n");
		
		printf("\t\t中奖人信息：\n");
		printf("\t\t————————————————————————————————————————————————————————————————————————————————————\n");
		printf("\t\tID\t姓名\t期号\t  类型\t\t号码\t数量\t开奖状态  中奖情况  中奖金额 \n");
	
		while(temp->next != NULL)
		{
			if(temp->next->ticket_dayth == buy_H->ticket_dayth)	//购买当期才判断,中奖的话奖池减少，彩民增加		
			{
				temp->next->ticket_status = 0 ;					//开奖状态为开奖0：开奖
				switch(temp->next->ticket_type)
				{
					case sport_ticket :
							if(temp->next->ticket_number == x)
							{
							temp->next->ticket_win =1;			//中奖
							temp->next->ticket_winmoney = temp->next->ticket_amount * sport_win;	//个人本期中奖金额
							buy_H->ticket_sum += temp->next->ticket_winmoney;	//算出中出奖总金额	
							add_winer_money(H,temp->next->person_id,temp->next->ticket_amount * sport_win);//中奖增加金额
							}
						break;
					case love_ticket :
							if(temp->next->ticket_number == y)
							{
								temp->next->ticket_win =1;		//中奖
								temp->next->ticket_winmoney = temp->next->ticket_amount * love_win ;//本次中奖金额
								buy_H->ticket_sum += temp->next->ticket_winmoney;
								add_winer_money(H,temp->next->person_id,temp->next->ticket_amount * love_win);//增加金额
							}
						break;
					case disastor_ticket:
							if(temp->next->ticket_number == z)
							{
							temp->next->ticket_win =1;			//中奖
							temp->next->ticket_winmoney = temp->next->ticket_amount * disastor_win ;
							buy_H->ticket_sum += temp->next->ticket_winmoney;	
							add_winer_money(H,temp->next->person_id,temp->next->ticket_amount * disastor_win);//增加金额
							}
						break;
					default:
						break;
				}
				
				if(temp->next->ticket_win)	//中奖的话,写入文件
				{
						flag = 1;			//中奖标志改为1,方便无中奖时，输出提示
						printf("\t\t%d\t%s\t%d",
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
						printf("\t%d\n",temp->next->ticket_winmoney);	//中奖金额
					w_winer_file(temp->next);							//用户节点，将用户信息写入文件,
				}
			}
			temp = temp->next;	
		}
		if(!flag)
			printf("\n\t\t^_^本期无彩民中奖！--");
			
		H->person_money -= buy_H->ticket_sum;	//修改将池金额:总金额-当期中奖总金额（存在buy_H头结点中），
		printf("奖池金额为：%d 元\n",H->person_money);
		prize.dayth = buy_H->ticket_dayth;	//期号
		prize.sport_ticket = x;				//体育彩票
		prize.love_ticket  = y;				//慈善
		prize.disastor_ticket = z;			//救灾
		prize.sum = buy_H->ticket_sum;		//总金额
		prize.year = tm_ptr->tm_year-100;	//年
		prize.month = tm_ptr->tm_mon+1;		//月
		prize.day = tm_ptr->tm_mday;		//日
		prize.hour = tm_ptr->tm_hour;		//时
		prize.min = tm_ptr->tm_min;			//分
		prize.sec = tm_ptr->tm_sec;			//秒
													
		/*-每期中奖信息保存，无需链表,需保存：期号，三种中奖号码，总金额-----*/
		w_wininformation_file(prize);
		buy_H->ticket_dayth ++;					//加一开通下次期号
		
		printf("任意键返回-->");
		getchar();
		getchar();

	}
}

/*****************彩民追加金额********************
*功  能：	追加彩民金额
*参  数：	H ：用户链表头结点
*参  数：    id：	输入查找的id
*参  数：	money:要追加的金额
************************************************/
void add_winer_money(struct person *H, int id,int money)
{
	while(H->next !=NULL)
	{
		if(H->next->id == id)
		{
			H->next->person_money += money;
			break;
		}
		H = H->next;
	}
}

/****************查看彩民基本信息********************
*功  能：	查看彩民基本信息
*参  数：	H ：用户信息头结点
***************************************************/
void people_information(struct person *H)
{
	printf("\t\t彩民基本信息为：\n");
	printf("\t\t-------------------------------\n");
	printf("\t\tid\t姓名\t密码\t金额(元)\n");
	printf("\t\t-------------------------------\n");
	while(H->next != NULL)
	{
		printf("\t\t%d\t%s\t%s\t%d\n",
								H->next->id, 
								H->next->name, 
								H->next->passwd, 
								H->next->person_money);
		H = H->next;
	}
	printf("-->任意键返回");
	getchar();

}

/***************menu12菜单-管理员查看信息*******************
*功  能：	管理员查看信息
*参  数：	H ： 用户链表，用于查找用户
*参  数：	buy_H : 购票信息头结点
*********************************************************/
void admin_view(struct person *H,struct buy_ticket *buy_H)
{
	while(menu_select !=0)
	{
		menu12();
		scanf("%d",&menu_select);
		getchar();				//防止输入字符时进入死循环
		switch(menu_select)
		{
			case 0:				//返回上一级
				break;
			case 1:				//管理员信息
					printf("\t\tid\t姓名\t密码\t奖池金额(元)\n");
					printf("\t\t-------------------------------\n");
					printf("\t\t%d\t%s\t%s\t%d\n",
									H->id, 
									H->name, 
									H->passwd, 
									H->person_money);
					printf("任意键退出-->");
					getchar();
				break;
			case 2:				//每期彩票信息
					r_wininformation_file();
					printf("任意键返回！");
					getchar();
				break;
			case 3:				//中奖人信息
					r_winer_file();
					printf("任意键返回！");
					getchar();
				break;
			case 4:				//彩民基本信息
					people_information(H);
				break;
			case 5:				//所有购票信息
					admin_view_buy_news(buy_H);
				break;
			case 6:				//根据ID查找购票信息	
					ID_check_buynews(buy_H);	
				break;
			case 7:				//根据期号查找信息
					dayth_check_buynews(buy_H);
				break;
			default:	
					menu_select = 0;
					printf("\n@_@---> 选择有误！任意键返回菜单！");
					getchar();		
				break;
		}
		if(menu_select == 0)
		{
			menu_select =1;		//上级菜单入口参数为1
			break;				//退出while(),不退出会死循环
		}
	}
}
/*********************管理员查看所有购票信息*******************
*功  能：	管理员查看所有购票信息
*参  数：	buy_H : 购票信息头结点
*********************************************************/
/*------------查看所有购票信息-------------------------*/
void admin_view_buy_news(struct buy_ticket *buy_H)
{
	printf("\t所有购票信息：\n");
	printf("\t————————————————————————————————————————————————————————————————————————————————————\n");
	printf("\tID\t姓名\t期号\t  类型\t\t号码\t数量\t开奖状态  中奖情况  购票金额 \n");
	while(buy_H->next != NULL)
	{
		printf("\t%d\t%s\t%d",
						buy_H->next->person_id,
						buy_H->next->person_name,
						buy_H->next->ticket_dayth);
		if(buy_H->next->ticket_type == sport_ticket)
			printf("\t体育彩票");
		else if(buy_H->next->ticket_type == love_ticket)
			printf("\t慈善彩票");
		else
			printf("\t救灾彩票");
		printf("\t%d\t%d",
						buy_H->next->ticket_number,
						buy_H->next->ticket_amount);
		if(buy_H->next->ticket_status)
				printf("\t未开奖");
		else
				printf("\t已开奖");
		if(buy_H->next->ticket_win)
			printf("    中  奖");
		else
			printf("    未中奖");
		printf("\t%d\n",buy_H->next->ticket_sum);
		buy_H = buy_H->next;
	}
	printf("\t————————————————————————————————————————————————————————————————————————————————————\n");
	printf("任意键返回-->");
	getchar();
}

/*------------根据ID查找购票信息-------------------------*/
void ID_check_buynews(struct buy_ticket *buy_H)
{
	int id_find;
	printf("请输入查找的ID：");
	scanf("%d",&id_find);

	printf("\t查找的购票信息为：\n");
	printf("\t————————————————————————————————————————————————————————————————————————————————————\n");
	printf("\tID\t姓名\t期号\t  类型\t\t号码\t数量\t开奖状态  中奖情况  购票金额 \n");
	while(buy_H->next != NULL)
	{
		if(buy_H->next->person_id == id_find)
		{
			printf("\t%d\t%s\t%d",
						buy_H->next->person_id,
						buy_H->next->person_name,
						buy_H->next->ticket_dayth);
			if(buy_H->next->ticket_type == sport_ticket)
				printf("\t体育彩票");
			else if(buy_H->next->ticket_type == love_ticket)
				printf("\t慈善彩票");
			else
				printf("\t救灾彩票");
			printf("\t%d\t%d",
							buy_H->next->ticket_number,
							buy_H->next->ticket_amount);
			if(buy_H->next->ticket_status)
					printf("\t未开奖");
			else
					printf("\t已开奖");
			if(buy_H->next->ticket_win)
				printf("    中奖");
			else
				printf("    未中奖");
			printf("\t%d\n",buy_H->next->ticket_sum);
		}

		buy_H = buy_H->next;
	}
	printf("任意键返回-->");
	getchar();
	getchar();
}


/*------------根据期号查找所有购票信息-------------------------*/
void dayth_check_buynews(struct buy_ticket *buy_H)
{
	int dayth_find;
	printf("请输入查找的期号：");
	scanf("%d",&dayth_find);

	printf("\t查找的购票信息为：\n");
	printf("\t————————————————————————————————————————————————————————————————————————————————————\n");
	printf("\tID\t姓名\t期号\t  类型\t\t号码\t数量\t开奖状态  中奖情况  购票金额 \n");
	while(buy_H->next != NULL)
	{
		if(buy_H->next->ticket_dayth == dayth_find)
		{
			printf("\t%d\t%s\t%d",
						buy_H->next->person_id,
						buy_H->next->person_name,
						buy_H->next->ticket_dayth);
			if(buy_H->next->ticket_type == sport_ticket)
				printf("\t体育彩票");
			else if(buy_H->next->ticket_type == love_ticket)
				printf("\t慈善彩票");
			else
				printf("\t救灾彩票");
			printf("\t%d\t%d",
							buy_H->next->ticket_number,
							buy_H->next->ticket_amount);
			if(buy_H->next->ticket_status)
					printf("\t未开奖");
			else
					printf("\t已开奖");
			if(buy_H->next->ticket_win)
				printf("    中奖");
			else
				printf("    未中奖");
			printf("\t%d\n",buy_H->next->ticket_sum);
		}

		buy_H = buy_H->next;
	}
	printf("任意键返回-->");
	getchar();
	getchar();
}


/*------------menu13菜单-管理员修改信息-------------------------*/
void admin_updata(struct person *H)
{
	struct person *p;
	while(menu_select !=0)
	{
		menu13();
		scanf("%d",&menu_select);
		getchar();				//防止输入字符时进入死循环
		switch(menu_select)
		{
			case 0:				//返回上一级
				break;
			case 1:				//修改管理员密码
					adminself_updata(H);
				break;
			case 2:				//修改彩民密码
					p = admin_find_user(H);
					if(p != NULL)
					{
						p = p->next;	//由于admin_find_user函数的返回值由H->next,改为了H
						admin_change_information(p);
					}
					else
					{
						printf("未找到该信息！任意键返回！");
						getchar();
					}
				break;
			case 3:						//追加金额
					p = admin_find_user(H);
					p = p->next;		//由于admin_find_user函数的返回值由H->next,改为了H
					admin_add_money(p);
				break;
			default:	
					menu_select = 0;
					printf("\n@_@---> 选择有误！任意键返回菜单！");
					getchar();			
				break;
		}
		if(menu_select == 0)
		{
			menu_select =1;		//上级菜单入口参数为1
			break;				//退出while(),不退出会死循环
		}
	}
}

/*******************menu14菜单-管理员删除信息*********************
*功  能：	管理员删除信息
*参  数：	H ：用户信息头结点
*参  数：	buy_H: 用户购票信息头结点
****************************************************************/
void admin_deldata(struct person *H,struct buy_ticket *buy_H)
{
	struct person *p = NULL;
	struct person *temp =NULL;
	while(menu_select !=0)
	{
		menu14();
		scanf("%d",&menu_select);
		getchar();				//防止输入字符时进入死循环
		switch(menu_select)
		{
			case 0:				//返回上一级
				break;
			case 1:				//删除注册用户
					p = admin_find_user(H);
					if(p != NULL)
					{
						printf("\t\t该彩民基本信息为：\n");
						printf("\t\tid\t姓名\t密码\t金额(元)\n");
						printf("\t\t-------------------------------\n");
						printf("\t\t%d\t%s\t%s\t%d\n",
										p->next->id, 		//p之前写成了H->
										p->next->name, 
										p->next->passwd, 
										p->next->person_money);
						printf("确认删除 %s (y/n)？ ",p->next->name);
						if(getchar() == 'y')
						{
							len_buy--;					//注册用户数减1
							save_flag = 1;				//信息更新提示
							temp = p->next;
							p->next = temp->next;
							printf("\t%s 删除成功!\n",temp->name);
							printf("\t结点:   %p 已经销毁！任意键返回",temp);
							free(temp);
							getchar();
							getchar();	
						}
						else
						{
							printf("已取消删除！任意键返回");
							getchar();
							getchar();
						}
							
					}
					else
					{
						printf("所查找的学生不存在！\n");
						getchar();
					}
								
				break;
			case 2:				//根据ID删除购票信息
					id_del_buynews(buy_H);
				break;
			case 3:				//根据类型删除购票信息
					type_del_buynews(buy_H);
				break;
			case 4:				//根据期号删除购票信息
					dayth_del_buynews(buy_H);
				break;
			default:	
					menu_select = 0;
					printf("\n@_@---> 选择有误！任意键返回菜单！");
					getchar();		
				break;
		}
		if(menu_select == 0)
		{
			menu_select =1;		//上级菜单入口参数为1
			break;				//退出while(),不退出会死循环
		}
	}
}

/*------------根据ID删除购票信息-------------------------*/
void id_del_buynews(struct buy_ticket *buy_H)
{
	int id_find;
	struct buy_ticket *temp = NULL;
	printf("请输入要删除信息的ID：");
	scanf("%d",&id_find);
	getchar();
	printf("确定删除信息(y/n)?");
	if(getchar() == 'y')
	{
		while(buy_H->next != NULL)
		{
			if(buy_H->next->person_id == id_find && buy_H->next->ticket_status == 0)	//并且已开奖
			{
				temp = buy_H->next;			
				buy_H->next = buy_H->next->next;	//删除节点，下一个接上
				printf("删除成功，节点 %p 已销毁!\n",temp);
				free(temp);
				len_buy--;		//购票信息个数减1
			}
			else
				buy_H = buy_H->next;
		}
		printf("提示：未开奖的无法删除,任意键返回-->");
		getchar();
		getchar();
	}
	else
	{
		printf("已放弃！任意键返回-->");
		getchar();
		getchar();
	}
	
}

/*------------根据类型删除购票信息-------------------------*/
void type_del_buynews(struct buy_ticket *buy_H)
{
	int type_find;
	struct buy_ticket *temp = NULL;
	printf("请选择要删除信息的类型(1·体育彩票  2·慈善彩票 3·救灾彩票)：");
	scanf("%d",&type_find);
	getchar();
	printf("确定删除信息(y/n)?");
	if(getchar() == 'y')
	{
		while(buy_H->next != NULL)
		{
			if(buy_H->next->ticket_type == type_find && buy_H->next->ticket_status == 0)//并且已开奖
			{
				temp = buy_H->next;			
				buy_H->next = buy_H->next->next;	//删除节点，下一个接上
				printf("删除成功，节点 %p 已销毁!\n",temp);
				free(temp);
				len_buy--;		//购票信息个数减1
			}
			else
				buy_H = buy_H->next;
		}
		printf("提示：未开奖的无法删除,任意键返回-->");
		getchar();
		getchar();
	}
	else
	{
		printf("已放弃！任意键返回-->");
		getchar();
		getchar();
	}
	
}

/*------------根据期号删除购票信息-------------------------*/
void dayth_del_buynews(struct buy_ticket *buy_H)
{
	int dayth_find;
	struct buy_ticket *temp = NULL;
	printf("请输入要删除信息的期号：");
	scanf("%d",&dayth_find);
	getchar();
	printf("确定删除信息(y/n)?");
	if(getchar() == 'y')
	{
		while(buy_H->next != NULL)
		{
			if(buy_H->next->ticket_dayth == dayth_find && buy_H->next->ticket_status == 0)	//并且已开奖
			{
				temp = buy_H->next;			
				buy_H->next = buy_H->next->next;	//删除节点，下一个接上
				printf("删除成功，节点 %p 已销毁!\n",temp);
				free(temp);
				len_buy--;		//购票信息个数减1
			}
			else
				buy_H = buy_H->next;
		}
		printf("提示：未开奖的无法删除,任意键返回-->");
		getchar();
		getchar();
	}
	else
	{
		printf("已放弃！任意键返回-->");
		getchar();
		getchar();
	}
	
}

/****************menu15菜单-管理员对信息排序*******************
*功  能：	管理员排序
*参  数：	H ： 用户头结点，对用户排序
*参  数：	buy_H : 购票信息头结点，对购票信息排序
************************************************************/
void admin_sort(struct person *H,struct buy_ticket *buy_H)
{
	while(menu_select !=0)
	{
		menu15();
		scanf("%d",&menu_select);
		getchar();				//防止输入字符时进入死循环
		switch(menu_select)
		{
			case 0:				//返回上一级
				break;
			case 1:				//按照帐号余额排序（排用户）排完并显示
					sortfun(H,buy_H);
				break;
			case 2:				//按照期号排序
					sortfun(H,buy_H);
				break;
			case 3:				//按购票总数排序
					sortfun(H,buy_H);
				break;
			default:	
					menu_select = 0;
					printf("\n@_@---> 选择有误！任意键返回菜单！");
					getchar();			
				break;
		}
		if(menu_select == 0)
		{
			menu_select =1;		//上级菜单入口参数为1
			break;				//退出while(),不退出会死循环
		}
	}
}

/************************管理员排序子函数*********************
*功  能：	管理排序子函数
*参  数：	H ：用户头结点
*参  数：	buy_H : 购票信息头结点
*提  示：
*    1·对用户排序（menu_select == 1）
*    2·对购票信息排序（menu_select ==2 3）
*    len_user 用户个数		len_buy 购票信息个数  全局变量
************************************************************/
void sortfun(struct person *H,struct buy_ticket *buy_H)
{
	int i,j;
	struct person *p = H;
	struct person *temp = NULL;
	struct buy_ticket *buy_p = buy_H;
	struct buy_ticket *buy_temp = NULL;
	if(menu_select == 1)					//对注册用户，余额从大到小排序
	{
		for(i=len_user-2;i>0;i--)
		{
			for(j=0;j<i;j++)
			{
				if(p->next->person_money < p->next->next->person_money)		//p->next与p->next->next比较
				{
					temp = p->next;			//以下四行，为交换两个相邻结点，可用作冒泡排序,p->next与p->next->next比较
					p->next = temp->next;
					temp->next = p->next->next;
					p->next->next = temp;	//以上四行，为交换两个相邻结点，可用作冒泡排序
				}
				p = p->next;
			}
			p = H;
		}
		printf("\t\t排序后>>\n");
		people_information(H);
	}
	else if(menu_select == 2)				//对购票信息的期号排序，从小到大
	{
		for(i=len_buy-1;i>0;i--)
		{
			for(j=0;j<i;j++)
			{
				if(buy_p->next->ticket_dayth > buy_p->next->next->ticket_dayth)		//p->next与p->next->next比较
				{
					buy_temp = buy_p->next;			//以下四行，为交换两个相邻结点，可用作冒泡排序,p->next与p->next->next比较
					buy_p->next = buy_temp->next;
					buy_temp->next = buy_p->next->next;
					buy_p->next->next = buy_temp;	//以上四行，为交换两个相邻结点，可用作冒泡排序
				}
				buy_p = buy_p->next;
			}
			buy_p = buy_H;
		}
		printf("\t排序后购票信息为：\n");
		admin_view_buy_news(buy_H);
	}
	else											//对购票信息的，用户当次购票总数,从大到小
	{
		for(i=len_buy-1;i>0;i--)
		{
			for(j=0;j<i;j++)
			{
				if(buy_p->next->ticket_amount < buy_p->next->next->ticket_amount)		//p->next与p->next->next比较
				{
					buy_temp = buy_p->next;			//以下四行，为交换两个相邻结点，可用作冒泡排序,p->next与p->next->next比较
					buy_p->next = buy_temp->next;
					buy_temp->next = buy_p->next->next;
					buy_p->next->next = buy_temp;	//以上四行，为交换两个相邻结点，可用作冒泡排序
				}
				buy_p = buy_p->next;
			}
			buy_p = buy_H;
		}
		printf("\t排序后购票信息为：\n");
		admin_view_buy_news(buy_H);
	}
}

/**************管理员产查找册用户*********************
*功  能：	管理员查找注册用户
*参  数：	H ： 用户头结点
*收  获：	输入 姓名 id 自动区分
*返回值：		找到学生返回其结点地址，未找到返回 NULL
***************************************************/
struct person * admin_find_user(struct person * H)
{
	int id = 0;
	char name[20];	
	printf("\n请输入要查找的姓名或ID：");
//	scanf("%s",name);
	fflush(stdin);
	scanf("%d",&id);			//自动区分姓名和id
	gets(name);
		while(H->next != NULL)
		{
			if((H->next->id == id) || (strcmp(H->next->name,name) == 0))	//姓名或者id相同
			{
				return H;
			}
			H = H->next;
		}
		if(H->next == NULL)		//未找到该学生
			return NULL;
}

/******************管理员修改已知地址的信息*************
*功  能：	管理员修改信息
*参  数：	p : 要修改学生的地址
*****************************************************/
void admin_change_information(struct person *p)		//p指向要改动的节点，由find提供
{
	char passwd_test[8];
	char passwd_test1[8];
	int i = 0;
	printf("该彩民信息为：\n");
	printf("\t\t-------------------------------\n");
	printf("\t\tid\t姓名\t密码\t金额(元)\n");
	printf("\t\t%d\t%s\t%s\t%d\n",
					p->id, 
					p->name, 
					p->passwd, 
					p->person_money);
	
	do
	{
		if(i>2)			//输入3次，则放弃更新
		{
			printf("错误次数超过3次！任意键返回");
			getchar();
			getchar();
			break;
		}				
		printf("请输入新密码：");
		scanf("%s",passwd_test);
		printf("请再次输入密码:");
		scanf("%s",passwd_test1);
		if(strcmp(passwd_test1,passwd_test)== 0)
		{
			save_flag = 1;		//信息已经更新
			strcpy(p->passwd,passwd_test1);
			printf("密码已更新！任意键返回！");
			getchar();			//需要两个，一个吸收之前的scanf后的
			getchar();
			break;
		}
		else
		{
			i++;
			printf("两次密码不匹配！请重新输入！\n");
		}
		
	}while(1);
}

/******************管理员追加金额***************
*功  能：	管理员追加金额
*参  数：	p : 要追加学生的地址
**********************************************/
void admin_add_money(struct person *p)
{
	int money;

	printf("余额为：");
	printf("%d 元\n",p->person_money);
	printf("请输入追加的金额 :");
	scanf("%d",&money);
	getchar();
	printf("确认追加？ (y/n)");
	if(getchar() == 'y')
	{
		save_flag = 1;	//信息更新提示
		p->person_money += money;
		printf("追加后的余额为："); 
		printf("%d 元\n",p->person_money);
		getchar();
		printf("任意键退出-->");
		getchar();
	}
	else
	{
		printf("已放弃追加！");
	}
	
	
}

/***************管理员修改个人信息*********************
*功  能：	管理员修改个人信息
*参  数：	用户头结点，管理员信息在用户链表头结点	
*****************************************************/
void adminself_updata(struct person *H)
{

	char passwd_test[8];
	char passwd_test1[8];
	char admin_passwd[8];
	char name[20];
	int i = 0;

	while(menu_select !=0)
	{
		menu131();
		scanf("%d",&menu_select);
		getchar();						//防止输入字符时进入死循环
		switch(menu_select)
		{
			case 0:						//返回上一级
				break;
			case 1:						//修改管理员姓名
					printf("请输入新用户名：");
					scanf("%s",name);
					getchar();
					printf("确认修改用户名 (y/n)?");
					if(getchar() == 'y')
					{
						save_flag = 1;	//信息更新提示
						strcpy(H->name,name);
						printf("修改成功！任意键返回！");
						getchar();
						getchar();
					}
					else
					{
						printf("已放弃修改！任意键返回！");
						getchar();
					}
				break;
			case 2:						//修改管理员密码
					strcpy(admin_passwd,getpass("请输入旧密码："));	
					if(strcmp(admin_passwd,H->passwd) == 0)
					{
						do
						{
							if(i>2)		//输入3次，则放弃更新
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
								save_flag = 1;		//信息已经更新
								strcpy(H->passwd,passwd_test1);
								printf("密码已更新！任意键返回！");
								getchar();
								break;
							}
							else
							{
								i++;
								printf("两次密码不匹配！请重新输入！\n");
							}
	
						}while(1);	
					}
					else
					{
						printf("密码错误！任意键返回！");
						getchar();
					}
					//---------修改管理员密码end
				break;
			case 3:							//追加奖池金额
					admin_add_money(H);		//调用管理员追加用户余额程序
				break;
			default:	
					menu_select = 0;
					printf("\n@_@---> 选择有误！任意键返回菜单！");
					getchar();			
				break;
		}
		if(menu_select == 0)
		{
			menu_select =3;		//上级菜单menu13入口参数为3
			break;				//退出while(),不退出会死循环
		}
	}

}


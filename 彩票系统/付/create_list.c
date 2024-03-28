#include<stdio.h>
#include<stdlib.h>
#include"head.h"

struct person * person_creat_head(struct person *H)
{
	struct person *newnode=NULL;
	newnode = (struct person *)malloc(sizeof(struct person));
	if(newnode == NULL)
	{
		printf("产生头节点时空间非配错误！\n");
		exit(0);
	}
	newnode->id = 0;
	newnode->person_money=admin_init_money;	//管理员初始金额
	strcpy(newnode->passwd,"admin");
	strcpy(newnode->name,"admin");
	newnode->next = NULL;
	return newnode;
}

struct buy_ticket * buy_creat_head(struct buy_ticket *buy_H)
{
	struct buy_ticket *newnode=NULL;
	newnode = (struct buy_ticket *)malloc(sizeof(struct buy_ticket));
	if(newnode == NULL)
	{
		printf("产生头节点时空间分配错误！\n");
		exit(0);
	}
	newnode->person_id = 0;			//上一期体彩中奖号码
	newnode->ticket_number = 0;		//慈善
	newnode->ticket_amount = 0;		//救灾彩票
	newnode->ticket_dayth = 1201;	//初始化为1201
	newnode->ticket_winmoney = 0;	//初始中奖为0
	newnode->next = NULL;
	return newnode;
}

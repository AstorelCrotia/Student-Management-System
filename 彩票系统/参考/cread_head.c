
/*******************************************
*功  能：	产生头节点
********************************************/

#include<stdio.h>
#include<stdlib.h>
#include"fun.h"

/***********用户注册产生头节点******************/
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

/***********购票信息产生头节点*****************
*功  能：	购票信息产生头节点
*提  示：	头节借存管理员摇奖后的信息
*   id：		存放上一期体彩中奖号码
*number:	存放上一期慈善彩票中奖号码
*amount:	存放上一期救灾彩票中奖号码
*ticket_dayth : 可够买的期号
********************************************/

struct buy_ticket * buy_creat_head(struct buy_ticket *buy_H)
{
	struct buy_ticket *newnode=NULL;
	newnode = (struct buy_ticket *)malloc(sizeof(struct buy_ticket));
	if(newnode == NULL)
	{
		printf("产生头节点时空间非配错误！\n");
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


/***********每期中奖信息产生头节点*****************
*		头节点可存储下一期的期号
********************************************/
/*
struct news * win_creat_head(struct news *win_H)
{
	struct news *newnode=NULL;
	newnode = (struct news *)malloc(sizeof(struct news));
	if(newnode == NULL)
	{
		printf("产生头节点时空间非配错误！\n");
		exit(0);
	}
	newnode->dayth = 1;		//头节点的dayth存用户可以购买的期号
	newnode->next = NULL;
	return newnode;
}
*/


#include<stdio.h>
#include<stdlib.h>
#include"head.h"

struct person * person_creat_head(struct person *H)
{
	struct person *newnode=NULL;
	newnode = (struct person *)malloc(sizeof(struct person));
	if(newnode == NULL)
	{
		printf("����ͷ�ڵ�ʱ�ռ�������\n");
		exit(0);
	}
	newnode->id = 0;
	newnode->person_money=admin_init_money;	//����Ա��ʼ���
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
		printf("����ͷ�ڵ�ʱ�ռ�������\n");
		exit(0);
	}
	newnode->person_id = 0;			//��һ������н�����
	newnode->ticket_number = 0;		//����
	newnode->ticket_amount = 0;		//���ֲ�Ʊ
	newnode->ticket_dayth = 1201;	//��ʼ��Ϊ1201
	newnode->ticket_winmoney = 0;	//��ʼ�н�Ϊ0
	newnode->next = NULL;
	return newnode;
}


/*******************************************
*��  �ܣ�	����ͷ�ڵ�
********************************************/

#include<stdio.h>
#include<stdlib.h>
#include"fun.h"

/***********�û�ע�����ͷ�ڵ�******************/
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

/***********��Ʊ��Ϣ����ͷ�ڵ�*****************
*��  �ܣ�	��Ʊ��Ϣ����ͷ�ڵ�
*��  ʾ��	ͷ�ڽ�����Աҡ�������Ϣ
*   id��		�����һ������н�����
*number:	�����һ�ڴ��Ʋ�Ʊ�н�����
*amount:	�����һ�ھ��ֲ�Ʊ�н�����
*ticket_dayth : �ɹ�����ں�
********************************************/

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


/***********ÿ���н���Ϣ����ͷ�ڵ�*****************
*		ͷ�ڵ�ɴ洢��һ�ڵ��ں�
********************************************/
/*
struct news * win_creat_head(struct news *win_H)
{
	struct news *newnode=NULL;
	newnode = (struct news *)malloc(sizeof(struct news));
	if(newnode == NULL)
	{
		printf("����ͷ�ڵ�ʱ�ռ�������\n");
		exit(0);
	}
	newnode->dayth = 1;		//ͷ�ڵ��dayth���û����Թ�����ں�
	newnode->next = NULL;
	return newnode;
}
*/


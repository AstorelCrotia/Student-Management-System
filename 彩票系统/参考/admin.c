
/************************************
*��  �ܣ�	����Ա���
*
*************************************/

#include"fun.h"
#include<time.h>
/********************menu1�˵�-����Ա��¼**************
*��  ��:		����Ա��¼
*��  ����	H ���û�ע������ͷ���
*��  ����	buy_H : ��Ʊ��Ϣ����ͷ�ڵ�
*
*****************************************************/
void admin_menu1(struct person *H,struct buy_ticket *buy_H)	//����Ա��¼
{
	char name_test[20];					//�û���¼�ݴ�
	char passwd_test[8];				//�û������ݴ�
	int i = 0;

	do			
	{
		printf("�������û����� ");
		scanf("%s",name_test);	

		strcpy(passwd_test, getpass("���������Ա���룺"));	
		printf("\n");
		if(strcmp(H->name,name_test) != 0 || strcmp(H->passwd,passwd_test) != 0)
			{
				i++;
				if(i>=3)
				{
					key_error();
					printf("\n@_@---> ��������������3�Σ�������������˵�");
					getchar();			//һ����������scanf��Ļس�
					getchar();
					break;
				}
				printf("\n�û�����������������������룺\n");
			}
		else
			{
				i=0;
				break;
			}
	}while(1);
	if(i == 0)							//������ȷ
	{
		while(menu_select != 0)			//menu_select==0 ,���˳���ǰ�˵�
		{
			menu1();
			scanf("%d",&menu_select);
			getchar();					//��ֹ�����ַ�ʱ������ѭ��
			switch(menu_select)
			{
				case 0:					//�������˵�
						menu_select = 0;
					break;
				case 1:					//ҡ��
						make_prize(H,buy_H);//ҡ��˳��Ƚ�
					break;
				case 2:					//����Ա�鿴��Ϣ
						admin_view(H,buy_H);	
					break;
				case 3:					//�޸���Ϣ
						admin_updata(H);
					break;
				case 4:					//ɾ����Ϣ
						admin_deldata(H,buy_H);
					break;
				case 5:					//����
						admin_sort(H,buy_H);
					break;
				default:
					printf("\n@_@---> ѡ��������������ز˵���");
					getchar();
					menu_select = 0;
					break;	
			}
		}
	}
}
/*****************����Աҡ��***********************
*��  �ܣ�	����Աҡ�ţ���ͳ�ƻ����
*��  ����	H ���û���Ϣͷ��㣬���ؽ����ͷ���
*��  ����	buy_H ����Ʊ��Ϣͷ��㣬�Ƚϻ����
*ע  �⣺	ÿ���н���Ϣ���ļ���ʱ��û�н�����
**********************************************/
void make_prize(struct person *H, struct buy_ticket *buy_H)
{
	struct news	prize;
	int flag = 0;					//�Ƿ������н���1��0��
	struct buy_ticket *temp = buy_H;
	int x = 0, y = 0, z = 0;		//x,y,z���ֲ�Ʊ�н�����
	printf("�Ƿ�ʼ��%d�ڵ�ҡ��(y/n)?",buy_H->ticket_dayth);
	if(getchar() == 'y')			//��ʼҡ��
	{
		srand((unsigned)time(NULL));
		x = rand()%20+1;			//���
		y = rand()%20+1;			//����
		z = rand()%20+1;			//���ֲ�Ʊ
		buy_H->person_id = x;		//���
		buy_H->ticket_number = y;	//����
		buy_H->ticket_amount = z;	//���ֲ�Ʊ
		buy_H->ticket_sum = 0;		//��ʼ�����ڻ��ܽ��
		luck_draw();				//ϵͳҡ���С�����
		/*------��-��ʱ����-------------*/
		time_t start,end;						//����ʱ�俪ʼ�����
		double dif;
		time (&start);
		while(dif <5)							//ʱ��С��5sһֱ��ѭ��
		{
			time (&end);
			dif = difftime (end,start);
		}
		/*------��-��ʱ����-------------*/
		/*------��-��ʾʱ��---------------*/
		struct tm *tm_ptr;
		time_t the_time;
		(void) time(&the_time);
		tm_ptr=localtime(&the_time);
		/*------��-��ʾʱ��---------------*/
		
		printf("\n\t\t��%d�ڵ��н�����Ϊ��\n",buy_H->ticket_dayth);
		printf("\t\t����������������������������������������������������������������\n");
		printf("\t\t������Ʊ�� %d\n",x);
		printf("\t\t���Ʋ�Ʊ�� %d\n",y);
		printf("\t\t���ֲ�Ʊ�� %d\n\n",z);
		printf("\t\t�齱ʱ��:%02d��%02d��%02d��  %02d-%02d-%02d\n",
												tm_ptr->tm_year-100,	//��
												tm_ptr->tm_mon+1,		//��
												tm_ptr->tm_mday,		//��
												tm_ptr->tm_hour,		//ʱ
												tm_ptr->tm_min,			//��
												tm_ptr->tm_sec);		//��
		printf("\t\t����������������������������������������������������������������\n");
		
		printf("\t\t�н�����Ϣ��\n");
		printf("\t\t������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("\t\tID\t����\t�ں�\t  ����\t\t����\t����\t����״̬  �н����  �н���� \n");
	
		while(temp->next != NULL)
		{
			if(temp->next->ticket_dayth == buy_H->ticket_dayth)	//�����ڲ��ж�,�н��Ļ����ؼ��٣���������		
			{
				temp->next->ticket_status = 0 ;					//����״̬Ϊ����0������
				switch(temp->next->ticket_type)
				{
					case sport_ticket :
							if(temp->next->ticket_number == x)
							{
							temp->next->ticket_win =1;			//�н�
							temp->next->ticket_winmoney = temp->next->ticket_amount * sport_win;	//���˱����н����
							buy_H->ticket_sum += temp->next->ticket_winmoney;	//����г����ܽ��	
							add_winer_money(H,temp->next->person_id,temp->next->ticket_amount * sport_win);//�н����ӽ��
							}
						break;
					case love_ticket :
							if(temp->next->ticket_number == y)
							{
								temp->next->ticket_win =1;		//�н�
								temp->next->ticket_winmoney = temp->next->ticket_amount * love_win ;//�����н����
								buy_H->ticket_sum += temp->next->ticket_winmoney;
								add_winer_money(H,temp->next->person_id,temp->next->ticket_amount * love_win);//���ӽ��
							}
						break;
					case disastor_ticket:
							if(temp->next->ticket_number == z)
							{
							temp->next->ticket_win =1;			//�н�
							temp->next->ticket_winmoney = temp->next->ticket_amount * disastor_win ;
							buy_H->ticket_sum += temp->next->ticket_winmoney;	
							add_winer_money(H,temp->next->person_id,temp->next->ticket_amount * disastor_win);//���ӽ��
							}
						break;
					default:
						break;
				}
				
				if(temp->next->ticket_win)	//�н��Ļ�,д���ļ�
				{
						flag = 1;			//�н���־��Ϊ1,�������н�ʱ�������ʾ
						printf("\t\t%d\t%s\t%d",
							temp->next->person_id,
							temp->next->person_name,
							temp->next->ticket_dayth);
						if(temp->next->ticket_type == sport_ticket)
							printf("\t������Ʊ");
						else if(temp->next->ticket_type == love_ticket)
							printf("\t���Ʋ�Ʊ");
						else
							printf("\t���ֲ�Ʊ");
						printf("\t%d\t%d",
										temp->next->ticket_number,
										temp->next->ticket_amount);
						if(temp->next->ticket_status)
								printf("\tδ����");
						else
								printf("\t�ѿ���");
						if(temp->next->ticket_win)
							printf("    ��  ��");
						else
							printf("    δ�н�");
						printf("\t%d\n",temp->next->ticket_winmoney);	//�н����
					w_winer_file(temp->next);							//�û��ڵ㣬���û���Ϣд���ļ�,
				}
			}
			temp = temp->next;	
		}
		if(!flag)
			printf("\n\t\t^_^�����޲����н���--");
			
		H->person_money -= buy_H->ticket_sum;	//�޸Ľ��ؽ��:�ܽ��-�����н��ܽ�����buy_Hͷ����У���
		printf("���ؽ��Ϊ��%d Ԫ\n",H->person_money);
		prize.dayth = buy_H->ticket_dayth;	//�ں�
		prize.sport_ticket = x;				//������Ʊ
		prize.love_ticket  = y;				//����
		prize.disastor_ticket = z;			//����
		prize.sum = buy_H->ticket_sum;		//�ܽ��
		prize.year = tm_ptr->tm_year-100;	//��
		prize.month = tm_ptr->tm_mon+1;		//��
		prize.day = tm_ptr->tm_mday;		//��
		prize.hour = tm_ptr->tm_hour;		//ʱ
		prize.min = tm_ptr->tm_min;			//��
		prize.sec = tm_ptr->tm_sec;			//��
													
		/*-ÿ���н���Ϣ���棬��������,�豣�棺�ںţ������н����룬�ܽ��-----*/
		w_wininformation_file(prize);
		buy_H->ticket_dayth ++;					//��һ��ͨ�´��ں�
		
		printf("���������-->");
		getchar();
		getchar();

	}
}

/*****************����׷�ӽ��********************
*��  �ܣ�	׷�Ӳ�����
*��  ����	H ���û�����ͷ���
*��  ����    id��	������ҵ�id
*��  ����	money:Ҫ׷�ӵĽ��
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

/****************�鿴���������Ϣ********************
*��  �ܣ�	�鿴���������Ϣ
*��  ����	H ���û���Ϣͷ���
***************************************************/
void people_information(struct person *H)
{
	printf("\t\t���������ϢΪ��\n");
	printf("\t\t-------------------------------\n");
	printf("\t\tid\t����\t����\t���(Ԫ)\n");
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
	printf("-->���������");
	getchar();

}

/***************menu12�˵�-����Ա�鿴��Ϣ*******************
*��  �ܣ�	����Ա�鿴��Ϣ
*��  ����	H �� �û��������ڲ����û�
*��  ����	buy_H : ��Ʊ��Ϣͷ���
*********************************************************/
void admin_view(struct person *H,struct buy_ticket *buy_H)
{
	while(menu_select !=0)
	{
		menu12();
		scanf("%d",&menu_select);
		getchar();				//��ֹ�����ַ�ʱ������ѭ��
		switch(menu_select)
		{
			case 0:				//������һ��
				break;
			case 1:				//����Ա��Ϣ
					printf("\t\tid\t����\t����\t���ؽ��(Ԫ)\n");
					printf("\t\t-------------------------------\n");
					printf("\t\t%d\t%s\t%s\t%d\n",
									H->id, 
									H->name, 
									H->passwd, 
									H->person_money);
					printf("������˳�-->");
					getchar();
				break;
			case 2:				//ÿ�ڲ�Ʊ��Ϣ
					r_wininformation_file();
					printf("��������أ�");
					getchar();
				break;
			case 3:				//�н�����Ϣ
					r_winer_file();
					printf("��������أ�");
					getchar();
				break;
			case 4:				//���������Ϣ
					people_information(H);
				break;
			case 5:				//���й�Ʊ��Ϣ
					admin_view_buy_news(buy_H);
				break;
			case 6:				//����ID���ҹ�Ʊ��Ϣ	
					ID_check_buynews(buy_H);	
				break;
			case 7:				//�����ںŲ�����Ϣ
					dayth_check_buynews(buy_H);
				break;
			default:	
					menu_select = 0;
					printf("\n@_@---> ѡ��������������ز˵���");
					getchar();		
				break;
		}
		if(menu_select == 0)
		{
			menu_select =1;		//�ϼ��˵���ڲ���Ϊ1
			break;				//�˳�while(),���˳�����ѭ��
		}
	}
}
/*********************����Ա�鿴���й�Ʊ��Ϣ*******************
*��  �ܣ�	����Ա�鿴���й�Ʊ��Ϣ
*��  ����	buy_H : ��Ʊ��Ϣͷ���
*********************************************************/
/*------------�鿴���й�Ʊ��Ϣ-------------------------*/
void admin_view_buy_news(struct buy_ticket *buy_H)
{
	printf("\t���й�Ʊ��Ϣ��\n");
	printf("\t������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\tID\t����\t�ں�\t  ����\t\t����\t����\t����״̬  �н����  ��Ʊ��� \n");
	while(buy_H->next != NULL)
	{
		printf("\t%d\t%s\t%d",
						buy_H->next->person_id,
						buy_H->next->person_name,
						buy_H->next->ticket_dayth);
		if(buy_H->next->ticket_type == sport_ticket)
			printf("\t������Ʊ");
		else if(buy_H->next->ticket_type == love_ticket)
			printf("\t���Ʋ�Ʊ");
		else
			printf("\t���ֲ�Ʊ");
		printf("\t%d\t%d",
						buy_H->next->ticket_number,
						buy_H->next->ticket_amount);
		if(buy_H->next->ticket_status)
				printf("\tδ����");
		else
				printf("\t�ѿ���");
		if(buy_H->next->ticket_win)
			printf("    ��  ��");
		else
			printf("    δ�н�");
		printf("\t%d\n",buy_H->next->ticket_sum);
		buy_H = buy_H->next;
	}
	printf("\t������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("���������-->");
	getchar();
}

/*------------����ID���ҹ�Ʊ��Ϣ-------------------------*/
void ID_check_buynews(struct buy_ticket *buy_H)
{
	int id_find;
	printf("��������ҵ�ID��");
	scanf("%d",&id_find);

	printf("\t���ҵĹ�Ʊ��ϢΪ��\n");
	printf("\t������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\tID\t����\t�ں�\t  ����\t\t����\t����\t����״̬  �н����  ��Ʊ��� \n");
	while(buy_H->next != NULL)
	{
		if(buy_H->next->person_id == id_find)
		{
			printf("\t%d\t%s\t%d",
						buy_H->next->person_id,
						buy_H->next->person_name,
						buy_H->next->ticket_dayth);
			if(buy_H->next->ticket_type == sport_ticket)
				printf("\t������Ʊ");
			else if(buy_H->next->ticket_type == love_ticket)
				printf("\t���Ʋ�Ʊ");
			else
				printf("\t���ֲ�Ʊ");
			printf("\t%d\t%d",
							buy_H->next->ticket_number,
							buy_H->next->ticket_amount);
			if(buy_H->next->ticket_status)
					printf("\tδ����");
			else
					printf("\t�ѿ���");
			if(buy_H->next->ticket_win)
				printf("    �н�");
			else
				printf("    δ�н�");
			printf("\t%d\n",buy_H->next->ticket_sum);
		}

		buy_H = buy_H->next;
	}
	printf("���������-->");
	getchar();
	getchar();
}


/*------------�����ںŲ������й�Ʊ��Ϣ-------------------------*/
void dayth_check_buynews(struct buy_ticket *buy_H)
{
	int dayth_find;
	printf("��������ҵ��ںţ�");
	scanf("%d",&dayth_find);

	printf("\t���ҵĹ�Ʊ��ϢΪ��\n");
	printf("\t������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\tID\t����\t�ں�\t  ����\t\t����\t����\t����״̬  �н����  ��Ʊ��� \n");
	while(buy_H->next != NULL)
	{
		if(buy_H->next->ticket_dayth == dayth_find)
		{
			printf("\t%d\t%s\t%d",
						buy_H->next->person_id,
						buy_H->next->person_name,
						buy_H->next->ticket_dayth);
			if(buy_H->next->ticket_type == sport_ticket)
				printf("\t������Ʊ");
			else if(buy_H->next->ticket_type == love_ticket)
				printf("\t���Ʋ�Ʊ");
			else
				printf("\t���ֲ�Ʊ");
			printf("\t%d\t%d",
							buy_H->next->ticket_number,
							buy_H->next->ticket_amount);
			if(buy_H->next->ticket_status)
					printf("\tδ����");
			else
					printf("\t�ѿ���");
			if(buy_H->next->ticket_win)
				printf("    �н�");
			else
				printf("    δ�н�");
			printf("\t%d\n",buy_H->next->ticket_sum);
		}

		buy_H = buy_H->next;
	}
	printf("���������-->");
	getchar();
	getchar();
}


/*------------menu13�˵�-����Ա�޸���Ϣ-------------------------*/
void admin_updata(struct person *H)
{
	struct person *p;
	while(menu_select !=0)
	{
		menu13();
		scanf("%d",&menu_select);
		getchar();				//��ֹ�����ַ�ʱ������ѭ��
		switch(menu_select)
		{
			case 0:				//������һ��
				break;
			case 1:				//�޸Ĺ���Ա����
					adminself_updata(H);
				break;
			case 2:				//�޸Ĳ�������
					p = admin_find_user(H);
					if(p != NULL)
					{
						p = p->next;	//����admin_find_user�����ķ���ֵ��H->next,��Ϊ��H
						admin_change_information(p);
					}
					else
					{
						printf("δ�ҵ�����Ϣ����������أ�");
						getchar();
					}
				break;
			case 3:						//׷�ӽ��
					p = admin_find_user(H);
					p = p->next;		//����admin_find_user�����ķ���ֵ��H->next,��Ϊ��H
					admin_add_money(p);
				break;
			default:	
					menu_select = 0;
					printf("\n@_@---> ѡ��������������ز˵���");
					getchar();			
				break;
		}
		if(menu_select == 0)
		{
			menu_select =1;		//�ϼ��˵���ڲ���Ϊ1
			break;				//�˳�while(),���˳�����ѭ��
		}
	}
}

/*******************menu14�˵�-����Աɾ����Ϣ*********************
*��  �ܣ�	����Աɾ����Ϣ
*��  ����	H ���û���Ϣͷ���
*��  ����	buy_H: �û���Ʊ��Ϣͷ���
****************************************************************/
void admin_deldata(struct person *H,struct buy_ticket *buy_H)
{
	struct person *p = NULL;
	struct person *temp =NULL;
	while(menu_select !=0)
	{
		menu14();
		scanf("%d",&menu_select);
		getchar();				//��ֹ�����ַ�ʱ������ѭ��
		switch(menu_select)
		{
			case 0:				//������һ��
				break;
			case 1:				//ɾ��ע���û�
					p = admin_find_user(H);
					if(p != NULL)
					{
						printf("\t\t�ò��������ϢΪ��\n");
						printf("\t\tid\t����\t����\t���(Ԫ)\n");
						printf("\t\t-------------------------------\n");
						printf("\t\t%d\t%s\t%s\t%d\n",
										p->next->id, 		//p֮ǰд����H->
										p->next->name, 
										p->next->passwd, 
										p->next->person_money);
						printf("ȷ��ɾ�� %s (y/n)�� ",p->next->name);
						if(getchar() == 'y')
						{
							len_buy--;					//ע���û�����1
							save_flag = 1;				//��Ϣ������ʾ
							temp = p->next;
							p->next = temp->next;
							printf("\t%s ɾ���ɹ�!\n",temp->name);
							printf("\t���:   %p �Ѿ����٣����������",temp);
							free(temp);
							getchar();
							getchar();	
						}
						else
						{
							printf("��ȡ��ɾ�������������");
							getchar();
							getchar();
						}
							
					}
					else
					{
						printf("�����ҵ�ѧ�������ڣ�\n");
						getchar();
					}
								
				break;
			case 2:				//����IDɾ����Ʊ��Ϣ
					id_del_buynews(buy_H);
				break;
			case 3:				//��������ɾ����Ʊ��Ϣ
					type_del_buynews(buy_H);
				break;
			case 4:				//�����ں�ɾ����Ʊ��Ϣ
					dayth_del_buynews(buy_H);
				break;
			default:	
					menu_select = 0;
					printf("\n@_@---> ѡ��������������ز˵���");
					getchar();		
				break;
		}
		if(menu_select == 0)
		{
			menu_select =1;		//�ϼ��˵���ڲ���Ϊ1
			break;				//�˳�while(),���˳�����ѭ��
		}
	}
}

/*------------����IDɾ����Ʊ��Ϣ-------------------------*/
void id_del_buynews(struct buy_ticket *buy_H)
{
	int id_find;
	struct buy_ticket *temp = NULL;
	printf("������Ҫɾ����Ϣ��ID��");
	scanf("%d",&id_find);
	getchar();
	printf("ȷ��ɾ����Ϣ(y/n)?");
	if(getchar() == 'y')
	{
		while(buy_H->next != NULL)
		{
			if(buy_H->next->person_id == id_find && buy_H->next->ticket_status == 0)	//�����ѿ���
			{
				temp = buy_H->next;			
				buy_H->next = buy_H->next->next;	//ɾ���ڵ㣬��һ������
				printf("ɾ���ɹ����ڵ� %p ������!\n",temp);
				free(temp);
				len_buy--;		//��Ʊ��Ϣ������1
			}
			else
				buy_H = buy_H->next;
		}
		printf("��ʾ��δ�������޷�ɾ��,���������-->");
		getchar();
		getchar();
	}
	else
	{
		printf("�ѷ��������������-->");
		getchar();
		getchar();
	}
	
}

/*------------��������ɾ����Ʊ��Ϣ-------------------------*/
void type_del_buynews(struct buy_ticket *buy_H)
{
	int type_find;
	struct buy_ticket *temp = NULL;
	printf("��ѡ��Ҫɾ����Ϣ������(1��������Ʊ  2�����Ʋ�Ʊ 3�����ֲ�Ʊ)��");
	scanf("%d",&type_find);
	getchar();
	printf("ȷ��ɾ����Ϣ(y/n)?");
	if(getchar() == 'y')
	{
		while(buy_H->next != NULL)
		{
			if(buy_H->next->ticket_type == type_find && buy_H->next->ticket_status == 0)//�����ѿ���
			{
				temp = buy_H->next;			
				buy_H->next = buy_H->next->next;	//ɾ���ڵ㣬��һ������
				printf("ɾ���ɹ����ڵ� %p ������!\n",temp);
				free(temp);
				len_buy--;		//��Ʊ��Ϣ������1
			}
			else
				buy_H = buy_H->next;
		}
		printf("��ʾ��δ�������޷�ɾ��,���������-->");
		getchar();
		getchar();
	}
	else
	{
		printf("�ѷ��������������-->");
		getchar();
		getchar();
	}
	
}

/*------------�����ں�ɾ����Ʊ��Ϣ-------------------------*/
void dayth_del_buynews(struct buy_ticket *buy_H)
{
	int dayth_find;
	struct buy_ticket *temp = NULL;
	printf("������Ҫɾ����Ϣ���ںţ�");
	scanf("%d",&dayth_find);
	getchar();
	printf("ȷ��ɾ����Ϣ(y/n)?");
	if(getchar() == 'y')
	{
		while(buy_H->next != NULL)
		{
			if(buy_H->next->ticket_dayth == dayth_find && buy_H->next->ticket_status == 0)	//�����ѿ���
			{
				temp = buy_H->next;			
				buy_H->next = buy_H->next->next;	//ɾ���ڵ㣬��һ������
				printf("ɾ���ɹ����ڵ� %p ������!\n",temp);
				free(temp);
				len_buy--;		//��Ʊ��Ϣ������1
			}
			else
				buy_H = buy_H->next;
		}
		printf("��ʾ��δ�������޷�ɾ��,���������-->");
		getchar();
		getchar();
	}
	else
	{
		printf("�ѷ��������������-->");
		getchar();
		getchar();
	}
	
}

/****************menu15�˵�-����Ա����Ϣ����*******************
*��  �ܣ�	����Ա����
*��  ����	H �� �û�ͷ��㣬���û�����
*��  ����	buy_H : ��Ʊ��Ϣͷ��㣬�Թ�Ʊ��Ϣ����
************************************************************/
void admin_sort(struct person *H,struct buy_ticket *buy_H)
{
	while(menu_select !=0)
	{
		menu15();
		scanf("%d",&menu_select);
		getchar();				//��ֹ�����ַ�ʱ������ѭ��
		switch(menu_select)
		{
			case 0:				//������һ��
				break;
			case 1:				//�����ʺ�����������û������겢��ʾ
					sortfun(H,buy_H);
				break;
			case 2:				//�����ں�����
					sortfun(H,buy_H);
				break;
			case 3:				//����Ʊ��������
					sortfun(H,buy_H);
				break;
			default:	
					menu_select = 0;
					printf("\n@_@---> ѡ��������������ز˵���");
					getchar();			
				break;
		}
		if(menu_select == 0)
		{
			menu_select =1;		//�ϼ��˵���ڲ���Ϊ1
			break;				//�˳�while(),���˳�����ѭ��
		}
	}
}

/************************����Ա�����Ӻ���*********************
*��  �ܣ�	���������Ӻ���
*��  ����	H ���û�ͷ���
*��  ����	buy_H : ��Ʊ��Ϣͷ���
*��  ʾ��
*    1�����û�����menu_select == 1��
*    2���Թ�Ʊ��Ϣ����menu_select ==2 3��
*    len_user �û�����		len_buy ��Ʊ��Ϣ����  ȫ�ֱ���
************************************************************/
void sortfun(struct person *H,struct buy_ticket *buy_H)
{
	int i,j;
	struct person *p = H;
	struct person *temp = NULL;
	struct buy_ticket *buy_p = buy_H;
	struct buy_ticket *buy_temp = NULL;
	if(menu_select == 1)					//��ע���û������Ӵ�С����
	{
		for(i=len_user-2;i>0;i--)
		{
			for(j=0;j<i;j++)
			{
				if(p->next->person_money < p->next->next->person_money)		//p->next��p->next->next�Ƚ�
				{
					temp = p->next;			//�������У�Ϊ�����������ڽ�㣬������ð������,p->next��p->next->next�Ƚ�
					p->next = temp->next;
					temp->next = p->next->next;
					p->next->next = temp;	//�������У�Ϊ�����������ڽ�㣬������ð������
				}
				p = p->next;
			}
			p = H;
		}
		printf("\t\t�����>>\n");
		people_information(H);
	}
	else if(menu_select == 2)				//�Թ�Ʊ��Ϣ���ں����򣬴�С����
	{
		for(i=len_buy-1;i>0;i--)
		{
			for(j=0;j<i;j++)
			{
				if(buy_p->next->ticket_dayth > buy_p->next->next->ticket_dayth)		//p->next��p->next->next�Ƚ�
				{
					buy_temp = buy_p->next;			//�������У�Ϊ�����������ڽ�㣬������ð������,p->next��p->next->next�Ƚ�
					buy_p->next = buy_temp->next;
					buy_temp->next = buy_p->next->next;
					buy_p->next->next = buy_temp;	//�������У�Ϊ�����������ڽ�㣬������ð������
				}
				buy_p = buy_p->next;
			}
			buy_p = buy_H;
		}
		printf("\t�����Ʊ��ϢΪ��\n");
		admin_view_buy_news(buy_H);
	}
	else											//�Թ�Ʊ��Ϣ�ģ��û����ι�Ʊ����,�Ӵ�С
	{
		for(i=len_buy-1;i>0;i--)
		{
			for(j=0;j<i;j++)
			{
				if(buy_p->next->ticket_amount < buy_p->next->next->ticket_amount)		//p->next��p->next->next�Ƚ�
				{
					buy_temp = buy_p->next;			//�������У�Ϊ�����������ڽ�㣬������ð������,p->next��p->next->next�Ƚ�
					buy_p->next = buy_temp->next;
					buy_temp->next = buy_p->next->next;
					buy_p->next->next = buy_temp;	//�������У�Ϊ�����������ڽ�㣬������ð������
				}
				buy_p = buy_p->next;
			}
			buy_p = buy_H;
		}
		printf("\t�����Ʊ��ϢΪ��\n");
		admin_view_buy_news(buy_H);
	}
}

/**************����Ա�����Ҳ��û�*********************
*��  �ܣ�	����Ա����ע���û�
*��  ����	H �� �û�ͷ���
*��  ��	���� ���� id �Զ�����
*����ֵ��		�ҵ�ѧ�����������ַ��δ�ҵ����� NULL
***************************************************/
struct person * admin_find_user(struct person * H)
{
	int id = 0;
	char name[20];	
	printf("\n������Ҫ���ҵ�������ID��");
//	scanf("%s",name);
	fflush(stdin);
	scanf("%d",&id);			//�Զ�����������id
	gets(name);
		while(H->next != NULL)
		{
			if((H->next->id == id) || (strcmp(H->next->name,name) == 0))	//��������id��ͬ
			{
				return H;
			}
			H = H->next;
		}
		if(H->next == NULL)		//δ�ҵ���ѧ��
			return NULL;
}

/******************����Ա�޸���֪��ַ����Ϣ*************
*��  �ܣ�	����Ա�޸���Ϣ
*��  ����	p : Ҫ�޸�ѧ���ĵ�ַ
*****************************************************/
void admin_change_information(struct person *p)		//pָ��Ҫ�Ķ��Ľڵ㣬��find�ṩ
{
	char passwd_test[8];
	char passwd_test1[8];
	int i = 0;
	printf("�ò�����ϢΪ��\n");
	printf("\t\t-------------------------------\n");
	printf("\t\tid\t����\t����\t���(Ԫ)\n");
	printf("\t\t%d\t%s\t%s\t%d\n",
					p->id, 
					p->name, 
					p->passwd, 
					p->person_money);
	
	do
	{
		if(i>2)			//����3�Σ����������
		{
			printf("�����������3�Σ����������");
			getchar();
			getchar();
			break;
		}				
		printf("�����������룺");
		scanf("%s",passwd_test);
		printf("���ٴ���������:");
		scanf("%s",passwd_test1);
		if(strcmp(passwd_test1,passwd_test)== 0)
		{
			save_flag = 1;		//��Ϣ�Ѿ�����
			strcpy(p->passwd,passwd_test1);
			printf("�����Ѹ��£���������أ�");
			getchar();			//��Ҫ������һ������֮ǰ��scanf���
			getchar();
			break;
		}
		else
		{
			i++;
			printf("�������벻ƥ�䣡���������룡\n");
		}
		
	}while(1);
}

/******************����Ա׷�ӽ��***************
*��  �ܣ�	����Ա׷�ӽ��
*��  ����	p : Ҫ׷��ѧ���ĵ�ַ
**********************************************/
void admin_add_money(struct person *p)
{
	int money;

	printf("���Ϊ��");
	printf("%d Ԫ\n",p->person_money);
	printf("������׷�ӵĽ�� :");
	scanf("%d",&money);
	getchar();
	printf("ȷ��׷�ӣ� (y/n)");
	if(getchar() == 'y')
	{
		save_flag = 1;	//��Ϣ������ʾ
		p->person_money += money;
		printf("׷�Ӻ�����Ϊ��"); 
		printf("%d Ԫ\n",p->person_money);
		getchar();
		printf("������˳�-->");
		getchar();
	}
	else
	{
		printf("�ѷ���׷�ӣ�");
	}
	
	
}

/***************����Ա�޸ĸ�����Ϣ*********************
*��  �ܣ�	����Ա�޸ĸ�����Ϣ
*��  ����	�û�ͷ��㣬����Ա��Ϣ���û�����ͷ���	
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
		getchar();						//��ֹ�����ַ�ʱ������ѭ��
		switch(menu_select)
		{
			case 0:						//������һ��
				break;
			case 1:						//�޸Ĺ���Ա����
					printf("���������û�����");
					scanf("%s",name);
					getchar();
					printf("ȷ���޸��û��� (y/n)?");
					if(getchar() == 'y')
					{
						save_flag = 1;	//��Ϣ������ʾ
						strcpy(H->name,name);
						printf("�޸ĳɹ�����������أ�");
						getchar();
						getchar();
					}
					else
					{
						printf("�ѷ����޸ģ���������أ�");
						getchar();
					}
				break;
			case 2:						//�޸Ĺ���Ա����
					strcpy(admin_passwd,getpass("����������룺"));	
					if(strcmp(admin_passwd,H->passwd) == 0)
					{
						do
						{
							if(i>2)		//����3�Σ����������
							{
								printf("�����������3�Σ����������");
								getchar();
								getchar();
								break;
							}	
							strcpy(passwd_test,getpass("�����������룺"));	
							strcpy(passwd_test1,getpass("���ٴ��������룺"));				
							if(strcmp(passwd_test1,passwd_test)== 0)
							{
								save_flag = 1;		//��Ϣ�Ѿ�����
								strcpy(H->passwd,passwd_test1);
								printf("�����Ѹ��£���������أ�");
								getchar();
								break;
							}
							else
							{
								i++;
								printf("�������벻ƥ�䣡���������룡\n");
							}
	
						}while(1);	
					}
					else
					{
						printf("���������������أ�");
						getchar();
					}
					//---------�޸Ĺ���Ա����end
				break;
			case 3:							//׷�ӽ��ؽ��
					admin_add_money(H);		//���ù���Ա׷���û�������
				break;
			default:	
					menu_select = 0;
					printf("\n@_@---> ѡ��������������ز˵���");
					getchar();			
				break;
		}
		if(menu_select == 0)
		{
			menu_select =3;		//�ϼ��˵�menu13��ڲ���Ϊ3
			break;				//�˳�while(),���˳�����ѭ��
		}
	}

}


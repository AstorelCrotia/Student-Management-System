

/*******************************
��    �ܣ�	�û����,�ļ����

*******************************/

#include<stdlib.h>
#include"fun.h"

/***********���û�ע�ắ��*******************
*��	�ܣ�	 ���û�ע�ᣬ������
*�� ����	 H ���û�ע������ͷ���
*�� ����  p ���û��������һ���ڵ�
*******************************************/
struct person * add_user(struct person *H,struct person *p)
{
	char passwd1[8],passwd2[8];
	char name[20];
	int i=0,flag = 1;			//�û����Ƿ����1,����
	struct person *newnode=NULL;

	do							//����û����Ƿ����
	{
		printf("����������(��׼������)��");
		scanf("%s",name);
		flag = check_username(H,name);
		if(flag == 0)			//0���û���������
			{
				i = 0;
				break;
			}

		else
			{
				printf("\n�û����Ѵ��ڣ���������%sA��\n",name);
				i++;
				if(i == 3)		//�޶��������
				{
					key_error();
					printf("\n@_@---> ���볬��3�Σ�������������˵��� \n");
					getchar();
					getchar();
					break;
				}
			}
	}while(1);
	if(!flag)
	{
		do
		{
			strcpy(passwd1, getpass("���������룺"));	//---------------------
			strcpy(passwd2, getpass("���ٴ��������룺"));	

			i++;
			if(i == 3)			//�޶��������
			{
				printf("\n@_@---> ���볬��3�Σ�������������˵��� \n");
				getchar();
				getchar();
				break;
			}

			if(strcmp(passwd1,passwd2) == 0)
			{
				break;			//������ȷ���˳�
			}
			else
				printf("�����������벻ƥ�䣡�������������룡\n");	
		}while(1);
		if(i!=3)				//ע��ɹ�
		{
			len++;
			len_user++;
			//ע��ɹ���������
			save_flag = 1;		//��Ϣ������ʾ
			newnode = (struct person *)malloc(sizeof(struct person));
				if(newnode == NULL)
				{
					printf("����ͷ�ڵ�ʱ�ռ�������\n");
					exit(0);
				}
				newnode->next = NULL;
				
			newnode->id = len;
			strcpy(newnode->passwd,passwd1);			//����
			strcpy(newnode->name,name);					//����
			newnode->person_money = user_init_money;	//��ʼ���
			apply_success();							//ע��ɹ���ʾ�ڲ˵�
			printf("\n\t\t\t�� Ʊ ϵ ͳ\n");
			printf("\t\t*********************************\n");
			printf("\t\t*\tע��ɹ���^_^\t\t*\n");
			printf("\t\t*  ��ϲ��%s (����/Ůʿ)\t*\n",newnode->name);
			printf("\t\t*  ϵͳ��������%dԪ\t\t*\n",user_init_money);
			printf("\t\t*  ���μ��������룡\t\t*\n");
			printf("\t\t*\t\t\t\t*\n");
			printf("\t\t*  ���������������Ա��ϵ��\t*\n");
			printf("\t\t*********************************\n\n");
			printf("  ���������-->");
			getchar();
			getchar();
			p->next = newnode;
			p = newnode;
		}
	}
	return p;
}


/****************menu2�˵�-�����¼****************
*��  �ܣ�	�����¼
*��  ����	H: �û�����ͷ���
*��  ����	buy_H: ��Ʊ��Ϣ���һ���ڵ�
*************************************************/
struct buy_ticket * person_menu2(struct person *H,struct buy_ticket *buy_p,struct buy_ticket *buy_H)
{
	char name_test[20];				//�û���¼�ݴ�
	char passwd_test[8];			//�û������ݴ�
	struct person *p = H;
//	struct buy_ticket *buy_p = buy_H;
	int i = 0;
		
	do
	{
		printf("�������û����� ");
		scanf("%s",name_test);	
		strcpy(passwd_test, getpass("���������룺"));	
		while(p->next !=NULL)
		{
			if(strcmp(p->next->name,name_test) == 0 && strcmp(p->next->passwd,passwd_test) == 0)
			{
				break;
			}
			p = p->next;
		}
		if(p->next ==NULL)			//�û������������
		{
			i++;
			if(i>=3)				//����3�����ϣ��˳�
			{
				key_error();
				printf("\n@_@---> �����������3�Σ�������������˵���\n");
				getchar();
				getchar();
				break;
			}
			printf("�û���������������������룺\n");
		}
		else
		{
			i =0;
			break;
		}
		p = H;						//pָ��ͷ�ڵ�
	}while(1);
	if(i == 0)
	{
		while(menu_select != 0)		//menu_select==0 ,���˳���ǰ�˵�
		{
			menu2();
			scanf("%d",&menu_select);
			getchar();				//��ֹ�����ַ�ʱ������ѭ��
			switch(menu_select)
			{
				case 0:				//�������˵�
						menu_select = 0;
						return buy_p;
					break;
				case 1:				//��Ʊ
									//buy_p,���һ��������Ϣ��p->next��ǰ�û��ڵ�,H,����Ա��Ϣ
						buy_p = user_buy_tickey(buy_p,p->next,H);
					break;
				case 2:				//�鿴��Ϣ
						printf("\t\t���ĸ�����ϢΪ��\n");
						printf("\t\t-------------------------------\n");
						printf("\t\tid\t����\t����\t���(Ԫ)\n");
						printf("\t\t%d\t%s\t%s\t%d\n",
												p->next->id, 
												p->next->name, 
												p->next->passwd, 
												p->next->person_money);
						user_view_ticket(p->next,buy_H);
						printf("���������");
						getchar();
					break;
				case 3:				//�޸���Ϣ
									//p->next,�û����,p����һ�ڵ�
						userself_updata(H,p->next);	
					break;
				default:
					printf("\n@_@---> ѡ��������������ز˵���\n");
					getchar();
					menu_select = 0;//���˵���ڲ���
					break;	
			}
		}
	}
}
/*************�û��鿴���˹�Ʊ��Ϣ**********************
*��  �ܣ�	�û��鿴��Ʊ��Ϣ
*��  ����	p : ��ǰ��¼�û��Ľ��
*��  ����buy_H : �û���Ʊ��Ϣͷ�ڵ�
*****************************************************/
void user_view_ticket(struct person *p,struct buy_ticket *buy_H)
{
	struct buy_ticket *temp = buy_H;
	printf("\n\t�����н����룺\n");
	printf("\t����������������������������������������������������������������������������������������������������������������\n");
	printf("\t������Ʊ\t���Ʋ�Ʊ\t���ֲ�Ʊ\t���ڲ�Ʊ\n");
	printf("\t%d\t\t%d\t\t%d\t\t%d\n",
					temp->person_id,			//��һ������н�����
					temp->ticket_number,		//��һ�ڴ����н�����
					temp->ticket_amount,		//��һ�ھ����н�����
					temp->ticket_dayth);		//������ں�
	
	printf("\n\t���Ĺ�Ʊ��Ϣ��\n");
	printf("\t������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\tID\t����\t�ں�\t  ����\t\t����\t����\t����״̬  �н����  ��Ʊ��� \n");
	while(temp->next !=NULL)
	{
		if(temp->next->person_id == p->id)			//�Ǳ��˵���Ϣ����ʾ
		{
			printf("\t%d\t%s\t%d",
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
			printf("\t%d\n",temp->next->ticket_sum);
		}
		temp = temp->next;
	}
}

/***************�û��޸ĸ�����Ϣ**********************
*��  �ܣ�	�û��޸ĸ�����Ϣ
*��  ����	H ���û�ע������ͷ�ڵ�-->���ڲ鿴�����Ƿ����
*��  ����	P ����ǰ��¼�û��Ľڵ�
*****************************************************/
void userself_updata(struct person *H,struct person *p)
{

	char passwd_test[8];
	char passwd_test1[8];
	char admin_passwd[8];
	char name[20];
	int i = 0,flag = 1;				//�û����Ƿ���ڱ�־ 1������

	while(menu_select !=0)
	{
		menu23();
		scanf("%d",&menu_select);
		getchar();					//��ֹ�����ַ�ʱ������ѭ��
		switch(menu_select)
		{
			case 0:					//������һ��
				break;
			case 1:					//�޸�����
					do
					{
						printf("���������û�����");
						scanf("%s",name);
						flag = check_username(H,name);	//�û����Ƿ���ڣ�1����
						if(!flag)
						{
							getchar();
							printf("ȷ���޸��û��� (y/n)?");
							if(getchar() == 'y')
							{
								save_flag = 1;			//��Ϣ������ʾ
								strcpy(p->name,name);
								printf("�޸ĳɹ�����������أ�");
								getchar();
							}
							else
							{
								printf("�ѷ����޸ģ���������أ�");
								getchar();
							}
							break;
						}
						else
						{
							printf("\n�û����Ѵ��ڣ���������%sA��\n",name);
							i++;
							if(i == 3)					//�޶��������
							{
								printf("\n@_@---> ���볬��3�Σ�������������˵��� \n");
								getchar();
								getchar();
								break;
							}
						}	
					}while(1);
					i = 0;								//case2���õ�
				break;
			case 2:										//�޸�����
					strcpy(admin_passwd,getpass("����������룺"));	
					if(strcmp(admin_passwd,p->passwd) == 0)
					{
						do
						{
							if(i>2)						//����3�Σ����������
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
								save_flag = 1;			//��Ϣ�Ѿ�����
								strcpy(p->passwd,passwd_test1);
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
					//�޸Ĺ���Ա����end
				break;
			default:	
					menu_select = 0;
					printf("\n@_@---> ѡ��������������ز˵���");
					getchar();			
				break;
		}
		if(menu_select == 0)
		{
			menu_select =2;					//�ϼ��˵�menu13��ڲ���Ϊ3
			break;							//�˳�while(),���˳�����ѭ��
		}
	}
}

/*********************************************
*��  �ܣ�	����û����Ƿ����
*��  ����	H ���û�����ͷ�ڵ�
*��  ����	name: Ҫ���ҵ�����
*����ֵ��		���ڷ���1�������ڷ���0
*********************************************/
int check_username(struct person *H,char name[20])
{
	while(H->next != NULL)
	{
		if(strcmp(H->next->name,name)==0)
			return 1;	//�д��û���
		H = H->next;
	}
	return 0;			//�޴��û���
}

/******************************************************
*��  �ܣ�	�û���Ʊ
*��  ����	p :   ��Ʊ��Ϣ��������һ�����
*��  ����	user����ǰ�û��Ľڵ�
*��  ����	H ��	  �û�����ͷ��㣬�˴�֮�õ�ͷ��㱣�潱�ؽ��
*����ֵ��		���ع�Ʊ��Ϣ��������һ�����
*******************************************************/
struct buy_ticket * user_buy_tickey(struct buy_ticket *p,struct person *user,struct person *H)
{

	struct buy_ticket *newnode=NULL;
	while(menu_select !=0)		
	{
		newnode = (struct buy_ticket *)malloc(sizeof(struct buy_ticket));
		if(newnode == NULL)
		{
			printf("����ͷ�ڵ�ʱ�ռ�������\n");
			exit(0);
		}
		newnode->next = NULL;

		printf("�����˻����Ϊ��%dԪ\n",user->person_money);
		if(user->person_money < ticket_value)		//������һ�ŵĻ��˳�
		{
			printf("���㣡������˳���");
			getchar();
			return p;
		}
		menu21();
		scanf("%d",&newnode->ticket_type); 			//ѡ��Ʊ����
		getchar();
		if(newnode->ticket_type == 0)				//0������һ��
				return p;
		printf("�������Ʊ���루1-20����");
		scanf("%d",&newnode->ticket_number);		//��Ʊ����
		printf("�����빻��������");					//��Ʊ����
		scanf("%d",&newnode->ticket_amount);
		newnode->person_id = user->id;				//id
		strcpy(newnode->person_name,user->name);	//����
		newnode->ticket_dayth = ticketdayth;		//�ں�
		newnode->ticket_status = 1;					//����״̬Ϊһ��δ��
		newnode->ticket_win = 0;					//1Ϊ�н���0Ϊδ�н�
		newnode->ticket_sum = newnode->ticket_amount * ticket_value;//ticket_valueΪ��Ʊ����
		if(newnode->ticket_sum > user->person_money)//����
		{
			printf("�˻����㣬��������أ�");
			getchar();
		}
		else					//��Ʊ�ɹ�
		{
			len_buy++;			//��Ʊ��Ϣ��1
			p->next = newnode;
			p = newnode;
			user->person_money =user->person_money - newnode->ticket_sum;		//����ȥ����
			H->person_money += newnode->ticket_sum;								//���ؽ������
			
			/***********���²�Ʊ����*****************/				
			printf("\n\t\t\t�� Ʊ �� ��\n");
			printf("\t\t*********************************\n");
			if(newnode->ticket_type == sport_ticket)
				printf("\t\t*\t  %s\t\t*\n","sport_ticket");
			else if(newnode->ticket_type == love_ticket)
				printf("\t\t*\t  %s\t\t*\n","love_ticket");
			else
				printf("\t\t*\t  %s\t\t*\n","disastor_ticket");
			printf("\t\t*  ��Ʊ�ںţ�%d ��\t\t*\n",newnode->ticket_dayth);
			printf("\t\t*  ��Ʊ���룺%d \t\t*\n",newnode->ticket_number);
			printf("\t\t*  ��Ʊ������%d ��\t\t*\n",newnode->ticket_amount);
			printf("\t\t*  �� �� �%d Ԫ\t\t*\n",newnode->ticket_sum);
			printf("\t\t*\t\t\t\t*\n");
			if(newnode->ticket_status)
			printf("\t\t*  ����״̬��δ����\t\t*\n");
			else
			{
				if(!newnode->ticket_win)	
				{
					printf("\t\t*  ����״̬���ѿ���\t\t*\n");
					printf("\t\t*  @_@ δ�н����´κ��ˣ�\t\t*\n");
				}
				else
				{
					printf("\t\t*  ����״̬���ѿ���\t\t*\n");
					printf("\t\t*  ^_^ ��ϲ���н��ˣ����Ϊ��%d\t\t*\n",newnode->ticket_amount*ticket_win_money);
				}			
				
			}
			
			printf("\t\t*\t  Made In China !\t*\n");
			printf("\t\t*********************************\n\n");
			/***********���ϲ�Ʊ����*****************/
			printf("  ���������-->");
			getchar();
			getchar();
		}	
	}
	return p;
}

/*********************************************
*��  �ܣ�	��ע���û���Ϣд���ļ�user.txt
*��  ����	H ���û�����ͷ�ڵ�
*********************************************/
void w_user_file(struct person *H)
{
	FILE *fp1;
	if((fp1 = fopen("user.txt","wt")) == NULL)
	{
		printf("w_user_file�޷������ļ�user.txt--������˳�!\n");
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

/***********************************************
*��  �ܣ�	���û���Ϣ���ļ�user.txt����
*��  ����	�û���Ϣ����ͷ�ڵ�
*����ֵ��		�������һ���ڵ����Ϣ
*  len��		len��¼�û���ID�������һ���û���ID��ʼ
*��  �⣺	�����len��ô�������һ��ID��
**************************************************/
struct person *r_user_file(struct person *H)
{
	struct person *newnode = NULL;
	struct person *p = H,*temp = NULL;
	
	FILE *fp;
	if((fp=fopen("user.txt","rt")) == NULL)
	{
		printf("r_user_file�޷����ļ�user.txt--������˳�!\n");
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
			printf("�����½ڵ�ʱ�ռ�������\n");
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
		len_user++;		//�û�����һ
	}
	fclose(fp);
	temp->next = NULL;	//����һ�����������⣬�����һ���ڵ��ͷ�
	free(p);
	len = temp->id;
	return temp;
}


/*********************************************
*��  �ܣ�	����Ʊ��Ϣд���ļ�buy.txt
*��  ����	buy_H : �û���Ʊ��Ϣͷ�ڵ�
*ע  �⣺	��ȡʱע��ͷ�ڵ�
*********************************************/
void w_buy_file(struct buy_ticket *buy_H)
{
	FILE *fp1;
	if((fp1 = fopen("buy.txt","wt")) == NULL)
	{
		printf("w_buy_file�޷������ļ�buy.txt--������˳�!\n");
		getchar();
		exit(1);
	}
	fprintf(fp1,"%d %d %d %d\n",
					buy_H->person_id,		//��һ������н�����
					buy_H->ticket_number,	//��һ�ڴ����н�����
					buy_H->ticket_amount,	//��һ�ھ����н�����
					buy_H->ticket_dayth		//������ں�
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

/*********************************************
*��  �ܣ�	����Ʊ��Ϣ���ļ�buy.txt����
*��  ����	buy_H : ��Ʊ��Ϣͷ���
*����ֵ��		�������һ��������Ϣ
*********************************************/
struct buy_ticket *r_buy_file(struct buy_ticket *buy_H)
{
	struct buy_ticket *newnode = NULL;
	struct buy_ticket *buy_p = buy_H,*temp = NULL;
	
	FILE *fp;
	if((fp=fopen("buy.txt","rt")) == NULL)
	{
		printf("r_buy_file�޷����ļ�buy.txt--������˳�!\n");
		getchar();
		exit(1);
	}
	/***********ͷ�ڵ��ʽע��,�Ѵ�����**********/
	fscanf(fp,"%d %d %d %d\n",
				&buy_H->person_id,		//��һ������н�����
				&buy_H->ticket_number,	//��һ�ڴ����н�����
				&buy_H->ticket_amount,	//��һ�ھ����н�����
				&buy_H->ticket_dayth	//������ں�
			);
	while(!feof(fp))
	{					
		newnode = (struct buy_ticket *)malloc(sizeof(struct buy_ticket));
		if(newnode == NULL)
		{
			printf("�����½ڵ�ʱ�ռ�������\n");
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
		len_buy++;				//��Ʊ��Ϣ������1
	}
	fclose(fp);
	return buy_p;
}

/**************************************************
*��  �ܣ�	������Ϣд���ļ�wininformation.txt
*��  ����	dayth,sport,love,disastor,sum
*			�ں�   ���  ����   ����    �г����
*��  ��
***************************************************/
//void w_wininformation_file(int dayth,int sport,int love,int disastor,int sum)
void w_wininformation_file(struct news temp)
{
	FILE *fp1;
	if((fp1 = fopen("wininformation.txt","at")) == NULL)
	{
		printf("w_wininformation_file�޷������ļ�wininformation.txt--������˳�!\n");
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

/*********************************************************
*��  �ܣ�	��ÿ��admin�н���Ϣ���ļ�wininformation.txt����
*��  ��
***********************************************************/

void r_wininformation_file()
{
	struct news temp;
	FILE *fp1;
	if((fp1 = fopen("wininformation.txt","rt")) == NULL)
	{
		printf("r_wininformation_file�޷������ļ�wininformation.txt--������˳�!\n");
		getchar();
		exit(1);
	}
	printf("\n\t\t���ڲ�Ʊ��Ϣ��\n");
	printf("\t\t��������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t�ں�  ������Ʊ  ���Ʋ�Ʊ  ���ֲ�Ʊ  �г����\t����\n");
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
//		fscanf(fp1,"%d %d %d %d %d\n",&dayth,&sport,&love,&disastor,&sum);
//		printf("\t\t%d\t%d\t  %d\t  %d\t\t%d\n",dayth,sport,love,disastor,sum);
		printf("\t\t%d\t%d\t  %d\t  %d\t\t%d\t%d��%d��%d��  %d-%d-%d\n",
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

/****************************************************
*��  �ܣ�	��ÿ��admin�н�����Ϣд���ļ�winer.txt
*��  ����	temp : ��ǰ�û��Ľ��		
*****************************************************/
void w_winer_file(struct buy_ticket *temp)
{
	FILE *fp1;
	if((fp1 = fopen("winer.txt","at")) == NULL)
	{
		printf("w_winer_file�޷������ļ�winer.txt--������˳�!\n");
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

/***************************************************
*��  �ܣ�	��ÿ��admin�н�����Ϣ���ļ�winer.txt����
*			����ʾ
****************************************************/

void r_winer_file()
{
	struct buy_ticket *temp = NULL;
	temp = (struct buy_ticket *)malloc(sizeof(struct buy_ticket));
	FILE *fp1;
	if((fp1 = fopen("winer.txt","rt")) == NULL)
	{
		printf("�ļ��޷��򿪻�����ʷ�н�����Ϣ--������˳�!\n");
		getchar();
		exit(0);
	}
	printf("\n\t\t�����н�����Ϣ��\n");
	printf("\t\t����������������������������������������������������������������������������������������\n");
	printf("\t\tID\t����\t�ں�\t����\t\t����\t����\t�н����\n");
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
			printf("\t������Ʊ");
		else if(temp->ticket_type == love_ticket)
			printf("\t���Ʋ�Ʊ");
		else
			printf("\t���ֲ�Ʊ");
		printf("\t%d\t%d\t%d\n",temp->ticket_number,temp->ticket_amount,temp->ticket_winmoney);
	}
	fclose(fp1);
}

/*********************************************
*��  �ܣ�	�ÿ���������visit.txt
*	
*********************************************/
void w_visit_file(int visit)
{
	FILE *fp1;
	if((fp1 = fopen("visit.txt","wt")) == NULL)
	{
		printf("w_visit_file�޷������ļ�visit.txt--������˳�!\n");
		getchar();
		exit(1);
	}
	fprintf(fp1,"%d",visit);
	fclose(fp1);
}

/*********************************************
*��  �ܣ�	�ÿ�������visit.txt����
*	
*********************************************/
int r_visit_file()
{
	int visit;
	FILE *fp1;
	if((fp1 = fopen("visit.txt","rt")) == NULL)
	{
		printf("r_visit_file�޷������ļ�visit.txt--������˳�!\n");
		getchar();
		exit(1);
	}
	fscanf(fp1,"%d",&visit);
	fclose(fp1);
	return visit;
}

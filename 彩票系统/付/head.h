#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<conio.h>
#include<windows.h>
/*-----------�궨��-------------------*/
#define user_init_money 10		//��ע���û���ʼ���
#define ticket_value 5			//ÿ�Ų�Ʊ�۸�
#define admin_init_money 500	//���س�ʼ���
#define ticket_win_money 20		//ÿ���н����
#define ticket_max 20			//�н����뷶Χ
#define sport_win 15			//������Ʊ�н����
#define love_win 20				//���Ʋ�Ʊ�н����
#define disastor_win 10			//���ֲ�Ʊ�н����

/*-------��Ʊ���Ͷ���-----------------*/
enum ticket
{
	sport_ticket = 1,
	love_ticket,
	disastor_ticket,
};

/*----------ȫ�ֱ���----------------*/
int len;			//ע���û�id
int len_user;		//ע���û���������ɾ��ʱlen != len_user����ʱ���
int len_buy;		//��Ʊ��Ϣ�������û�����
int menu_select;	//�˵�ѡ��
int save_flag;		//��Ϣ�Ƿ��иĶ���־λ
int ticketdayth;	//��Ʊ�ں�

/*----------�ṹ�嶨��----------------*/
struct person		//ע���û���������user.txt
{
	int id;
	char name[20];
	char passwd[8];
	int person_money;
	struct person *next;
};

struct buy_ticket					//��Ʊ��Ϣ��������buy_ticket.txt
{
	int person_id;
	char person_name[20];		
	int ticket_dayth;
	int ticket_type;
	int ticket_number;
	int ticket_amount;
	int ticket_status;				//1δ����,0
	int ticket_win;					//1�н���0δ�н�
	int ticket_winmoney;			//��һ���еĽ��
	int ticket_sum;					//���˵��ڹ�Ʊ�ܶ�
	struct buy_ticket *next;
};

struct winer						//�н�����Ϣ��������winer.txt
{
	int winer_id;
	char winer_name[20];
	int winer_dayth;
	int winer_money;
	struct winer *next;
};

struct news							//ÿ���н���Ϣ
{
	int dayth;
	int sport_ticket;
	int love_ticket;
	int disastor_ticket;
	int sum;
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;	
};

/*----------�˵��Ӻ�������----------------*/
void menu_build();				//��ӭ�˵�
void main_menu();				//���˵�
void menu1();					//
void menu12();					//
void menu13();					//
void menu131();					//menu13�޸Ĺ���Ա��Ϣ�Ӳ˵�
void menu14();					//
void menu15();					//
void menu2();					//
void menu21();					//menu21�û���Ʊ�Ӳ˵�
void menu23();					//menu23�޸��û�������Ϣ�Ӳ˵�
void menu_open(char *address);	//���������ʾ�Ӳ˵�
void apply_success();			//ע��ɹ���ʾ�Ӳ˵�
void thanks();					//�˳���л�Ӳ˵�
void luck_draw();				//ϵͳҡ���Ӻ���
void ht();						//�йغ�ͬ
void summary1();				//�ܽ�1����������5����,��ʾ�ṹ����;
void summary2();				//�ܽ�2����������6���ã���ʾ�˵��ṹ

void menu_open(char *address);	//�򿪲˵��ļ��Ӻ���

/*---------����Ա����Ӻ�������-----------*/
//void admin_menu1(struct person *H,struct buy_ticket *buy_H);	//menu1
void admin_menu1(struct person *H,struct buy_ticket *buy_H);	//����Ա��¼
void people_information(struct person *H);						//����Ա�鿴���������Ϣ
void admin_view(struct person *H,struct buy_ticket *buy_H);		//����Ա�鿴��Ϣ------�����д��޸�
void admin_updata(struct person *H);							//����Ա�޸���Ϣ��menu13
//void admin_deldata(struct person *H);							//����Աɾ����Ϣ��menu14
void admin_deldata(struct person *H,struct buy_ticket *buy_H);	//����Աɾ����Ϣ��menu14
//void admin_sort(struct person *H);							//����Ա����Ϣ����
void admin_sort(struct person *H,struct buy_ticket *buy_H);		//����Ա����Ϣ����
struct person * admin_find_user(struct person * H);				//����Ա����ע���û�
void admin_change_information(struct person *p);				//����Ա�޸���Ϣ��(��ַ�ɲ��Һ�������)���������û��޸ĸ�������
void adminself_updata(struct person *H);						//����Ա�޸ĸ������룬�������û��޸ĸ�������
void admin_add_money(struct person *p);							//����Ա׷�ӽ��
void admin_view_buy_news(struct buy_ticket *buy_H);				//����Ա�鿴���й�Ʊ��Ϣ
void ID_check_buynews(struct buy_ticket *buy_H);				//����Ա����id���ҹ�Ʊ��Ϣ
void dayth_check_buynews(struct buy_ticket *buy_H);				//����Ա�����ںŲ��ҹ�Ʊ��Ϣ
void id_del_buynews(struct buy_ticket *buy_H);					//����Ա����IDɾ����Ʊ��Ϣ
void type_del_buynews(struct buy_ticket *buy_H);				//����Ա��������ɾ����Ʊ��Ϣ
void dayth_del_buynews(struct buy_ticket *buy_H);				//����Ա�����ں�ɾ����Ʊ��Ϣ
void make_prize(struct person *H, struct buy_ticket *buy_H);	//����Աҡ��
void add_winer_money(struct person *H, int id,int money);		//����񽱺�׷�ӽ��
void sortfun(struct person *H,struct buy_ticket *buy_H);		//����Ա�����Ӻ���


/*----------�û�����Ӻ�������------------*/
struct person * add_user(struct person *H,struct person *p);	//���û�ע�ắ��		
struct buy_ticket * person_menu2(struct person *H,struct buy_ticket *buy_p,struct buy_ticket *buy_H);//�����¼
int check_username(struct person *H,char name[20]);				//����û����Ƿ���ڣ�����1���ڣ�0������
void userself_updata(struct person *H,struct person *p);		//�û������Լ�����Ϣ
struct buy_ticket * user_buy_tickey(struct buy_ticket *p,struct person *user, struct person *H);	//�û���Ʊ�Ӻ���		
void user_view_ticket(struct person *p,struct buy_ticket *buy_H);	//�û��鿴��Ʊ��Ϣ

/*---------����ͷ�ڵ�----------------*/
struct person * person_creat_head(struct person *H);			//�û�ע�����ͷ���
struct buy_ticket * buy_creat_head(struct buy_ticket *buy_H);	//��Ʊ��Ϣ����ͷ�ڵ�
struct news * win_creat_head(struct news *win_H);				//ÿ�ڹ�Ʊ��Ϣ����ͷ���

/*---------�ļ���������---------------*/
void w_user_file(struct person *H);								//�û���Ϣд���ļ���user.txt
struct person *r_user_file(struct person *H);					//�û���Ϣ���ļ����� from user.txt
void w_buy_file(struct buy_ticket *buy_H);						//����Ʊ��Ϣд���ļ�
struct buy_ticket *r_buy_file(struct buy_ticket *buy_H);		//����Ʊ��Ϣ�����ļ�
//void w_wininformation_file(int dayth,int sport,int love,int disastor,int sum);//ÿ���н���Ϣд���ļ�
void w_wininformation_file(struct news temp);//ÿ���н���Ϣд���ļ�
void w_winer_file(struct buy_ticket *temp);						//ÿ���н�����Ϣд���ļ�winer.txt
void r_wininformation_file();									//ÿ���н�������ļ���������ʾ
void r_winer_file();											//ÿ���н�����Ϣ���ļ���������ʾ
void w_visit_file(int visit);									//�ÿ����������ļ�
int r_visit_file();												//�ÿ���������
//�������
void gotXY(int x,int y);
int posx();
int posy();
void GetPasscode(char* pwd);
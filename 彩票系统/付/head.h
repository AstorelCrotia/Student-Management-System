#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<conio.h>
#include<windows.h>
/*-----------宏定义-------------------*/
#define user_init_money 10		//新注册用户初始金额
#define ticket_value 5			//每张彩票价格
#define admin_init_money 500	//奖池初始金额
#define ticket_win_money 20		//每柱中奖金额
#define ticket_max 20			//中奖号码范围
#define sport_win 15			//体育彩票中奖金额
#define love_win 20				//慈善彩票中奖金额
#define disastor_win 10			//救灾彩票中奖金额

/*-------彩票类型定义-----------------*/
enum ticket
{
	sport_ticket = 1,
	love_ticket,
	disastor_ticket,
};

/*----------全局变量----------------*/
int len;			//注册用户id
int len_user;		//注册用户数量，有删除时len != len_user其他时相等
int len_buy;		//购票信息数量，用户排序
int menu_select;	//菜单选择
int save_flag;		//信息是否有改动标志位
int ticketdayth;	//彩票期号

/*----------结构体定义----------------*/
struct person		//注册用户，保存在user.txt
{
	int id;
	char name[20];
	char passwd[8];
	int person_money;
	struct person *next;
};

struct buy_ticket					//购票信息，保存在buy_ticket.txt
{
	int person_id;
	char person_name[20];		
	int ticket_dayth;
	int ticket_type;
	int ticket_number;
	int ticket_amount;
	int ticket_status;				//1未开奖,0
	int ticket_win;					//1中奖，0未中奖
	int ticket_winmoney;			//买一次中的金额
	int ticket_sum;					//个人当期购票总额
	struct buy_ticket *next;
};

struct winer						//中奖人信息，保存在winer.txt
{
	int winer_id;
	char winer_name[20];
	int winer_dayth;
	int winer_money;
	struct winer *next;
};

struct news							//每期中奖信息
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

/*----------菜单子函数声明----------------*/
void menu_build();				//欢迎菜单
void main_menu();				//主菜单
void menu1();					//
void menu12();					//
void menu13();					//
void menu131();					//menu13修改管理员信息子菜单
void menu14();					//
void menu15();					//
void menu2();					//
void menu21();					//menu21用户购票子菜单
void menu23();					//menu23修改用户个人信息子菜单
void menu_open(char *address);	//密码错误提示子菜单
void apply_success();			//注册成功提示子菜单
void thanks();					//退出感谢子菜单
void luck_draw();				//系统摇奖子函数
void ht();						//有关海同
void summary1();				//总结1，主函数下5调用,显示结构体用途
void summary2();				//总结2，主函数下6调用，显示菜单结构

void menu_open(char *address);	//打开菜单文件子函数

/*---------管理员相关子函数声明-----------*/
//void admin_menu1(struct person *H,struct buy_ticket *buy_H);	//menu1
void admin_menu1(struct person *H,struct buy_ticket *buy_H);	//管理员登录
void people_information(struct person *H);						//管理员查看彩民基本信息
void admin_view(struct person *H,struct buy_ticket *buy_H);		//管理员查看信息------参数有待修改
void admin_updata(struct person *H);							//管理员修改信息，menu13
//void admin_deldata(struct person *H);							//管理员删除信息，menu14
void admin_deldata(struct person *H,struct buy_ticket *buy_H);	//管理员删除信息，menu14
//void admin_sort(struct person *H);							//管理员对信息排序
void admin_sort(struct person *H,struct buy_ticket *buy_H);		//管理员对信息排序
struct person * admin_find_user(struct person * H);				//管理员查找注册用户
void admin_change_information(struct person *p);				//管理员修改信息，(地址由查找函数传送)，可用作用户修改个人密码
void adminself_updata(struct person *H);						//管理员修改个人密码，可用作用户修改个人密码
void admin_add_money(struct person *p);							//管理员追加金额
void admin_view_buy_news(struct buy_ticket *buy_H);				//管理员查看所有购票信息
void ID_check_buynews(struct buy_ticket *buy_H);				//管理员按照id查找购票信息
void dayth_check_buynews(struct buy_ticket *buy_H);				//管理员按照期号查找购票信息
void id_del_buynews(struct buy_ticket *buy_H);					//管理员根据ID删除购票信息
void type_del_buynews(struct buy_ticket *buy_H);				//管理员根据类型删除购票信息
void dayth_del_buynews(struct buy_ticket *buy_H);				//管理员根据期号删除购票信息
void make_prize(struct person *H, struct buy_ticket *buy_H);	//管理员摇奖
void add_winer_money(struct person *H, int id,int money);		//彩民获奖后追加金额
void sortfun(struct person *H,struct buy_ticket *buy_H);		//管理员排序子函数


/*----------用户相关子函数声明------------*/
struct person * add_user(struct person *H,struct person *p);	//新用户注册函数		
struct buy_ticket * person_menu2(struct person *H,struct buy_ticket *buy_p,struct buy_ticket *buy_H);//彩民登录
int check_username(struct person *H,char name[20]);				//检测用户名是否存在，返回1存在，0不存在
void userself_updata(struct person *H,struct person *p);		//用户更改自己的信息
struct buy_ticket * user_buy_tickey(struct buy_ticket *p,struct person *user, struct person *H);	//用户购票子函数		
void user_view_ticket(struct person *p,struct buy_ticket *buy_H);	//用户查看彩票信息

/*---------产生头节点----------------*/
struct person * person_creat_head(struct person *H);			//用户注册产生头结点
struct buy_ticket * buy_creat_head(struct buy_ticket *buy_H);	//购票信息产生头节点
struct news * win_creat_head(struct news *win_H);				//每期购票信息产生头结点

/*---------文件操作函数---------------*/
void w_user_file(struct person *H);								//用户信息写入文件：user.txt
struct person *r_user_file(struct person *H);					//用户信息从文件读出 from user.txt
void w_buy_file(struct buy_ticket *buy_H);						//将购票信息写入文件
struct buy_ticket *r_buy_file(struct buy_ticket *buy_H);		//将购票信息读出文件
//void w_wininformation_file(int dayth,int sport,int love,int disastor,int sum);//每期中奖信息写入文件
void w_wininformation_file(struct news temp);//每期中奖信息写入文件
void w_winer_file(struct buy_ticket *temp);						//每期中奖人信息写入文件winer.txt
void r_wininformation_file();									//每期中奖号码从文件读出并显示
void r_winer_file();											//每期中奖人信息从文件读出并显示
void w_visit_file(int visit);									//访客数量存入文件
int r_visit_file();												//访客数量读出
//密码加密
void gotXY(int x,int y);
int posx();
int posy();
void GetPasscode(char* pwd);
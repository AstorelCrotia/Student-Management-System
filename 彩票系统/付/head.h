#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
//创建用户结构体
typedef struct Person{
    int id;
    char name[20];
    char password[20];
    int balance;
    struct Person *next;
}User;


//购票信息
struct buy_ticket
{
    int person_id;
    char person_name[20];
    int ticket_dayth;
    int ticket_type;
    int ticket_number;
    int ticket_amount;
    int ticket_status;
    int ticket_win;
    int ticket_winmoney;
    int ticket_sum;
    int mouse_ID;
	int cat_ID;
	int dog_ID;
    struct buy_ticket *next;
};

//每期中奖信息
struct news{
    int dayth;
    int mouse_ticket;
    int dog_ticket;
    int cat_ticket;
    int sum;
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
};
enum ticket
{
	mouse_ticket = 1,
	cat_ticket,
	dog_ticket,
};
//全局变量
int len;//注册用户id
int len_user;//注册用户数量
int len_buy;//购票信息数量，用户排序
int save_flag;//信息改动信号
int choice;//菜单选择
int ticketdayth;//彩票期号

//宏定义
#define user_init_money 100     //用户初始金额
#define ticket_value 5			//每张彩票价格
#define admin_init_money 500	//奖池初始金额
#define ticket_win_money 20		//每柱中奖金额
#define ticket_max 20			//中奖号码范围
#define mouse_win 15			//鼠彩票中奖金额
#define cat_win 20				//猫彩票中奖金额
#define dog_win 10			    //狗彩票中奖金额


struct Person *signup(struct Person *p , struct Person *q);//新用户注册
struct buy_ticket * signin(struct Person *p,struct buy_ticket *buy_p,struct buy_ticket *buy_q);//彩民登陆
struct buy_ticket * user_buy_ticket(struct buy_ticket *p,struct Person *user,struct Person *q);//购买彩票
void user_view_ticket(struct Person *p,struct buy_ticket *buy_p);//查看用户个人信息
void user_update(struct Person *p,struct Person *q);//用户更新信息
int check_user(char name[20],struct Person *p);//核验用户名

void admin_signin(struct Person *p,struct buy_ticket *buy_p);//管理员登录
void admin_view(struct Person *p, struct buy_ticket *buy_p);//管理员信息查询
void user_information(struct Person *p);//彩民信息查询
void view_allbuy_news(struct buy_ticket *buy_p);//所有购票信息
void ID_check_buynews(struct buy_ticket *buy_p);//根据ID查找购票信息
void dayth_check_buynews(struct buy_ticket *buy_p);//根据期号查找购票信息
void Game(struct Person *p, struct buy_ticket *buy_p);//摇号
void add_winmoney(struct Person *p, int id, int money);//奖池累加
void w_winer_file(struct buy_ticket *temp);//保存中奖人信息
void w_wininformation_file(struct news temp);//保存开奖信息
void r_wininformation_file();//读取开奖信息
void r_winner_file();//读取中奖人信息
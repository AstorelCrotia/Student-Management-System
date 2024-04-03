#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>
#include <ctype.h>
#ifndef YOUR_HEADER_FILE_NAME_H
#define YOUR_HEADER_FILE_NAME_H
// 用户结构体;
typedef struct Person
{
    int id;
    char name[20];
    char password[20];
    int balance;
    struct Person *next;
} User;

// 购票结构体;
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
    struct buy_ticket *next;
};

// 彩票结构体;
struct news
{
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
// 全局变量;
int len;         // 注册用户id
int len_user;    // 注册用户数量
int len_buy;     // 购票信息数量，用户按顺序排列
int save_flag;   // 信息是否有改动标志位
int choice;      // 菜单选择
int ticketdayth; // 彩票期号
char ch;

// 价格宏定义;
#define user_init_money 10   // 新注册用户初始值
#define ticket_value 5       // 每张彩票价格
#define admin_init_money 500 // 奖池初始金额
#define ticket_win_money 20  // 每柱中奖金额
#define ticket_max 20        // 中奖号码范围
#define mouse_win 15
#define cat_win 20
#define dog_win 10

struct buy_ticket *buy_creat_head(struct buy_ticket *buy_h);                                     // 购票头节点;
struct Person *r_user_file(struct Person *h);                                                    // 创建和读取用户链表;
struct buy_ticket *r_buy_file(struct buy_ticket *buy_h);                                         // 读取用户购票链表;
struct Person *person_creat_head(struct Person *h);                                              // 创建头节点;
struct Person *signup(struct Person *p, struct Person *q);                                       // 新用户注册;
struct buy_ticket *signin(struct Person *p, struct buy_ticket *buy_p, struct buy_ticket *buy_q); // 彩民登陆;
struct buy_ticket *user_buy_ticket(struct buy_ticket *p, struct Person *user, struct Person *q); // 彩民购票;
struct Person *admin_user(struct Person *p);                                                     // 管理员查找需要修改用户信息;
void admin_change(struct Person *p);                                                             // 管理员修改所查找的用户信息;
void user_view_ticket(struct Person *p, struct buy_ticket *buy_p);                               // 用户查询购票信息;
void user_update(struct Person *p, struct Person *q);                                            // 用户更新信息;
int check_user(char name[20], struct Person *p);                                                 // 比对用户信息;

void admin_signin(struct Person *p, struct buy_ticket *buy_p); // 管理员登陆;
void admin_view(struct Person *p, struct buy_ticket *buy_p);   // 管理员查陆;
void admin_updata(struct Person *p);                           // 管理员更新信息操作界面;
void adminself_updata(struct Person *p);                       // 管理员自我信息更新;
void admin_delete(struct Person *p, struct buy_ticket *buy_p); // 管理员删除信息;
void admin_sort(struct Person *p, struct buy_ticket *buy_p);   // 管理员排序购票信息;
void sortfun(struct Person *H, struct buy_ticket *buy_H);      // 管理员按不同方式排序;
void user_information(struct Person *p);                       // 打印用户信息;
void admin_add_money(struct Person *p);                        // 管理员添加奖池奖金;
void view_allbuy_news(struct buy_ticket *buy_p);               // 查询所有购票信息;
void ID_check_buynews(struct buy_ticket *buy_p);               // 以ID查询购票信息;
void id_del_buynews(struct buy_ticket *buy_p);                 // 以ID删除彩票信息;
void dayth_check_buynews(struct buy_ticket *buy_p);            // 以期号查询购票信息;
void dayth_del_buynews(struct buy_ticket *buy_p);              // 以期号删除彩票信息;
void type_del_buynews(struct buy_ticket *buy_p);               // 以类型删除彩票信息;
void Game(struct Person *p, struct buy_ticket *buy_p);         // 摇奖;
void add_winmoney(struct Person *p, int id, int money);        // 添加奖池奖金;
void mask_password(char *password);                           // 密码加密不可见;

void w_visit_file(int visit);                 // 记录访客数量
int r_visit_file();                           // 读取访客数量
void w_buy_file(struct buy_ticket *buy_H);    // 写入用户购票信息
void w_user_file(struct Person *h);           // 写入用户基本信息
void w_winer_file(struct buy_ticket *temp);   // 录入赢家用户信息
void w_wininformation_file(struct news temp); // 录入赢家信息
void r_wininformation_file();                 // 读取赢家信息
void r_winner_file();                         // 读取赢家用户信息
#endif
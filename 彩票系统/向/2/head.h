#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct User
{
    char uid[20];
    char code[20];
    float balance;
    struct User *next;
} User;

typedef struct Revenue
{
    char uid[20];
    char buydate[20];
    int category;
    float money;
    struct Revenue *next;
} Revenue;

typedef struct Lottery
{
    char tid[25];
    char uid[20];
    char did[20];
    int category;
    char usernumber[20];
    char winnumber[20];
    int draw;
    int win;
    char buydate[20];
    char windate[20];
    struct Lottery *next;
} Lottery;

void InbuyDate(Lottery *date);                    // 写入购买日期
void InwinDate(Lottery *date);                    // 写入开奖日期
void Initialface(int *sc);                        // 初始界面
void Initialization();                            // 系统初始化，写入超管
void Validation(char *id, int *group);            // 验证用户名功能
void Mjudgment(int *sc, int *group, char *id);    // 登录前界面选择判断
void userjudgment(int *sc, int *group, char *id); // 登录后界面选择判断
void Registeruser();                              // 用户注册
void Registeradmin();                             // 管理员注册
void Adminface(int *sc, char *id);                // 管理员界面
void Superface(int *sc);                          // 超管界面
void Userface(int *sc, char *id);                 // 用户界面
void Back(int *sc);                               // 返回初始界面
void adminQuery(int *sc);                         // 管理员查询
void userQuery(int *sc, char *id);                // 用户查询
void conditionQueryuser();                        // 条件查询用户
void allQueryuser();                              // 查询所有用户信息
void Showuser(char *id);                          // 用户查询自己信息
void adminModify(int *sc);                        // 修改界面
void admincodeModify();                           // 管理员密码修改
void usercodeModify(char *id);                    // 用户密码修改
void usermoneyModify(char *id, int flag);         // 用户余额修改
void adminmoneyModify();                          // 余额修改
void Delete(int *sc);                             // 删除界面
void Deleteuser();                                // 删除功能
void winlottery(int *sc);                         // 彩票开奖
void Buy(int *sc, char *id);                      // 购买彩票
void buyModify(char *id, float money, int *sc);   // 购买时余额修改
void didDate(Lottery *date1, Lottery *date2);     // 期号生成
void Buyin(Lottery *lottery, char *id, int sc,Lottery *oldlottery);   // 购买写入
void winlotteryin1();                             // 彩票开奖写入1
void winlotteryin2();                             // 彩票开奖写入2
void winlotteryin3();                             // 彩票开奖写入3
void conditionQuerybuy();                         // 条件查询购票历史
void conditionQuerywin();                         // 条件查询历史开奖
void allnQueryubuy();                             // 查询所有历史购票
void allQuerywin();                               // 查询所有历史中奖
void Querymoney();                                // 查询彩票中心营收
void conditionQueryuserbuy(char *id);             // 用户查询所有购票历史
void userQuerywin(char *id);                      // 用户查询所有历史中奖
void Prize(Lottery *lottery, int *ran, float n);  // 兑奖
void revenue(float money, Lottery *lottery);      // 营收操作
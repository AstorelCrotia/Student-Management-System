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

typedef struct lottery
{
    char tid[20];
    char uid[20];
    char did[20];
    int category;
    char number[20];
    int draw;
    int win;
    time_t buydate;
    time_t windate;
    struct lottery *next;
} lottery;

void InDate(lottery *date);//写入日期
void OutDate(lottery *date);//读出日期
void Initialface(int *sc);//初始界面
void Initialization();//系统初始化，写入超管
void Validation(char *id, int *group); // 验证用户名功能
void Mjudgment(int *sc,int *group,char *id); // 登录前界面选择判断
void userjudgment(int *sc, int *group, char *id);// 登录后界面选择判断
void Registeruser();// 用户注册
void Registeradmin();// 管理员注册
void Adminface(int *sc,char *id); //管理员界面
void Superface(int *sc); //超管界面
void Userface(int *sc,char *id); //用户界面
void Back(int *sc); //返回初始界面
void adminQuery(int *sc); // 管理员查询
void userQuery(int *sc); // 用户查询
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct User
{
    char uid[20];
    char code[20];
    float balance;
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
    time_t date;
} lottery;

void InDate(lottery *date);//写入日期
void OutDate(lottery *date);//读出日期
void Initialface(char *id);//初始界面
void Initialization();//系统初始化，写入超管
void Validation(char *id, int *group); // 验证用户名功能
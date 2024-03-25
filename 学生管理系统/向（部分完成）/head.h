#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Student//定义学生结构体
{
    char username[20];
    char name[20];
    char gender[10];
    char code[20];
    char class[20];
    float math;
    float chinese;
    float english;
    int age;
    int rank;
    float sum;
    struct Student * next; 
} Student;

typedef struct Administrator //定义管理者结构体
{
    char username[20];
    char code[20];
    struct Administrator * next; 
} Administrator;

void Initialface(char *username);//初始界面
void Validation(char *username,int *usergroup,int *sc);//验证功能
void Interface(int usergroup,char *username);//登录显示界面
void Input(int usergroup);//录入功能
void Query(Student s1);//查询功能
void Modify(int usergroup,char username);//修改功能
void Delete(int usergroup,char username);//删除功能
void scan(Student *s1);//键盘录入函数
Student* createlist();//链表的创建

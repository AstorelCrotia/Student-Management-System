#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct //定义学生结构体
{
    char id[20];
    char name[20];
    char gender[10];
    int code[20];
    char class[20];
    int math;
    int chinese;
    int english;
    int age;
    struct Student * next; 
} Student;

typedef struct //定义管理者结构体
{
    char username[20];
    int code[20];
} Administrator;

void Initialface();//初始界面
void Validation(int username);//验证功能
int Interface(int usergroup,char username);//登录显示界面
int Input(int usergroup,char username);//录入功能
int Query(Student s1);//查询功能
int Modify(int usergroup,char username);//修改功能
int Delete(int usergroup,char username);//删除功能
Student* createlist();//链表的创建

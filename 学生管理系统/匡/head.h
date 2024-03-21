#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
typedef struct  studentlist{
    char id[20];
    char name[20];
    char gender[10];
    char code[20];
    char class[20];
    int math;
    int chinese;
    int english;
    int age;
    int rank;
    int sum;
    struct studentlist *next;
}StudentList;
typedef struct administratorlist{
    char username[20];
    char code[20];
    struct administratorlist *next;    
} Administratorlist;
//将文件中的数据写入链表
Administratorlist *CreateAdminList();//从admintxt获取创建链表
Administratorlist * CreateAdminList1();//录入超级管理员的，可以不管
StudentList * CreateStuList() ;//从studenttxt获取创建链表
//初始页面选项
int Initialface();
//管理员与学生登录与验证
int ValidationAdmin(Administratorlist *Admin);//管理员登录，判断超级管理和普通管理
char *ValidationStu(StudentList *Student);//学生登录，返回学生姓名
//密码掩盖 concealCode.c
void gotXY(int x,int y);
int posx();
int posy();
void GetPasscode(char* code);
//解密与加密密码
char *decrypt(char *code);//解密
char *encrypt(char *code);//加密
//管理员与学生功能面板
void InterfaceAdmin(int usergroup,Administratorlist *admin,StudentList *student);//管理调用函数
void InterfaceStudent(StudentList *student,char *id);//学生
void supAdminFunc(Administratorlist *admin,StudentList *student);//超级管理的功能
void AdminFunc(StudentList *student);//普通
void studentFunc(StudentList *student,char *id);//学生
//功能实现
void InputAdmin(Administratorlist *a);//添加管理员
int checkAdminExistence(char *name,Administratorlist *admin);//查询管理员是否存在
void inPutAdminTxt(Administratorlist *head);//保存到文件admin.txt
//
void InputStu(StudentList *s);//添加学生
void  getSumScore(StudentList *student);//获得学生总分
int checkStuExistence(char *id,StudentList *student);//查询学号是否重复
void inPutStuTxt(StudentList *head);//放入学生txt
//查询操作
int getStu_Count(StudentList *student);//学生人数
void QueryStu(StudentList *student);//查询面板
void QueryStuByRankDown(StudentList *student);//名次降序
void QueryStuByRankUp(StudentList *student);//名次升序
void QueryStuByName(StudentList *student);//姓名排序
void QueryStuByClass(StudentList *student);//班级排序
void QueryStuById(StudentList *student);//学号排序
//修改学生信息
void ModifyStu(StudentList *student);//先查询学生，修改学生信息
void ModifyStuCode(StudentList *student,char *id);//修改密码
//删除学生
void Delete(StudentList *student);

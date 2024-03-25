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
// 将文件中的数据写入链表
Administratorlist *CreateAdminList();
Administratorlist * CreateAdminList1();
StudentList * CreateStuList() ;
// 初始界面管理
int Initialface();
// 管理员与学生登录与验证
int ValidationAdmin(Administratorlist *Admin);
char *ValidationStu(StudentList *Student);
// 密码掩盖 concealCode.c
void gotXY(int x,int y);
int posx();
int posy();
void GetPasscode(char* code);
// 解密与加密密码
char *decrypt(char *code);//解密
char *encrypt(char *code);//加密
// 管理员与学生管理系统
void InterfaceAdmin(int usergroup,Administratorlist *admin,StudentList *student);
void InterfaceStudent(StudentList *student,char *id);
void supAdminFunc(Administratorlist *admin,StudentList *student);
void AdminFunc(StudentList *student);
void studentFunc(StudentList *student,char *id);
// 功能实现
void InputAdmin(Administratorlist *a);// 添加管理员
int checkAdminExistence(char *name,Administratorlist *admin);// 查询管理员是否存在
void inPutAdminTxt(Administratorlist *head);//保存到文件admin.txt
//
void InputStu(StudentList *s);// 添加学生
void  getSumScore(StudentList *student);// 获得学生总分
int checkStuExistence(char *id,StudentList *student);//查询学号是否重复
void inPutStuTxt(StudentList *head);//放入学生txt
// 查询操作
int getStu_Count(StudentList *student);// 学生人数
void QueryStu(StudentList *student);// 查询面板
void QueryStuByRankDown(StudentList *student);// 名次降序
void QueryStuByName(StudentList *student,char name[]);// 根据姓名查询
void QueryStuById(StudentList *student,int id);// 根据学号查询
void QueryStuByChinese(StudentList *student,int chinese);// 根据语文成绩查询
void QueryStuByMath(StudentList *student,int math);// 根据数学成绩查询
void QueryStuByEnglish(StudentList *student,int english);// 根据外语成绩查询
void QueryStuByRank(StudentList *student,int rank);// 根据总排名查询
// 修改学生信息
void ModifyStu(StudentList *student);
void ModifyStuCode(StudentList *student,char *id);
// 删除学生
void Delete(StudentList *student);

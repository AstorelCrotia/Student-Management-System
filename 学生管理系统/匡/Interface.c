#include "head.h"

void InterfaceAdmin(int usergroup,Administratorlist *admin,StudentList *student) //界面
{
    if(usergroup == 1){
        supAdminFunc(admin,student);
    }
    if(usergroup == 2)
    {
        AdminFunc(student);
    }
}
void InterfaceStudent(StudentList *student,char *name){
    studentFunc(student,name);
}
void supAdminFunc(Administratorlist *admin,StudentList *student){
    int sc=0;
    printf("欢迎超级管理员登录学生管理系统！\n");
    while(1)
    {
        printf("************************************\n");
        printf("增添管理信息输入“1”        录入学生信息输入“2”\n");
        printf("查询学生信息输入“3”        修改学生信息输入“4”\n");
        printf("删除学生信息输入“5”        退出管理系统输入“6”\n");
        scanf("%d",&sc);
        switch (sc)
        {
        case 1:InputAdmin(admin);
            break;
        case 2:InputStu(student);
            break;
        case 3:QueryStu(student);
            break;
        case 4:ModifyStu(student);
            break;
        case 5:Delete(student);
            break;
        case 6:exit(1);
        default:
            break;
        }
    }
}
void AdminFunc(StudentList *student){
    int sc=0;
    printf("欢迎管理员登录学生管理系统！\n");
    while(1){
        printf("************************************\n");
        printf("录入学生信息输入“1”        查询学生信息输入“2”\n");
        printf("修改学生信息输入“3”        删除学生信息输入“4”\n");
        printf("退出管理系统输入“5“\n");
        printf("请选择你需要的功能：");
        scanf("%d",&sc);
        switch (sc)
        {
        case 1:InputStu(student);
            break;
        case 2:QueryStu(student);
            break;
        case 3:ModifyStu(student);
            break;
        case 4:Delete(student);
            break;
        case 5:exit(1);
        default:
            break;
        }
    }
}
void studentFunc(StudentList *student,char *name){
    int sc=0;
    printf("欢迎学生登录学生管理系统！\n");
    while(1){
        printf("************************************\n");
        printf("查询信息输入“1”        修改密码输入“2”\n");
        printf("退出管理系统输入“3”\n");
        printf("请选择你需要的功能：");
        scanf("%d",&sc);
        switch (sc)
        {
        case 1:QueryStu(student);
            break;
        case 2:;

            break;
        case 3:exit(1);
        default:
            break;
        }
    }
}
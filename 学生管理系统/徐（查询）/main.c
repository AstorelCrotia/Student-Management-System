#include <stdio.h>
#include "head.h"
int main()
{   
    Administratorlist *a=CreateAdminList();
    StudentList *s=CreateStuList();
    int loginSelect=Initialface();//登录选项
    int usergroup=0;//学生还是//管理员
    int funcSelect=0;//功能选项
    char *id;
    switch (loginSelect)
    {
    case 1:usergroup=ValidationAdmin(a);
            InterfaceAdmin(usergroup,a,s);// 管理员界面
        break;
    case 2:id=ValidationStu(s);
            InterfaceStudent(s,id);//  学生界面
            break;
    default:
        break;
    }
}
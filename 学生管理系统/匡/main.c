#include <stdio.h>
#include "head.h"
int main()
{   
    Administratorlist *a=CreateAdminList();
    StudentList *s=CreateStuList();
    int loginSelect=Initialface();//��¼ѡ��
    int usergroup=0;//ѧ������//����Ա
    int funcSelect=0;//����ѡ��
    char *name;
    switch (loginSelect)
    {
    case 1:usergroup=ValidationAdmin(a);
            InterfaceAdmin(usergroup,a,s);
        break;
    case 2:name=ValidationStu(s);
            InterfaceStudent(s,name);
            break;
    default:
        break;
    }
}
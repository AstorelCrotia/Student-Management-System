#include <stdio.h>
#include "head.h"
int main()
{   
    Administratorlist *a=CreateAdminList();
    StudentList *s=CreateStuList();
    int loginSelect=Initialface();//��¼ѡ��
    int usergroup=0;//ѧ������//����Ա
    int funcSelect=0;//����ѡ��
    char *id;
    switch (loginSelect)
    {
    case 1:usergroup=ValidationAdmin(a);
            InterfaceAdmin(usergroup,a,s);// ����Ա����
        break;
    case 2:id=ValidationStu(s);
            InterfaceStudent(s,id);//  ѧ������
            break;
    default:
        break;
    }
}
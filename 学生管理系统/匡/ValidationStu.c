#include "head.h"
char *ValidationStu(StudentList *Student) //��֤����
{
    StudentList *trueuser=Student;
    char name[20]="0";
    char code[20]="0";
    int flag = 2;
    int sc=0;
    printf("������ѧ���û�����");
    scanf("%s",name);
    while(trueuser!=NULL)
    {   
        if(!strcmp(trueuser->name,name)){
            break;
        }
        trueuser=trueuser->next;
        if(trueuser==NULL)
        {
            printf("ѧ���˻�������,����������!\n");
            printf("������ѧ���û�����");
            scanf("%s",name);
            trueuser=Student;
        }
    }
    printf("���������룺");
    GetPasscode(code);
    char *trueCode=decrypt(trueuser->code);//��ý��ܺ������
    while (strcmp(trueCode,code)){
        if(flag==0){
            printf("������Ĵ��������������,�����Զ��˳�\n");
            exit(1);
        }
        else if(!strcmp(trueCode,code)){
            printf("\n��¼�ɹ���\n");
        }
        else{
            printf("�������,�㻹��%d���������,�������������룡\n",flag);
            printf("���������룺");
            GetPasscode(code);
            flag--;
        }
    }
    char *p=name;
    return p; 
}
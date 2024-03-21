#include "head.h"
char *ValidationStu(StudentList *Student) //验证功能
{
    StudentList *trueuser=Student;
    char name[20]="0";
    char code[20]="0";
    int flag = 2;
    int sc=0;
    printf("请输入学生用户名：");
    scanf("%s",name);
    while(trueuser!=NULL)
    {   
        if(!strcmp(trueuser->name,name)){
            break;
        }
        trueuser=trueuser->next;
        if(trueuser==NULL)
        {
            printf("学生账户不存在,请重新输入!\n");
            printf("请输入学生用户名：");
            scanf("%s",name);
            trueuser=Student;
        }
    }
    printf("请输入密码：");
    GetPasscode(code);
    char *trueCode=decrypt(trueuser->code);//获得解密后的密码
    while (strcmp(trueCode,code)){
        if(flag==0){
            printf("您输入的错误次数等于三次,程序自动退出\n");
            exit(1);
        }
        else if(!strcmp(trueCode,code)){
            printf("\n登录成功！\n");
        }
        else{
            printf("密码错误,你还有%d次输入机会,请重新输入密码！\n",flag);
            printf("请输入密码：");
            GetPasscode(code);
            flag--;
        }
    }
    char *p=name;
    return p; 
}
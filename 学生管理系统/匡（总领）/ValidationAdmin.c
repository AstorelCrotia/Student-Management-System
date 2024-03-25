#include "head.h"
int ValidationAdmin(Administratorlist *Admin) //验证功能
{
    Administratorlist *trueuser=Admin;
    Administratorlist *sup=Admin;
    char name[20]="0";
    char code[20]="0";
    int flag = 2;
    int sc=0;
    printf("请输入管理员用户名：");
    scanf("%s",name);
    while(trueuser!=NULL)
    {   
        if(!strcmp(trueuser->username,name)){
            break;
        }
        trueuser=trueuser->next;
        if(trueuser==NULL)
        {
            printf("管理员账户不存在,请重新输入!\n");
            printf("请输入管理员用户名：");
            scanf("%s",name);
            trueuser=Admin;
        }
    }
    printf("请输入密码：");
    GetPasscode(code);
    char *trueCode=decrypt(trueuser->code);//获得解密后的密码
    while (1)
    {
        if(flag==0){
            printf("\n您输入的错误次数等于三次,程序自动退出\n");
            exit(1);
        }
        if(!strcmp(trueCode,code)&&!strcmp(trueuser->username,sup->username)){
            printf("\n登录成功！\n");
            sc=1; 
            break;
        }else if(!strcmp(trueCode,code)){
            printf("\n登录成功！\n");
            sc=2;
            break;
        }else{
            printf("\n密码错误,你还有%d次输入机会,请重新输入密码！\n",flag);
            printf("请输入密码：");
            GetPasscode(code);
            flag--;
        }
    }
    return sc;
}
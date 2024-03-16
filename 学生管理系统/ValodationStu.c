#include "head.h"

int ValidationStu() //验证功能
{
    Administrator tureuser;
    char name[20]="0";
    char code[20]="0";
    int flag = 2;
    int sc=0;
    FILE* file_read = fopen("users.txt","r");
    if(file_read == NULL)
    {
        printf("连接服务器失败！\n");
        return;
    }
    fread(&tureuser,sizeof(Administrator),1,file_read);
    printf("请输入学生用户名：");
    scanf("%s",name);
    while(1)
    {
        if(!strcmp(tureuser.username,name)){
            break;
        }else{
            if(!feof(file_read)){
                fread(&tureuser,sizeof(Administrator),1,file_read);
            }else{
                printf("学生账户不存在,请重新输入!\n");
                printf("请输入学生用户名：");
                scanf("%s",name);
            }
        }
    }
    printf("请输入密码：");
    scanf("%s",code);
    while (strcmp(tureuser.code,code)){
        getPassCode(tureuser.code);
        if(!strcmp(tureuser.code,code)){
            sc=1;
            return sc; 
        }else if(flag==0){
            printf("您输入的错误次数等于三次,程序自动退出\n");
            exit(1);
        }
        else{
            printf("密码错误,你还有%d次输入机会,请重新输入密码！\n",flag);
            printf("请输入密码：");
            scanf("%s",code);
            flag--;
        }
    }
}
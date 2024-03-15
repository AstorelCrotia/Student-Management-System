#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct adminSys{
    char name[20];
    char passWord[10];
    struct adminSys *next;   
}adminPerson;
adminPerson *sysPerson;
void *creat(){
    sysPerson=malloc(sizeof(adminPerson));
    strcpy(sysPerson->name,"admin");
    strcpy(sysPerson->passWord,"123456");
    sysPerson->next=NULL;
}
void logIn(){
    char supName[20];
    char passWord[10];
    int i=3;
    printf("欢迎进入学生管理系统\n");
    printf("请输入超级管理人的用户名：");
    scanf("%s",supName);
    printf("请输入超级管理人的密码：");
    scanf("%s",passWord);
    while (((strcmp(sysPerson->name,supName))!=0)||((strcmp(sysPerson->passWord,passWord))!=0)){
        if(i==0){
            printf("错误次数已到上限,请确认后再进行登录\n");
            exit(1);
        }
        printf("输入的用户名或密码错误，你还有%d次输入机会\n",i);
        printf("请重新输入姓名:");
        scanf("%s",supName);
        printf("请重新输入密码:");
        scanf("%s",passWord);
        i--;
    }
    printf("登录成功\n");
}
int  sysFnc(){
    int select;
    while(1){
        printf("**请选择您需要使用的功能**\n");
        printf("*******1.注册管理员*******\n");
        printf("*******2.查询管理员*******\n");
        printf("*******3.修改管理员信息***\n");
        printf("*******4.退出程序*********\n");
        scanf("%d",&select);
        if(select==1||select==2||select==3||select==4){
            break;
        }else{
            printf("输入选项有误，请重新输入\n");
        }
    }
    return select;
}
void addSysPerson(){
    char name[20];
    char password1[20];
    char password2[20];
    printf("请输入管理员用户名：");
    scanf("%s",name);
    while(1){
    printf("请输入管理员密码：");
    scanf("%s",password1);
    printf("请再次输入管理员密码：");
    scanf("%s",password2);
    if(strcmp(password1,password2)==0){
        break;
    }else{
        printf("第一次输入密码与第二次输入密码不一致,请重新输入\n");
    }
    }
    adminPerson *p=malloc(sizeof(adminPerson));
    adminPerson *t=sysPerson;
    strcpy(p->name,name);
    strcpy(p->passWord,password1);
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=p;
    t=p;
    t->next=NULL;
}
void inqurePerson(){
    adminPerson *p=sysPerson;
    while(p!=NULL){
        printf("姓名：%s,密码：%s\n",p->name,p->passWord);
        p=p->next;
    }
}
void updataPerson(){
    char name[20];
    char passWord[20];
    printf("请输入需要修改的管理员姓名：");
    scanf("%s",name);
    adminPerson *t=sysPerson;
    while(strcmp(t->name,name)!=0){
        t=t->next;
        if(t==NULL){
            printf("您输入的管理员不存在，请重新输入：");
            scanf("%s",name);
            t=sysPerson;
        }
    }
    printf("请输入该管理员密码：");
    scanf("%s",passWord);
    int i;
    for(i=3;i>=0;i--){
        if(strcmp(t->passWord,passWord)!=0){
            if(i==0){
                printf("错误次数超过次数,请确认后重新输入");
                return;
            }
            printf("密码错误，您还有%d次机会,请重新输入：",i);
            scanf("%s",passWord);
        }else{
            break;
        }
    }
    int flag=0;
    while(1){
    printf("请选择需要进行修改的信息\n");
    printf("1.管理员姓名\n");
    printf("2.管理员密码\n");
    printf("3.退出\n");
    scanf("%d",&i);
    while(i!=1&&i!=2&&i!=3){
        printf("输入选项错误,请重新输入：\n");
        printf("1.管理员姓名\n");
        printf("2.管理员密码\n");
        scanf("%d",&i);
    }
    if(i==1){
        printf("输入改名的管理员姓名：");
        scanf("%s",t->name);
        printf("修改成功，修改后的管理姓名：%s,密码：%s",t->name,t->passWord);
    }else if(i==2){
        printf("输入改名的管理员密码：");
        scanf("%s",t->passWord);
        printf("修改成功，修改后的管理姓名：%s,密码：%s",t->name,t->passWord);
    }else{
        flag=1;
        break;
    }
    if(flag==1){
        break;
    }
    }
}
int main(){
    creat();
    logIn();
    while(1){
    int select=sysFnc();
    if(select==1){
        addSysPerson();
    }else if(select==2){
        inqurePerson();
    }else if(select==3){
        updataPerson();
    }
    else{
        break;
    }
    }
}
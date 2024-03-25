#include "head.h"
void InputAdmin(Administratorlist *admin){//添加管理员
    char name[20]={"0"};
    char code1[20]={"0"};
    char code2[20]={"0"};
    Administratorlist *head=admin;
    while(head->next!=NULL){
        head=head->next;
    }
    while(1){
        printf("请输入管理员用户名：");
        scanf("%s",name);
        int i=checkAdminExistence(name,admin);
        if(i==1){
            printf("管理员已经存在，请重新输入需添加的用户名!\n");
        }else if(i==0){
            break;
        }
    }
    Administratorlist *newadmin=malloc(sizeof(Administratorlist));
    strcpy(newadmin->username,name);
    while(1){
        printf("请输入密码:");
        GetPasscode(code1);
        printf("\n请再次输入密码:");
        GetPasscode(code2);
        if(!strcmp(code1,code2)){
            break;
        }else{
            printf("\n两次输入的密码不一致,请重新输入！\n");
        }
    }
    char *truecode=encrypt(code1);
    strcpy(newadmin->code,truecode);
    newadmin->next=NULL;
    head->next=newadmin;
    head=newadmin;
    inPutAdminTxt(admin);
    printf("\n添加成功!\n");
}
int checkAdminExistence(char *name,Administratorlist *admin) //验证功能
{   
    int i=0;
    Administratorlist *head=admin;
    while(head!=NULL){
        if(!strcmp(head->username,name)){
            i=1;
            return i; 
        }
        head=head->next;
    }
    i=0;
    return i;
}
void inPutAdminTxt(Administratorlist *head){
    Administratorlist *p=head;
    FILE *fp=fopen("admin.txt","w");
    if(fp==NULL){
        printf("连接服务器失败！");
        return;
    }while(p!=NULL){
        fprintf(fp,"姓名：%s 密码：%s \n",p->username,p->code);
        p=p->next;
    }
    fclose(fp);
    fp=NULL;
}
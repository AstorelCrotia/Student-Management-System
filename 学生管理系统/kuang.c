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
    printf("��ӭ����ѧ������ϵͳ\n");
    printf("�����볬�������˵��û�����");
    scanf("%s",supName);
    printf("�����볬�������˵����룺");
    scanf("%s",passWord);
    while (((strcmp(sysPerson->name,supName))!=0)||((strcmp(sysPerson->passWord,passWord))!=0)){
        if(i==0){
            printf("��������ѵ�����,��ȷ�Ϻ��ٽ��е�¼\n");
            exit(1);
        }
        printf("������û�������������㻹��%d���������\n",i);
        printf("��������������:");
        scanf("%s",supName);
        printf("��������������:");
        scanf("%s",passWord);
        i--;
    }
    printf("��¼�ɹ�\n");
}
int  sysFnc(){
    int select;
    while(1){
        printf("**��ѡ������Ҫʹ�õĹ���**\n");
        printf("*******1.ע�����Ա*******\n");
        printf("*******2.��ѯ����Ա*******\n");
        printf("*******3.�޸Ĺ���Ա��Ϣ***\n");
        printf("*******4.�˳�����*********\n");
        scanf("%d",&select);
        if(select==1||select==2||select==3||select==4){
            break;
        }else{
            printf("����ѡ����������������\n");
        }
    }
    return select;
}
void addSysPerson(){
    char name[20];
    char password1[20];
    char password2[20];
    printf("���������Ա�û�����");
    scanf("%s",name);
    while(1){
    printf("���������Ա���룺");
    scanf("%s",password1);
    printf("���ٴ��������Ա���룺");
    scanf("%s",password2);
    if(strcmp(password1,password2)==0){
        break;
    }else{
        printf("��һ������������ڶ����������벻һ��,����������\n");
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
        printf("������%s,���룺%s\n",p->name,p->passWord);
        p=p->next;
    }
}
void updataPerson(){
    char name[20];
    char passWord[20];
    printf("��������Ҫ�޸ĵĹ���Ա������");
    scanf("%s",name);
    adminPerson *t=sysPerson;
    while(strcmp(t->name,name)!=0){
        t=t->next;
        if(t==NULL){
            printf("������Ĺ���Ա�����ڣ����������룺");
            scanf("%s",name);
            t=sysPerson;
        }
    }
    printf("������ù���Ա���룺");
    scanf("%s",passWord);
    int i;
    for(i=3;i>=0;i--){
        if(strcmp(t->passWord,passWord)!=0){
            if(i==0){
                printf("���������������,��ȷ�Ϻ���������");
                return;
            }
            printf("�������������%d�λ���,���������룺",i);
            scanf("%s",passWord);
        }else{
            break;
        }
    }
    int flag=0;
    while(1){
    printf("��ѡ����Ҫ�����޸ĵ���Ϣ\n");
    printf("1.����Ա����\n");
    printf("2.����Ա����\n");
    printf("3.�˳�\n");
    scanf("%d",&i);
    while(i!=1&&i!=2&&i!=3){
        printf("����ѡ�����,���������룺\n");
        printf("1.����Ա����\n");
        printf("2.����Ա����\n");
        scanf("%d",&i);
    }
    if(i==1){
        printf("��������Ĺ���Ա������");
        scanf("%s",t->name);
        printf("�޸ĳɹ����޸ĺ�Ĺ���������%s,���룺%s",t->name,t->passWord);
    }else if(i==2){
        printf("��������Ĺ���Ա���룺");
        scanf("%s",t->passWord);
        printf("�޸ĳɹ����޸ĺ�Ĺ���������%s,���룺%s",t->name,t->passWord);
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
#include "head.h"
void InputAdmin(Administratorlist *admin){//��ӹ���Ա
    char name[20]={"0"};
    char code1[20]={"0"};
    char code2[20]={"0"};
    Administratorlist *head=admin;
    while(head->next!=NULL){
        head=head->next;
    }
    while(1){
        printf("���������Ա�û�����");
        scanf("%s",name);
        int i=checkAdminExistence(name,admin);
        if(i==1){
            printf("����Ա�Ѿ����ڣ���������������ӵ��û���!\n");
        }else if(i==0){
            break;
        }
    }
    Administratorlist *newadmin=malloc(sizeof(Administratorlist));
    strcpy(newadmin->username,name);
    while(1){
        printf("����������:");
        GetPasscode(code1);
        printf("\n���ٴ���������:");
        GetPasscode(code2);
        if(!strcmp(code1,code2)){
            break;
        }else{
            printf("\n������������벻һ��,���������룡\n");
        }
    }
    char *truecode=encrypt(code1);
    strcpy(newadmin->code,truecode);
    newadmin->next=NULL;
    head->next=newadmin;
    head=newadmin;
    inPutAdminTxt(admin);
    printf("\n��ӳɹ�!\n");
}
int checkAdminExistence(char *name,Administratorlist *admin) //��֤����
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
        printf("���ӷ�����ʧ�ܣ�");
        return;
    }while(p!=NULL){
        fprintf(fp,"������%s ���룺%s \n",p->username,p->code);
        p=p->next;
    }
    fclose(fp);
    fp=NULL;
}
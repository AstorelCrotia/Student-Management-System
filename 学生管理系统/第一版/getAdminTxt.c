#include "head.h"
Administratorlist * CreateAdminList() 
{  
    Administratorlist *head,*q,*temp;
    head=(Administratorlist *)malloc(sizeof(Administratorlist));
    q = head;
    head->next = NULL;
    FILE *fp=fopen("admin.txt","rb");
    if(fp==NULL){
        printf("连接服务器失败！");
        return NULL;
    }
    while(1){
        temp=malloc(sizeof(Administratorlist));
        if(fscanf(fp,"姓名：%s 密码：%s \n",temp->username,temp->code)==EOF)break;
        q->next=temp;
        q=temp;
        q->next=NULL;
    }
    fclose(fp);
    free(temp);
    temp=NULL;
    return head->next;
}
Administratorlist * CreateAdminList1(){
    Administratorlist *head=malloc(sizeof(Administratorlist));
    strcpy(head->username,"hello");
    strcpy(head->code,"123456");
    head->next=NULL;
    return head;
}
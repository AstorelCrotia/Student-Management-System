#include "head.h"
StudentList * CreateStuList() 
{  
    StudentList *head,*q,*temp;
    head=(StudentList *)malloc(sizeof(StudentList));
    q = head;
    head->next = NULL;
    FILE *fp=fopen("student.txt","rb");
    if(fp==NULL){
        printf("连接服务器失败！");
        return 0;
    }
    while(1){
        temp=malloc(sizeof(StudentList));
        if(fscanf(fp,"学号：%s 姓名：%s 性别：%s 年龄：%d 班级：%s 数学：%d 英语：%d 语文：%d 总分：%d 名次：%d 密码：%s\n",temp->id,temp->name,temp->gender,&temp->age,temp->class,&temp->math,&temp->english,&temp->chinese,&temp->sum,&temp->rank,temp->code)==EOF)break;
        q->next=temp;
        q=temp;
        q->next=NULL;
    }
    fclose(fp);
    free(temp);
    temp=NULL;
    return head;
}
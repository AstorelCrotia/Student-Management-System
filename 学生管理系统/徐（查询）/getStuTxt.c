#include "head.h"
StudentList * CreateStuList() 
{  
    StudentList *head,*q,*temp;
    head=(StudentList *)malloc(sizeof(StudentList));
    q = head;
    head->next = NULL;
    FILE *fp=fopen("student.txt","rb");
    if(fp==NULL){
        printf("���ӷ�����ʧ�ܣ�");
        return 0;
    }
    while(1){
        temp=malloc(sizeof(StudentList));
        if(fscanf(fp,"ѧ�ţ�%s ������%s �Ա�%s ���䣺%d �༶��%s ��ѧ��%d Ӣ�%d ���ģ�%d �ܷ֣�%d ���Σ�%d ���룺%s\n",temp->id,temp->name,temp->gender,&temp->age,temp->class,&temp->math,&temp->english,&temp->chinese,&temp->sum,&temp->rank,temp->code)==EOF)break;
        q->next=temp;
        q=temp;
        q->next=NULL;
    }
    fclose(fp);
    free(temp);
    temp=NULL;
    return head;
}
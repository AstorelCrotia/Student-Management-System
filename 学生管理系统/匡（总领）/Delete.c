#include "head.h"

void Delete(StudentList *student) //ɾ��ѧ��
{
    char id[20]="0";
    QueryStu(student);
    printf("��ѡ����Ҫ����ɾ����ѧ����ѧ�ţ�");
    scanf("%s",id);
    StudentList *p=student,*q=p->next;
    while(q!=NULL){
        if(!strcmp(q->id,id)){
            p->next=q->next;
            free(q);
            printf("ɾ���ɹ���");
        }else{
            p=p->next;
            q=q->next;
        }
    }
    QueryStuByRankDown(student);
    inPutStuTxt(student->next);
}
#include "head.h"

void Delete(StudentList *student) //ɾ��ѧ��
{

    char id[20]="0";
    QueryStu(student);
    int key = Modifydelete(student);
    if(key==1)
    {
        printf("��֤��ȷ���������һ��������\n");
    }
    else
    {
        printf("��֤ʧ�ܣ��Ժ󷵻س�ʼ��½ҳ�档\n");
    }
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
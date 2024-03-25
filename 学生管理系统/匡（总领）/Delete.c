#include "head.h"

void Delete(StudentList *student) //删除学生
{
    char id[20]="0";
    QueryStu(student);
    printf("请选择需要进行删除的学生的学号：");
    scanf("%s",id);
    StudentList *p=student,*q=p->next;
    while(q!=NULL){
        if(!strcmp(q->id,id)){
            p->next=q->next;
            free(q);
            printf("删除成功！");
        }else{
            p=p->next;
            q=q->next;
        }
    }
    QueryStuByRankDown(student);
    inPutStuTxt(student->next);
}
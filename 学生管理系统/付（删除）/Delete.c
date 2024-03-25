#include "head.h"

void Delete(StudentList *student) //删除学生
{

    char id[20]="0";
    QueryStu(student);
    int key = Modifydelete(student);
    if(key==1)
    {
        printf("验证正确，请进行下一步操作。\n");
    }
    else
    {
        printf("验证失败，稍后返回初始登陆页面。\n");
    }
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
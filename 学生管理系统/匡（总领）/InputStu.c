#include "head.h"
void InputStu(StudentList *student){//添加学生
    char id[20]="0";
    char code1[20]="0";
    char code2[20]="0";
    StudentList *head=student;
    while(head->next!=NULL){
        head=head->next;
    }
    while(1){
        printf("请输入学号：");
        scanf(" %s",id);
        int i=checkStuExistence(id,student);
        if(i==1){
            printf("学号重复，请重新输入需添加的学生的学号!\n");
        }else if(i==0){
            break;
        }
    }
    StudentList *newstudent=malloc(sizeof(StudentList));
    if(newstudent==NULL){
        printf("内存分配失败！\n");
        return;
    }
    strcpy(newstudent->id,id);
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
    printf("\n请输入学生的姓名：");
    scanf(" %s",newstudent->name);
    printf("请输入学生的性别：");
    scanf(" %s",newstudent->gender);
    printf("请输入学生的班级：");
    scanf(" %s",newstudent->class);
    printf("请输入学生的年龄：");
    scanf(" %d",&newstudent->age);
    printf("请输入学生的语文成绩：");
    scanf(" %d",&newstudent->chinese);
    printf("请输入学生的数学成绩：");
    scanf(" %d",&newstudent->math);
    printf("请输入学生的英语成绩：");
    scanf(" %d",&newstudent->english);
    char *encode=encrypt(code1);
    strcpy(newstudent->code,encode);
    getSumScore(newstudent);
    head->next=newstudent;
    head=newstudent;
    head->next=NULL;
    QueryStuByRankDown(student);
    inPutStuTxt(student->next);
    printf("添加成功!\n");
    free(newstudent);
}
int checkStuExistence(char *id,StudentList *student) //验证功能
{   
    int i=0;
    StudentList *head=student->next;
    while(head!=NULL){
        if(!strcmp(head->id,id)){
            i=1;
            return i; 
        }
        head=head->next;
    }
    i=0;
    return i;
}
void inPutStuTxt(StudentList *head){
    FILE *fp=fopen("student.txt","w");
    StudentList *temp=head;
    while(temp!=NULL){
        fprintf(fp,"学号：%s 姓名：%s 性别：%s 年龄：%d 班级：%s 数学：%d 英语：%d 语文：%d 总分：%d 名次：%d 密码：%s \n",temp->id,temp->name,temp->gender,temp->age,temp->class,temp->math,temp->english,temp->chinese,temp->sum,temp->rank,temp->code);
        temp=temp->next;
    }
    fclose(fp);
    fp=NULL;
}
void  getSumScore(StudentList *student){
    student->sum=student->math+student->chinese+student->english;
}
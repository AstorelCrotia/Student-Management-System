#include "head.h"

void ModifyStu(StudentList *student) //修改学生信息
{
    char id[20]="0";
    QueryStu(student);
    printf("请选择需要进行修改的学生的学号：");
    scanf("%s",id);
    StudentList *p=student->next;
    while(p!=NULL){
        if(!strcmp(p->id,id)){
            printf("请输入修改后的学生的姓名：");
            scanf("%s",p->name);
            printf("请输入修改后的学生的性别：");
            scanf("%s",p->gender);
            printf("请输入修改后的学生的班级：");
            scanf("%s",p->class);
            printf("请输入修改后的学生的年龄：");
            scanf("%d",&p->age);
            printf("请输入修改后的学生的语文成绩：");
            scanf("%d",&p->chinese);
            printf("请输入修改后的学生的数学成绩：");
            scanf("%d",&p->math);
            printf("请输入修改后的学生的英语成绩：");
            scanf("%d",&p->english);
            printf("修改成功！");
            break;
        }else{
            p=p->next;
        }
    }
    getSumScore(p);
    QueryStuByRankDown(student);
    inPutStuTxt(student->next);
}
void ModifyStuCode(StudentList *student,char *id){
    StudentList *p=student->next;
    char code[20]="0";
    char code1[20]="0";
    char code2[20]="0";
    int flag=2;
    printf("%s\n",id);
    while(p!=NULL){
        if(!strcmp(p->id,id)){
            break;
        }
        p=p->next;
    }
    while(1){
        printf("请输入原密码：");
        GetPasscode(code);
        if(!strcmp(p->code,code)){
            while (1){
                printf("\n请输入修改后的密码：");
                GetPasscode(code1);
                printf("\n请再次输入修改后的密码：");
                GetPasscode(code2);
                if(!strcmp(code1,code2)){
                    char *encode=encrypt(code1);
                    strcpy(p->code,encode);
                    printf("\n修改成功!");
                    inPutStuTxt(student->next);
                    return;
                }else{
                    printf("两次密码不一致，请重新输入！\n");
                    }
                }
        }else{
            if(flag==0){
                printf("\n原密码输入错误次数过多，请检查后在进行修改！\n");
                return;
            }
            else{
                printf("\n原密码错误，你还有%d次机会，请重新输入！\n",flag);
                flag--;
            }
        }
    }
}
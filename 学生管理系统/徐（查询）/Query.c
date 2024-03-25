#include "head.h"
void QueryStu(StudentList *student){

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
        if(fscanf(fp,"学号：%s 姓名：%s 性别：%s 年龄：%d 班级：%s 数学：%d 英语：%d 语文：%d 总分：%d 名次：%d 密码：%s\n",
           temp->id,temp->name,temp->gender,&temp->age,temp->class,&temp->math,&temp->english,&temp->chinese,&temp->sum,&temp->rank,temp->code)==EOF)break;
        q->next=temp;
        q=temp;
        q->next=NULL;
    }

    int flag = 0;
    while(flag != 0){   
        int select=0;
        printf("1.根据姓名查询 2.根据学号查询\n");
        printf("3.根据语文成绩查询 4.根据数学成绩查询\n");
        printf("5.根据外语成绩查询 6.根据总名次查询\n");
        printf("7.退出查询\n");
        printf("请选择需要进行的查询方式：");
        scanf("%d",&select);
        StudentList *temp=student;
        switch (select)
        {
        case 1:
            char name[10] ={};
            printf("请输入学生姓名：");
            scanf("%s",name);
            QueryStuByName(temp,name);
            break;
        case 2:
            int id = 0;
            printf("请输入学生学号：");
            scanf("%d",&id);
            QueryStuById(temp,id);
            break;
        case 3:
            int chinese = 0;
            printf("请输入学生语文成绩：");
            scanf("%d",&chinese);
            QueryStuByChinese(temp,chinese);
            break;
        case 4:
            int math = 0;
            printf("请输入学生数学成绩：");
            scanf("%d",&math);
            QueryStuByMath(temp,math);
            break;
        case 5:
            int english = 0;
            printf("请输入学生外语成绩：");
            scanf("%d",&english);
            QueryStuByEnglish(temp,english);
            break;
        case 6:
            int rank = 0;
            printf("请输入学生总名次：");
            scanf("%d",&rank);
            QueryStuByRank(temp,rank);
            break;
        case 7:
            flag = 1;
            break;
        default:
            printf("输入有误，请重新输入\n");
            break;
        }
    }

    fclose(fp);
    free(temp);
    temp=NULL;
    return;
}

int getStu_Count(StudentList *student){
    StudentList *p=student->next;
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}

void QueryStuByRankDown(StudentList *student){
    if(student->next==NULL){ 
        printf("学生列表为空\n"); 
        return; 
    }    
    StudentList *p=NULL,*q=NULL,*temp=NULL,*subhead=NULL; 
    int n=getStu_Count(student);
    for(int i=0;i<n-1;i++){
        subhead=student;
        p=student->next;
        q=p->next;
        for(int j=0;j<n-1-i;j++){
            if(p->sum<q->sum){
                subhead->next=p->next;
                p->next=q->next;
                q->next=p;
                temp=p;
                p=q;
                q=temp;
            }
            subhead=subhead->next;
            p=p->next;
            q=q->next;
        }
    }
    int i=1;
    p=student->next;
    for(int i=1;i<=n;i++){
        p->rank=i;
        p=p->next;
        if(p==NULL){
            break;
        }
    }
}

void QueryStuByName(StudentList *student,char name[]){
    if(student->next==NULL){ 
        printf("学生列表为空\n"); 
        return; 
    } 
    int n=getStu_Count(student);
    for(int i=0;i<n-1;i++){
        if(student->name==name){ 
            printf("学号：%s\t姓名：%s\t性别：%s\t年龄：%d\t班级：%s\t数学：%d\t英语：%d\t语文：%d\t总分：%d\t名次：%d\t\n",student->id,student->name,student->gender,
            student->age,student->class,student->math,student->english,student->chinese,student->sum,student->rank);
            return;  
        } 
    }
}

void QueryStuById(StudentList *student,int id){
    if(student->next==NULL){ 
        printf("学生列表为空\n"); 
        return; 
    } 
    int n=getStu_Count(student);
    for(int i=0;i<n-1;i++){
        if(student->id==id){ 
            printf("学号：%s\t姓名：%s\t性别：%s\t年龄：%d\t班级：%s\t数学：%d\t英语：%d\t语文：%d\t总分：%d\t名次：%d\t\n",student->id,student->name,student->gender,
            student->age,student->class,student->math,student->english,student->chinese,student->sum,student->rank);\
            return;  
        } 
    }
}

void QueryStuByChinese(StudentList *student,int chinese){
    if(student->next==NULL){ 
        printf("学生列表为空\n"); 
        return; 
    } 
    int n=getStu_Count(student);
    for(int i=0;i<n-1;i++){
        if(student->chinese==chinese){ 
            printf("学号：%s\t姓名：%s\t性别：%s\t年龄：%d\t班级：%s\t数学：%d\t英语：%d\t语文：%d\t总分：%d\t名次：%d\t\n",student->id,student->name,student->gender,
            student->age,student->class,student->math,student->english,student->chinese,student->sum,student->rank); 
            return; 
        } 
    }
}

void QueryStuByMath(StudentList *student,int math){
    if(student->next==NULL){ 
        printf("学生列表为空\n"); 
        return; 
    } 
    int n=getStu_Count(student);
    for(int i=0;i<n-1;i++){
        if(student->math==math){ 
            printf("学号：%s\t姓名：%s\t性别：%s\t年龄：%d\t班级：%s\t数学：%d\t英语：%d\t语文：%d\t总分：%d\t名次：%d\t\n",student->id,student->name,student->gender,
            student->age,student->class,student->math,student->english,student->chinese,student->sum,student->rank); 
            return; 
        } 
    }
}

void QueryStuByEnglish(StudentList *student,int english){
    if(student->next==NULL){ 
        printf("学生列表为空\n"); 
        return; 
    } 
    int n=getStu_Count(student);
    for(int i=0;i<n-1;i++){
        if(student->english==english){ 
            printf("学号：%s\t姓名：%s\t性别：%s\t年龄：%d\t班级：%s\t数学：%d\t英语：%d\t语文：%d\t总分：%d\t名次：%d\t\n",student->id,student->name,student->gender,
            student->age,student->class,student->math,student->english,student->chinese,student->sum,student->rank); 
            return; 
        } 
    }
}

void QueryStuByRank(StudentList *student,int rank){
    if(student->next==NULL){ 
        printf("学生列表为空\n"); 
        return; 
    } 
    int n=getStu_Count(student);
    for(int i=0;i<n-1;i++){
        if(student->rank==rank){ 
            printf("学号：%s\t姓名：%s\t性别：%s\t年龄：%d\t班级：%s\t数学：%d\t英语：%d\t语文：%d\t总分：%d\t名次：%d\t\n",student->id,student->name,student->gender,
            student->age,student->class,student->math,student->english,student->chinese,student->sum,student->rank); 
            return; 
        } 
    }
}
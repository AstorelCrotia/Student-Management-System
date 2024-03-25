#include "head.h"
void QueryStu(StudentList *student){
    int select=0;
    printf("1.�������� 2.���ν���\n");
    printf("3.�������� 4.�༶����\n");
    printf("5.ѧ������\n");
    printf("��ѡ����Ҫ���еĲ�ѯ��ʽ��");
    scanf("%d",&select);
    StudentList *temp=student;
    switch (select)
    {
    case 1:
        QueryStuByRankDown(temp);
        break;
    case 2:
        QueryStuByRankUp(temp);
        break;
    case 3:
        QueryStuByName(temp);
        break;
    case 4:
        QueryStuByClass(temp);
        break;
    case 5:
        QueryStuById(temp);
    default:
        break;
    }
    StudentList *p=temp->next;
    while(p!=NULL){
        printf("ѧ�ţ�%s\t������%s\t�Ա�%s\t���䣺%d\t�༶��%s\t��ѧ��%d\tӢ�%d\t���ģ�%d\t�ܷ֣�%d\t���Σ�%d\t\n",p->id,p->name,p->gender,p->age,p->class,p->math,p->english,p->chinese,p->sum,p->rank);
        p=p->next;
    }
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
        printf("ѧ���б�Ϊ��\n"); 
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
void QueryStuByRankUp(StudentList *student){
    if(student->next==NULL){ 
        printf("ѧ���б�Ϊ��\n"); 
        return; 
    } 
    int n=getStu_Count(student);
    StudentList *p=NULL,*q=NULL,*temp=NULL,*subhead=NULL; 
    for(int i=0;i<n-1;i++){
        subhead=student;
        p=student->next;
        q=p->next;
        for(int j=0;j<n-1-i;j++){
            if(p->sum>q->sum){
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
    p=student->next;
    for(int i=n;i>0;i--){
        p->rank=i;
        p=p->next;
        if(p==NULL){
            break;
        }
    }
}
void QueryStuByName(StudentList *student){
    if(student->next==NULL){ 
        printf("ѧ���б�Ϊ��\n"); 
        return; 
    } 
    int n=getStu_Count(student);
    StudentList *p=NULL,*q=NULL,*temp=NULL,*subhead=NULL;
    for(int i=0;i<n-1;i++){
        subhead=student;
        p=student->next;
        q=p->next;
        for(int j=0;j<n-i-1;j++){
            if(strcmp(p->name,q->name)>0){
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
}
void QueryStuByClass(StudentList *student){
    if(student->next==NULL){ 
        printf("ѧ���б�Ϊ��\n"); 
        return; 
    } 
    int n=getStu_Count(student);
    StudentList *p=NULL,*q=NULL,*temp=NULL,*subhead=NULL;
    for(int i=0;i<n-1;i++){
        subhead=student;
        p=student->next;
        q=p->next;
        for(int j=0;j<n-i-1;j++){
            if(strcmp(p->class,q->class)>0){
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
}
void QueryStuById(StudentList *student){
    if(student->next==NULL){ 
        printf("ѧ���б�Ϊ��\n"); 
        return; 
    } 
    int n=getStu_Count(student);
    StudentList *p=NULL,*q=NULL,*temp=NULL,*subhead=NULL; 
    for(int i=0;i<n-1;i++){
        subhead=student;
        p=student->next;
        q=p->next;
        for(int j=0;j<n-1-i;j++){
            if(strcmp(p->id,q->id)>0){
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
}
#include "head.h"
void QueryStu(StudentList *student){

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
        if(fscanf(fp,"ѧ�ţ�%s ������%s �Ա�%s ���䣺%d �༶��%s ��ѧ��%d Ӣ�%d ���ģ�%d �ܷ֣�%d ���Σ�%d ���룺%s\n",
           temp->id,temp->name,temp->gender,&temp->age,temp->class,&temp->math,&temp->english,&temp->chinese,&temp->sum,&temp->rank,temp->code)==EOF)break;
        q->next=temp;
        q=temp;
        q->next=NULL;
    }

    int flag = 0;
    while(flag != 0){   
        int select=0;
        printf("1.����������ѯ 2.����ѧ�Ų�ѯ\n");
        printf("3.�������ĳɼ���ѯ 4.������ѧ�ɼ���ѯ\n");
        printf("5.��������ɼ���ѯ 6.���������β�ѯ\n");
        printf("7.�˳���ѯ\n");
        printf("��ѡ����Ҫ���еĲ�ѯ��ʽ��");
        scanf("%d",&select);
        StudentList *temp=student;
        switch (select)
        {
        case 1:
            char name[10] ={};
            printf("������ѧ��������");
            scanf("%s",name);
            QueryStuByName(temp,name);
            break;
        case 2:
            int id = 0;
            printf("������ѧ��ѧ�ţ�");
            scanf("%d",&id);
            QueryStuById(temp,id);
            break;
        case 3:
            int chinese = 0;
            printf("������ѧ�����ĳɼ���");
            scanf("%d",&chinese);
            QueryStuByChinese(temp,chinese);
            break;
        case 4:
            int math = 0;
            printf("������ѧ����ѧ�ɼ���");
            scanf("%d",&math);
            QueryStuByMath(temp,math);
            break;
        case 5:
            int english = 0;
            printf("������ѧ������ɼ���");
            scanf("%d",&english);
            QueryStuByEnglish(temp,english);
            break;
        case 6:
            int rank = 0;
            printf("������ѧ�������Σ�");
            scanf("%d",&rank);
            QueryStuByRank(temp,rank);
            break;
        case 7:
            flag = 1;
            break;
        default:
            printf("������������������\n");
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

void QueryStuByName(StudentList *student,char name[]){
    if(student->next==NULL){ 
        printf("ѧ���б�Ϊ��\n"); 
        return; 
    } 
    int n=getStu_Count(student);
    for(int i=0;i<n-1;i++){
        if(student->name==name){ 
            printf("ѧ�ţ�%s\t������%s\t�Ա�%s\t���䣺%d\t�༶��%s\t��ѧ��%d\tӢ�%d\t���ģ�%d\t�ܷ֣�%d\t���Σ�%d\t\n",student->id,student->name,student->gender,
            student->age,student->class,student->math,student->english,student->chinese,student->sum,student->rank);
            return;  
        } 
    }
}

void QueryStuById(StudentList *student,int id){
    if(student->next==NULL){ 
        printf("ѧ���б�Ϊ��\n"); 
        return; 
    } 
    int n=getStu_Count(student);
    for(int i=0;i<n-1;i++){
        if(student->id==id){ 
            printf("ѧ�ţ�%s\t������%s\t�Ա�%s\t���䣺%d\t�༶��%s\t��ѧ��%d\tӢ�%d\t���ģ�%d\t�ܷ֣�%d\t���Σ�%d\t\n",student->id,student->name,student->gender,
            student->age,student->class,student->math,student->english,student->chinese,student->sum,student->rank);\
            return;  
        } 
    }
}

void QueryStuByChinese(StudentList *student,int chinese){
    if(student->next==NULL){ 
        printf("ѧ���б�Ϊ��\n"); 
        return; 
    } 
    int n=getStu_Count(student);
    for(int i=0;i<n-1;i++){
        if(student->chinese==chinese){ 
            printf("ѧ�ţ�%s\t������%s\t�Ա�%s\t���䣺%d\t�༶��%s\t��ѧ��%d\tӢ�%d\t���ģ�%d\t�ܷ֣�%d\t���Σ�%d\t\n",student->id,student->name,student->gender,
            student->age,student->class,student->math,student->english,student->chinese,student->sum,student->rank); 
            return; 
        } 
    }
}

void QueryStuByMath(StudentList *student,int math){
    if(student->next==NULL){ 
        printf("ѧ���б�Ϊ��\n"); 
        return; 
    } 
    int n=getStu_Count(student);
    for(int i=0;i<n-1;i++){
        if(student->math==math){ 
            printf("ѧ�ţ�%s\t������%s\t�Ա�%s\t���䣺%d\t�༶��%s\t��ѧ��%d\tӢ�%d\t���ģ�%d\t�ܷ֣�%d\t���Σ�%d\t\n",student->id,student->name,student->gender,
            student->age,student->class,student->math,student->english,student->chinese,student->sum,student->rank); 
            return; 
        } 
    }
}

void QueryStuByEnglish(StudentList *student,int english){
    if(student->next==NULL){ 
        printf("ѧ���б�Ϊ��\n"); 
        return; 
    } 
    int n=getStu_Count(student);
    for(int i=0;i<n-1;i++){
        if(student->english==english){ 
            printf("ѧ�ţ�%s\t������%s\t�Ա�%s\t���䣺%d\t�༶��%s\t��ѧ��%d\tӢ�%d\t���ģ�%d\t�ܷ֣�%d\t���Σ�%d\t\n",student->id,student->name,student->gender,
            student->age,student->class,student->math,student->english,student->chinese,student->sum,student->rank); 
            return; 
        } 
    }
}

void QueryStuByRank(StudentList *student,int rank){
    if(student->next==NULL){ 
        printf("ѧ���б�Ϊ��\n"); 
        return; 
    } 
    int n=getStu_Count(student);
    for(int i=0;i<n-1;i++){
        if(student->rank==rank){ 
            printf("ѧ�ţ�%s\t������%s\t�Ա�%s\t���䣺%d\t�༶��%s\t��ѧ��%d\tӢ�%d\t���ģ�%d\t�ܷ֣�%d\t���Σ�%d\t\n",student->id,student->name,student->gender,
            student->age,student->class,student->math,student->english,student->chinese,student->sum,student->rank); 
            return; 
        } 
    }
}
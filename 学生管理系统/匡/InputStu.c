#include "head.h"
void InputStu(StudentList *student){//���ѧ��
    char id[20]="0";
    char code1[20]="0";
    char code2[20]="0";
    StudentList *head=student;
    while(head->next!=NULL){
        head=head->next;
    }
    while(1){
        printf("������ѧ�ţ�");
        scanf(" %s",id);
        int i=checkStuExistence(id,student);
        if(i==1){
            printf("ѧ���ظ�����������������ӵ�ѧ����ѧ��!\n");
        }else if(i==0){
            break;
        }
    }
    StudentList *newstudent=malloc(sizeof(StudentList));
    if(newstudent==NULL){
        printf("�ڴ����ʧ�ܣ�\n");
        return;
    }
    strcpy(newstudent->id,id);
    while(1){
        printf("����������:");
        GetPasscode(code1);
        printf("\n���ٴ���������:");
        GetPasscode(code2);
        if(!strcmp(code1,code2)){
            break;
        }else{
            printf("\n������������벻һ��,���������룡\n");
        }
    }
    printf("\n������ѧ����������");
    scanf(" %s",newstudent->name);
    printf("������ѧ�����Ա�");
    scanf(" %s",newstudent->gender);
    printf("������ѧ���İ༶��");
    scanf(" %s",newstudent->class);
    printf("������ѧ�������䣺");
    scanf(" %d",&newstudent->age);
    printf("������ѧ�������ĳɼ���");
    scanf(" %d",&newstudent->chinese);
    printf("������ѧ������ѧ�ɼ���");
    scanf(" %d",&newstudent->math);
    printf("������ѧ����Ӣ��ɼ���");
    scanf(" %d",&newstudent->english);
    char *encode=encrypt(code1);
    strcpy(newstudent->code,encode);
    getSumScore(newstudent);
    head->next=newstudent;
    head=newstudent;
    head->next=NULL;
    QueryStuByRankDown(student);
    inPutStuTxt(student->next);
    printf("��ӳɹ�!\n");
    free(newstudent);
}
int checkStuExistence(char *id,StudentList *student) //��֤����
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
        fprintf(fp,"ѧ�ţ�%s ������%s �Ա�%s ���䣺%d �༶��%s ��ѧ��%d Ӣ�%d ���ģ�%d �ܷ֣�%d ���Σ�%d ���룺%s \n",temp->id,temp->name,temp->gender,temp->age,temp->class,temp->math,temp->english,temp->chinese,temp->sum,temp->rank,temp->code);
        temp=temp->next;
    }
    fclose(fp);
    fp=NULL;
}
void  getSumScore(StudentList *student){
    student->sum=student->math+student->chinese+student->english;
}
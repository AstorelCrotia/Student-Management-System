#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
typedef struct  studentlist{
    char id[20];
    char name[20];
    char gender[10];
    char code[20];
    char class[20];
    int math;
    int chinese;
    int english;
    int age;
    int rank;
    int sum;
    struct studentlist *next;
}StudentList;
typedef struct administratorlist{
    char username[20];
    char code[20];
    struct administratorlist *next;    
} Administratorlist;
//���ļ��е�����д������
Administratorlist *CreateAdminList();//��admintxt��ȡ��������
Administratorlist * CreateAdminList1();//¼�볬������Ա�ģ����Բ���
StudentList * CreateStuList() ;//��studenttxt��ȡ��������
//��ʼҳ��ѡ��
int Initialface();
//����Ա��ѧ����¼����֤
int ValidationAdmin(Administratorlist *Admin);//����Ա��¼���жϳ����������ͨ����
char *ValidationStu(StudentList *Student);//ѧ����¼������ѧ������
//�����ڸ� concealCode.c
void gotXY(int x,int y);
int posx();
int posy();
void GetPasscode(char* code);
//�������������
char *decrypt(char *code);//����
char *encrypt(char *code);//����
//����Ա��ѧ���������
void InterfaceAdmin(int usergroup,Administratorlist *admin,StudentList *student);//������ú���
void InterfaceStudent(StudentList *student,char *id);//ѧ��
void supAdminFunc(Administratorlist *admin,StudentList *student);//��������Ĺ���
void AdminFunc(StudentList *student);//��ͨ
void studentFunc(StudentList *student,char *id);//ѧ��
//����ʵ��
void InputAdmin(Administratorlist *a);//��ӹ���Ա
int checkAdminExistence(char *name,Administratorlist *admin);//��ѯ����Ա�Ƿ����
void inPutAdminTxt(Administratorlist *head);//���浽�ļ�admin.txt
//
void InputStu(StudentList *s);//���ѧ��
void  getSumScore(StudentList *student);//���ѧ���ܷ�
int checkStuExistence(char *id,StudentList *student);//��ѯѧ���Ƿ��ظ�
void inPutStuTxt(StudentList *head);//����ѧ��txt
//��ѯ����
int getStu_Count(StudentList *student);//ѧ������
void QueryStu(StudentList *student);//��ѯ���
void QueryStuByRankDown(StudentList *student);//���ν���
void QueryStuByRankUp(StudentList *student);//��������
void QueryStuByName(StudentList *student);//��������
void QueryStuByClass(StudentList *student);//�༶����
void QueryStuById(StudentList *student);//ѧ������
//�޸�ѧ����Ϣ
void ModifyStu(StudentList *student);//�Ȳ�ѯѧ�����޸�ѧ����Ϣ
void ModifyStuCode(StudentList *student,char *id);//�޸�����
//ɾ��ѧ��
void Delete(StudentList *student);

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Student//����ѧ���ṹ��
{
    char username[20];
    char name[20];
    char gender[10];
    int code[20];
    char class[20];
    int math;
    int chinese;
    int english;
    int age;
    struct Student * next; 
} Student;

typedef struct Administrator //��������߽ṹ��
{
    char username[20];
    char code[20];
    struct Administrator * next; 
} Administrator;

void Initialface(char *username);//��ʼ����
void Validation(char *username,int *usergroup,int *sc,int *flag);//��֤����
void Interface(int usergroup,char username,int *sc);//��¼��ʾ����
void Input(int usergroup,char username);//¼�빦��
void Query(Student s1);//��ѯ����
void Modify(int usergroup,char username);//�޸Ĺ���
void Delete(int usergroup,char username);//ɾ������
void scan(Student *s1);//����¼�뺯��
Student* createlist();//����Ĵ���

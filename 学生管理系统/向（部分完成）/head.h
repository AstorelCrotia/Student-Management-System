#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Student//����ѧ���ṹ��
{
    char username[20];
    char name[20];
    char gender[10];
    char code[20];
    char class[20];
    float math;
    float chinese;
    float english;
    int age;
    int rank;
    float sum;
    struct Student * next; 
} Student;

typedef struct Administrator //��������߽ṹ��
{
    char username[20];
    char code[20];
    struct Administrator * next; 
} Administrator;

void Initialface(char *username);//��ʼ����
void Validation(char *username,int *usergroup,int *sc);//��֤����
void Interface(int usergroup,char *username);//��¼��ʾ����
void Input(int usergroup);//¼�빦��
void Query(Student s1);//��ѯ����
void Modify(int usergroup,char username);//�޸Ĺ���
void Delete(int usergroup,char username);//ɾ������
void scan(Student *s1);//����¼�뺯��
Student* createlist();//����Ĵ���

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct //����ѧ���ṹ��
{
    char id[20];
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

typedef struct //��������߽ṹ��
{
    char username[20];
    int code[20];
} Administrator;

void Initialface();//��ʼ����
void Validation(int username);//��֤����
int Interface(int usergroup,char username);//��¼��ʾ����
int Input(int usergroup,char username);//¼�빦��
int Query(Student s1);//��ѯ����
int Modify(int usergroup,char username);//�޸Ĺ���
int Delete(int usergroup,char username);//ɾ������
Student* createlist();//����Ĵ���

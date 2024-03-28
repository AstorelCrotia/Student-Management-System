#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct User
{
    char uid[20];
    char code[20];
    float balance;
    struct User *next;
} User;

typedef struct lottery
{
    char tid[20];
    char uid[20];
    char did[20];
    int category;
    char number[20];
    int draw;
    int win;
    time_t buydate;
    time_t windate;
    struct lottery *next;
} lottery;

void InDate(lottery *date);//д������
void OutDate(lottery *date);//��������
void Initialface(int *sc);//��ʼ����
void Initialization();//ϵͳ��ʼ����д�볬��
void Validation(char *id, int *group); // ��֤�û�������
void Mjudgment(int *sc,int *group,char *id); // ��¼ǰ����ѡ���ж�
void userjudgment(int *sc, int *group, char *id);// ��¼�����ѡ���ж�
void Registeruser();// �û�ע��
void Registeradmin();// ����Աע��
void Adminface(int *sc,char *id); //����Ա����
void Superface(int *sc); //���ܽ���
void Userface(int *sc,char *id); //�û�����
void Back(int *sc); //���س�ʼ����
void adminQuery(int *sc); // ����Ա��ѯ
void userQuery(int *sc); // �û���ѯ
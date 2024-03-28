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
    time_t date;
    struct lottery *next;
} lottery;

void InDate(lottery *date);//д������
void OutDate(lottery *date);//��������
void Initialface(int *sc);//��ʼ����
void Initialization();//ϵͳ��ʼ����д�볬��
void Validation(char *id, int *group); // ��֤�û�������
void Mjudgment(int *sc,int *group,char *id); // ��¼����ѡ���ж�
void Register();// �û�ע��
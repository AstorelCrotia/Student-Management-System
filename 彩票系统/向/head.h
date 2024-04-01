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

typedef struct Lottery
{
    char tid[25];
    char uid[20];
    char did[20];
    int category;
    char usernumber[20];
    char winnumber[20];
    int draw;
    int win;
    time_t buydate;
    time_t windate;
    struct Lottery *next;
} Lottery;

void InbuyDate(Lottery *date);                    // д�빺������
void InwinDate(Lottery *date);                    // д�뿪������
void OutbuyDate(Lottery *date);                   // ������������
void OutwinDate(Lottery *date);                   // ������������
void Initialface(int *sc);                        // ��ʼ����
void Initialization();                            // ϵͳ��ʼ����д�볬��
void Validation(char *id, int *group);            // ��֤�û�������
void Mjudgment(int *sc, int *group, char *id);    // ��¼ǰ����ѡ���ж�
void userjudgment(int *sc, int *group, char *id); // ��¼�����ѡ���ж�
void Registeruser();                              // �û�ע��
void Registeradmin();                             // ����Աע��
void Adminface(int *sc, char *id);                // ����Ա����
void Superface(int *sc);                          // ���ܽ���
void Userface(int *sc, char *id);                 // �û�����
void Back(int *sc);                               // ���س�ʼ����
void adminQuery(int *sc);                         // ����Ա��ѯ
void userQuery(int *sc, char *id);                // �û���ѯ
void conditionQueryuser();                        // ������ѯ�û�
void allQueryuser();                              // ��ѯ�����û���Ϣ
void Showuser(char *id);                          // �û���ѯ�Լ���Ϣ
void adminModify(int *sc);                        // �޸Ľ���
void admincodeModify();                           // ����Ա�����޸�
void usercodeModify(char *id);                    // �û������޸�
void usermoneyModify(char *id, int flag);         // �û�����޸�
void adminmoneyModify();                          // ����޸�
void Delete(int *sc);                             // ɾ������
void Deleteuser();                                // ɾ������
void winlottery(int *sc);                         // ��Ʊ����
void Buy(int *sc, char *id);                      // �����Ʊ
void buyModify(char *id, float money, int *sc);   // ����ʱ����޸�
void didDate(Lottery *date);                      // �ں�����
void Buyin(Lottery *lottery, char *id, int sc);    // ����д��
void winlotteryin1();                             // ��Ʊ����д��1
void winlotteryin2();                             // ��Ʊ����д��2
void winlotteryin3();                             // ��Ʊ����д��3
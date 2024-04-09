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

typedef struct Revenue
{
    char uid[20];
    char buydate[20];
    int category;
    float money;
    struct Revenue *next;
} Revenue;

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
    char buydate[20];
    char windate[20];
    struct Lottery *next;
} Lottery;

void InbuyDate(Lottery *date);                    // д�빺������
void InwinDate(Lottery *date);                    // д�뿪������
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
void didDate(Lottery *date1, Lottery *date2);     // �ں�����
void Buyin(Lottery *lottery, char *id, int sc,Lottery *oldlottery);   // ����д��
void winlotteryin1();                             // ��Ʊ����д��1
void winlotteryin2();                             // ��Ʊ����д��2
void winlotteryin3();                             // ��Ʊ����д��3
void conditionQuerybuy();                         // ������ѯ��Ʊ��ʷ
void conditionQuerywin();                         // ������ѯ��ʷ����
void allnQueryubuy();                             // ��ѯ������ʷ��Ʊ
void allQuerywin();                               // ��ѯ������ʷ�н�
void Querymoney();                                // ��ѯ��Ʊ����Ӫ��
void conditionQueryuserbuy(char *id);             // �û���ѯ���й�Ʊ��ʷ
void userQuerywin(char *id);                      // �û���ѯ������ʷ�н�
void Prize(Lottery *lottery, int *ran, float n);  // �ҽ�
void revenue(float money, Lottery *lottery);      // Ӫ�ղ���
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include<conio.h>
#define ID_EDIT_USERNAME 1001
#define ID_EDIT_PASSWORD 1002
#define ID_EDIT_PASSWORD1 1000
#define ID_RETURN 1003
#define ID_LISTBOX 1004
#define ID_LISTBOX1 1005
#define ID_LISTBOX2 1006
#define ID_LISTBOX3 1007
#define ID_LISTBOX4 1008
#define ID_LISTBOX5 1009
#define ID_LISTBOX6 1010
#define ID_LISTBOX7 1011
#define ID_LISTBOX8 1012
#define ID_LISTBOX9 1013
#define ID_LISTBOX10 1014
#define ID_LISTBOX11 1015
#define WM_USER_RETURN_PREV_WINDOW (WM_USER + 1)
typedef struct user{//�û�����
    char name[20];
    char password[20];
    int userBalance;
    struct user *next;
}USER;
typedef struct issue_list_data{//��Ʊ����
    char issueID[12];//�����ں�
    int unitPrice;//��Ʊ����
    int lotteryState;//����״̬
    int winningNumbers[10];//�н�����
    int totalSales;//�����۳�����
    int currentPrizePool; //���ڽ����ܽ��
    struct issue_list_data *next;
}Id_t;
typedef struct ticket_list_data{//��Ʊ����
    char issueID[12];//�ں�
    int ticketID;//��Ʊid
    int unitPrice;//��Ʊ����
    int betNumber;//����
    int state;//�Ƿ�ҽ�
    int lotteryState;//����״̬
    int Number[10];//ѡ�����
    int jackPots;//�н����
    char name[20];//������
    struct ticket_list_data *next;
}Td_t;
USER *U;
Id_t *I;
Td_t *T;
Td_t *Pwinner;
//����Ա
int admin_login(char *name,char *password);//����Ա��¼
void quire_admin(HWND hWnd);
void quire_Pwinner(HWND hWnd);
void quire_Pwinner1(HWND hWnd,char *issueID);//�����н�
void quire_admintoUserlist(HWND hWnd);
void quire_admintoUser(HWND hWnd,char *name);//����Ա��ѯ�û�
void quiretickt_issue(Id_t *issue,Td_t *ticket);//��Ʊ���
void quire_curr(HWND hWnd);//���ڹ�Ʊ���
void quire_prvelist(HWND hWnd);
void quire_prve(HWND hWnd,char *id);//���ڹ�Ʊ���
//�û�
USER *getUser_txt();//�ļ���ȡ���û�����
void putUser_txt(USER *users);//�����ļ�
int check(USER *users,char *name);//����û����Ƿ��ظ�
int registerUser(HWND hWnd,char *name,char *password);
void banlance(HWND hWnd,char *name);
void recharge(HWND hWnd,char *name,int banlance);
int user_login(char *name,char *password);//�û���¼
void userquire_curr(HWND hWnd);
void quiry_user(USER *users,Id_t *issue,Td_t *ticket,Td_t *pwinner,char *name);//�û���ѯ
void quiry_userinf(HWND hWnd,char *name);//������Ϣ
void quiry_buyticket(HWND hWnd,char *name);//��Ʊ���
void quiry_userwin(HWND hWnd,char *name);//�н���¼
void modify_user(USER *users,char *name);//�޸ĸ�����Ϣ
int modify_userName(HWND hWnd,char *name1,char *name2);//�޸��û���
void modify_userPassword(HWND hWnd,char *password,char *name);//�޸�����
//��Ʊ
Id_t *getIssue_txt();//�ļ���ȡ����Ʊ����
void putIssue_txt(Id_t *head);//�����ļ�
void Issue_lottery(int unitPrice,int currentPrizePool,HWND hWnd);//���۲�Ʊ
void rand_winNumber(Id_t *head);//��ȡ��Ʊ�н��������
void Draw_lottery(HWND hWnd);//����
void paylevel();//�ж��н�����
void payout();//�н��������
//��Ʊ
Td_t *getticket_txt();//�ļ���ȡ��Ʊ��¼����Ʊ����
void putticket_txt(Td_t *head);//�����ļ�
void ticket_issue(HWND hWnd,char *name,int bet,int *arr);//��Ʊ
void ticket_num(int *arr1,int *arr2);//�û����빺�����
//���ڲ�Ʊ�н���¼
Td_t *getprvewinner_txt();//��ȡ�����н�������
void putprevwinner_txt(Td_t *head);//�����ļ�
//�˵�
void menu_sign(HWND hwnd);
void menu_admin(HWND hwnd);
void menu_adminquiry(HWND hWnd);
void menu_adminquiryticket(HWND hWnd);
void menu_user(HWND hWnd);
void menu_userquiry(HWND hWnd);
void menu_usermodify(HWND hWnd);
//ʱ�亯��
void delay(int seconds);//��ʱ����
void Countdown(int seconds);//�ȴ���ʱ
void getData(char *date);//��ȡ��Ʊ�ں�
//�����ڲ�
void gotXY(int x,int y);
int posx();
int posy();
void GetPasscode(char* pwd);


//
void admin_loginw(HWND hWnd);//��¼����
void admin_function(HWND hWnd);//���ܴ���
void admin_issueLottery(HWND hWnd);//
void admin_quiry(HWND hWnd);
void admin_quiryPwinner(HWND hWnd);
void admin_quiryuser(HWND hWnd);
void admin_quiryuserinf(HWND hWnd);
void admin_quiryticket(HWND hWnd);
void admin_quiryticketcurr(HWND hWnd);
void admin_quiryticketprve(HWND hWnd);
void admin_quiryticketprveinf(HWND hWnd);
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcAdmin(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcAdminfun(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcAdminIssueLottery(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcAdminQuiry(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcAdminQuiryPwinner(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcAdminQuiryuser(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcAdminQuiryuserinf(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcAdminQuiryTicket(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcAdminQuiryTicketcurr(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcAdminQuiryTicketprve(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcAdminQuiryTicketprveinf(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

void user_loginw(HWND hWnd);
void user_function(HWND hWnd);
void user_ticketissue(HWND hWnd);
void user_quiry(HWND hWnd);
void user_quiryinf(HWND hWnd);
void user_quiryticket(HWND hWnd);
void user_quirywin(HWND hWnd);
void user_modify(HWND hWnd);
void user_modifyname(HWND hWnd);
void user_modifypassword(HWND hWnd);
void user_add(HWND hWnd);//
void user_recharge(HWND hWnd);

LRESULT CALLBACK WndProcUser(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcUserfun(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcUserticketissue(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcUserQuiry(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcUserQuiryinf(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcUserQuiryticket(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcUserQuirywin(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcUserModify(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcUserModifyName(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcUserModifyPassword(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcAdd(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcUserrecharge(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
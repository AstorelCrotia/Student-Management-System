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
typedef struct user{//用户链表
    char name[20];
    char password[20];
    int userBalance;
    struct user *next;
}USER;
typedef struct issue_list_data{//彩票链表
    char issueID[12];//发行期号
    int unitPrice;//彩票单价
    int lotteryState;//开奖状态
    int winningNumbers[10];//中奖号码
    int totalSales;//当期售出总数
    int currentPrizePool; //当期奖池总金额
    struct issue_list_data *next;
}Id_t;
typedef struct ticket_list_data{//购票链表
    char issueID[12];//期号
    int ticketID;//彩票id
    int unitPrice;//彩票单价
    int betNumber;//倍数
    int state;//是否兑奖
    int lotteryState;//开奖状态
    int Number[10];//选择号码
    int jackPots;//中将金额
    char name[20];//购买者
    struct ticket_list_data *next;
}Td_t;
USER *U;
Id_t *I;
Td_t *T;
Td_t *Pwinner;
//管理员
int admin_login(char *name,char *password);//管理员登录
void quire_admin(HWND hWnd);
void quire_Pwinner(HWND hWnd);
void quire_Pwinner1(HWND hWnd,char *issueID);//往期中奖
void quire_admintoUserlist(HWND hWnd);
void quire_admintoUser(HWND hWnd,char *name);//管理员查询用户
void quiretickt_issue(Id_t *issue,Td_t *ticket);//购票情况
void quire_curr(HWND hWnd);//往期购票情况
void quire_prvelist(HWND hWnd);
void quire_prve(HWND hWnd,char *id);//当期购票情况
//用户
USER *getUser_txt();//文件获取到用户链表
void putUser_txt(USER *users);//存入文件
int check(USER *users,char *name);//检查用户名是否重复
int registerUser(HWND hWnd,char *name,char *password);
void banlance(HWND hWnd,char *name);
void recharge(HWND hWnd,char *name,int banlance);
int user_login(char *name,char *password);//用户登录
void userquire_curr(HWND hWnd);
void quiry_user(USER *users,Id_t *issue,Td_t *ticket,Td_t *pwinner,char *name);//用户查询
void quiry_userinf(HWND hWnd,char *name);//个人信息
void quiry_buyticket(HWND hWnd,char *name);//购票情况
void quiry_userwin(HWND hWnd,char *name);//中奖记录
void modify_user(USER *users,char *name);//修改个人信息
int modify_userName(HWND hWnd,char *name1,char *name2);//修改用户名
void modify_userPassword(HWND hWnd,char *password,char *name);//修改密码
//彩票
Id_t *getIssue_txt();//文件获取到彩票链表
void putIssue_txt(Id_t *head);//存入文件
void Issue_lottery(int unitPrice,int currentPrizePool,HWND hWnd);//发售彩票
void rand_winNumber(Id_t *head);//获取彩票中奖号码随机
void Draw_lottery(HWND hWnd);//开奖
void paylevel();//判断中奖级别
void payout();//中奖金额派送
//购票
Td_t *getticket_txt();//文件获取购票记录到购票链表
void putticket_txt(Td_t *head);//存入文件
void ticket_issue(HWND hWnd,char *name,int bet,int *arr);//购票
void ticket_num(int *arr1,int *arr2);//用户输入购买号码
//往期彩票中奖记录
Td_t *getprvewinner_txt();//获取往期中奖到链表
void putprevwinner_txt(Td_t *head);//存入文件
//菜单
void menu_sign(HWND hwnd);
void menu_admin(HWND hwnd);
void menu_adminquiry(HWND hWnd);
void menu_adminquiryticket(HWND hWnd);
void menu_user(HWND hWnd);
void menu_userquiry(HWND hWnd);
void menu_usermodify(HWND hWnd);
//时间函数
void delay(int seconds);//延时函数
void Countdown(int seconds);//等待定时
void getData(char *date);//获取彩票期号
//密码掩藏
void gotXY(int x,int y);
int posx();
int posy();
void GetPasscode(char* pwd);


//
void admin_loginw(HWND hWnd);//登录窗口
void admin_function(HWND hWnd);//功能窗口
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
#include "head.h"

USER *getUser_txt(){//从文件获取用户到链表
    USER *head,*q,*temp;
    head=(USER *)malloc(sizeof(USER));
    if(head==NULL){
        printf("申请内存失败！\n");
        exit(0);
    }
    q = head;
    head->next = NULL;
    FILE *fp=fopen("user.txt","rb");
    if(fp==NULL){
        printf("连接服务器失败！");
        exit(0);
    }
    while(1){
        temp=malloc(sizeof(USER));
        if(fscanf(fp,"姓名：%s 密码：%s 账户余额：%d\n",temp->name,temp->password,&temp->userBalance)==EOF)break;
        q->next=temp;
        q=temp;
        q->next=NULL;
    }
    fclose(fp);
    free(temp);
    temp=NULL;
    return head->next;
}
void putUser_txt(USER *users){//存入txt
    FILE *fp=fopen("user.txt","w");
    if(fp==NULL){
        printf("连接服务器失败！");
        exit(0);
    }
    USER *temp=users;
    while(temp!=NULL){
        fprintf(fp,"姓名：%s 密码：%s 账户余额：%d\n",temp->name,temp->password,temp->userBalance);
        temp=temp->next;
    }
    fclose(fp);
    fp=NULL;
}
void registerUser(USER *users){//注册用户
    char name[20];
    char code1[20];
    char code2[20];
    int flag=0;
    USER *temp=users;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    USER *newuser =malloc(sizeof(USER));
    if(newuser==NULL){
        printf("申请内存失败！\n");
        exit(0);
    }
    while(1){
        printf("请输入用户名：");
        scanf("%s",name);
        flag=check(users,name);
        if(flag==1){
            printf("该用户名已经存在，请重新输入！\n");
        }else{
            break;
        }
    }
    while(1){
        printf("请输入密码：");
        GetPasscode(code1);
        printf("\n请再次输入密码：");
        GetPasscode(code2);
        if(strcmp(code1,code2)==0){
            break;
        }else{
            printf("两次密码输入不一致，请重新输入！\n");
        }
    }
    strcpy(newuser->name,name);
    strcpy(newuser->password,code1);
    newuser->userBalance=0;
    temp->next=newuser;
    temp=newuser;
    temp->next=NULL;
    putUser_txt(users);
    printf("\n注册成功！\n");
    delay(3);
}
int check(USER *users,char *name){//检查用户名存在
    USER *temp=users->next;
    int flag=0;
    while(temp!=NULL){
        char *str=strlwr(temp->name);
        if(strcmp(str,name)==0){
            flag=1;
            return flag;
        }
        temp=temp->next;
    }
    return flag;
}
void recharge(USER *users,char *name){
    USER *temp=users->next;
    while(temp!=NULL){
        if(strcmp(temp->name,name)==0){
            break;
        }
        temp=temp->next;
    }
    int money=0;
    printf("请输入您想充值的金额：");
    scanf("%d",&money);
    temp->userBalance+=money;
    putUser_txt(users);
    printf("充值成功！您的余额为%d\n",temp->userBalance);
}
//彩民登录
int user_login(char *name,char *password){
    USER *temp=U->next;
    int flag=0;
    while(temp!=NULL){
        if(!strcmp(temp->name,name)&&!strcmp(temp->password,password)){
            flag=1;
        }
        temp=temp->next;
    }
    return flag;
}
void userquire_curr(HWND hWnd){
    Id_t *temp=I->next;
    Td_t *temp1=T->next;
    int flag=0;
    while(temp!=NULL){
        if(temp->lotteryState==0){
            break;
        }
        temp=temp->next;
        if(temp==NULL){
            SendMessage(GetDlgItem(hWnd, ID_LISTBOX5), LB_ADDSTRING, 0, (LPARAM)"当期彩票还未发售！");
            return;
        }
    }
    char box1[200];
    sprintf(box1,"彩票信息：期号：%s 单价：%d 当期售出：%d 奖池金额：%d",temp->issueID,temp->unitPrice,temp->totalSales,temp->currentPrizePool);
    SendMessage(GetDlgItem(hWnd, ID_LISTBOX8), LB_ADDSTRING, 0, (LPARAM)box1);
}
void ticket_issue(HWND hWnd,char *name,int bet,int *arr){
    Id_t *temp=I->next;
    USER *p=U->next;
    Td_t *q=T;
    int count=1;
    MessageBox(hWnd,"！","提示",MB_OK);
    while(p!=NULL){
        if(!strcmp(p->name,name)){
            break;
        }
        p=p->next;
    }
    while(temp!=NULL){
        if(temp->lotteryState==0){
            break;
        }
        temp=temp->next;
    }
    int sum=bet*temp->unitPrice;
    MessageBox(hWnd,"2222","提示",MB_OK);
    if(p->userBalance<sum){
        MessageBox(hWnd,"余额不足，请充值！","提示",MB_OK);
        return;
    }else{
        p->userBalance-=sum;
        temp->currentPrizePool+=sum;
        temp->totalSales+=bet;
    }
    MessageBox(hWnd,"！！！","提示",MB_OK);
    Td_t *newticket=malloc(sizeof(Td_t));
    strcpy(newticket->issueID,temp->issueID);
    newticket->unitPrice=temp->unitPrice;
    newticket->lotteryState=temp->lotteryState;
    ticket_num(newticket->Number,arr);
    newticket->betNumber=bet;
    newticket->jackPots=0;
    newticket->state=0;
    strcpy(newticket->name,name);
    while(q->next!=NULL){
        if(!strcmp(q->next->issueID,newticket->issueID)){
            count++;
        }
        q=q->next;
    }
    newticket->ticketID=count;
    q->next=newticket;
    q=newticket;
    q->next=NULL;
    MessageBox(hWnd,"购买成功！","提示",MB_OK);
    putUser_txt(U);
    putIssue_txt(I);
    putticket_txt(T);
    newticket=NULL;
    free(newticket);
}
void ticket_num(int *arr1,int *arr2){
    for(int i=0;i<7;i++){
        arr1[i]=arr2[i];
    }
}
void quiry_userinf(HWND hWnd,char *name){
    USER *temp=U->next;
    while(temp!=NULL){
        if(!strcmp(temp->name,name)){
            break;
        }
        temp=temp->next;
    }
    char box1[100];
    sprintf(box1,"个人信息：用户名：%s 密码：%s 余额：%d",temp->name,temp->password,temp->userBalance);
    SendMessage(GetDlgItem(hWnd, ID_LISTBOX9), LB_ADDSTRING, 0, (LPARAM)box1);
}
void quiry_buyticket(Td_t *ticket,char *name){
    Td_t *temp=ticket->next;
    int flag=0;
    if(temp==NULL){
        printf("未查询到您的购买记录！\n");
        return;
    }
    printf("您的购买记录如下：\n");
    while(temp!=NULL){
        if(!strcmp(temp->name,name)){
            flag=1;
            printf("发行期号：%s 彩票ID：%d 彩票单价：%d 注数：%d 开奖状态：%d 购买号码：%d %d %d %d %d %d %d\n",temp->issueID,temp->ticketID,temp->unitPrice,temp->betNumber,temp->lotteryState,temp->Number[0],temp->Number[1],temp->Number[2],temp->Number[3],temp->Number[4],temp->Number[5],temp->Number[6]);
        }
        temp=temp->next;
    }
    if(flag!=1){
        printf("您的购买记录为空！\n");
    }
}
void quiry_userwin(Td_t *pwinner,char *name){
    int flag=0;
    Td_t *temp=pwinner->next;
    if(temp==NULL){
        printf("您的中奖记录为空！\n");
        return;
    }while(temp!=NULL){
        if(!strcmp(temp->name,name)){
            flag=1;
            printf("发行期号：%s 彩票ID：%d 彩票单价：%d 注数：%d 兑奖：%d 中奖金额：%d 购买号码：%d %d %d %d %d %d %d\n",temp->issueID,temp->ticketID,temp->unitPrice,temp->betNumber,temp->state,temp->jackPots,temp->Number[0],temp->Number[1],temp->Number[2],temp->Number[3],temp->Number[4],temp->Number[5],temp->Number[6]);
        }
        temp=temp->next;
    }
    if(flag!=1){
        printf("您还未中获奖，请加大马力购买彩票！\n");
    }
}
void modify_user(USER *users,char *name){
    while(1){
        int select=0;
        //menu_user2();
        scanf("%d",&select);
        switch(select){
            case 1:modify_userName(users,name);
                    delay(1);
                break;
            case 2:modify_userPassword(users,name);
                    delay(1);
                break;
            case 3:return;
                break;
            default:
                break;
        }
    }
}
void modify_userName(USER *users,char *name){
    USER *temp=users->next;
    while(temp!=NULL){
        if(!strcmp(temp->name,name)){
            break;
        }
        temp=temp->next;
    }
    char name1[20]="0";
    int flag=0;
    while(1){
        printf("请输入修改的用户名：");
        scanf("%s",name1);
        flag=check(users,name1);
        if(flag==0){
            break;
        }else{
            printf("该用户名已经存在，请重新输入！\n");
        }
    }
    strcpy(temp->name,name1);
    putUser_txt(users);
    printf("修改成功！\n");
}
void modify_userPassword(USER *users,char *name){
    USER *temp=users->next;
    while(temp!=NULL){
        if(!strcmp(temp->name,name)){
            break;
        }
        temp=temp->next;
    }
    char code[20]="0";
    char code1[20]="0";
    char code2[20]="0";
    int flag=0;
    while(1){
        printf("\n请输入原密码：");
        GetPasscode(code);
        if(!strcmp(temp->password,code)){
            while (1){
                printf("\n请输入修改后的密码：");
                GetPasscode(code1);
                printf("\n请再次输入修改后的密码：");
                GetPasscode(code2);
                if(!strcmp(code1,code2)){
                    strcpy(temp->password,code1);
                    printf("\n修改成功!\n");
                    putUser_txt(users);
                    return;
                }else{
                    printf("\n两次密码不一致，请重新输入！\n");
                    }
                }
        }else{
            if(flag==0){
                printf("\n原密码输入错误次数过多，请检查后在进行修改！\n");
                return;
            }
            else{
                printf("\n原密码错误，你还有%d次机会，请重新输入！\n",flag);
                flag--;
            }
        }
    }
}
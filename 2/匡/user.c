#include "head.h"

USER *getUser_txt(){//���ļ���ȡ�û�������
    USER *head,*q,*temp;
    head=(USER *)malloc(sizeof(USER));
    if(head==NULL){
        printf("�����ڴ�ʧ�ܣ�\n");
        exit(0);
    }
    q = head;
    head->next = NULL;
    FILE *fp=fopen("user.txt","rb");
    if(fp==NULL){
        printf("���ӷ�����ʧ�ܣ�");
        exit(0);
    }
    while(1){
        temp=malloc(sizeof(USER));
        if(fscanf(fp,"������%s ���룺%s �˻���%d\n",temp->name,temp->password,&temp->userBalance)==EOF)break;
        q->next=temp;
        q=temp;
        q->next=NULL;
    }
    fclose(fp);
    free(temp);
    temp=NULL;
    return head->next;
}
void putUser_txt(USER *users){//����txt
    FILE *fp=fopen("user.txt","w");
    if(fp==NULL){
        printf("���ӷ�����ʧ�ܣ�");
        exit(0);
    }
    USER *temp=users;
    while(temp!=NULL){
        fprintf(fp,"������%s ���룺%s �˻���%d\n",temp->name,temp->password,temp->userBalance);
        temp=temp->next;
    }
    fclose(fp);
    fp=NULL;
}
int registerUser(HWND hWnd,char *name,char *password){//ע���û�
    int flag=0;
    USER *temp=U;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    flag=check(U,name);
    if(flag==1){
        MessageBox(hWnd,"���û����Ѵ��ڣ�","��ʾ",MB_OK);
        return 1;
    }
    USER *newuser=malloc(sizeof(USER));
    strcpy(newuser->name,name);
    strcpy(newuser->password,password);
    newuser->userBalance=0;
    temp->next=newuser;
    temp=newuser;
    temp->next=NULL;
    putUser_txt(U);
    return flag;
}
int check(USER *users,char *name){//����û�������
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
void banlance(HWND hWnd,char *name){
    USER *temp=U->next;
    while(temp!=NULL){
        if(!strcmp(temp->name,name)){
            break;
        }
        temp=temp->next;
    }
    char box1[100];
    sprintf(box1,"��%d",temp->userBalance);
    SendMessage(GetDlgItem(hWnd, ID_LISTBOX11), LB_ADDSTRING, 0, (LPARAM)box1);
}
void recharge(HWND hWnd,char *name,int money){
    USER *temp=U->next;
    while(temp!=NULL){
        if(strcmp(temp->name,name)==0){
            break;
        }
        temp=temp->next;
    }
    temp->userBalance+=money;
    putUser_txt(U);
    char message[100];
    sprintf(message,"��ֵ�ɹ���Ŀǰ�����Ϊ��%d",temp->userBalance);
    MessageBox(hWnd, message, "��ʾ", MB_OK);
}
//�����¼
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
            MessageBox(hWnd,"��δ���۲�Ʊ��","��ʾ",MB_OK);
            return;
        }
    }
    char box1[200];
    sprintf(box1,"��Ʊ��Ϣ���ںţ�%s ���ۣ�%d �����۳���%d ���ؽ�%d",temp->issueID,temp->unitPrice,temp->totalSales,temp->currentPrizePool);
    SendMessage(GetDlgItem(hWnd, ID_LISTBOX8), LB_ADDSTRING, 0, (LPARAM)box1);
}
void ticket_issue(HWND hWnd,char *name,int bet,int *arr){
    Id_t *temp=I->next;
    USER *p=U->next;
    Td_t *q=T;
    int count=1;
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
    if(p->userBalance<sum){
        MessageBox(hWnd,"���㣬���ֵ��","��ʾ",MB_OK);
        return;
    }else{
        p->userBalance-=sum;
        temp->currentPrizePool+=sum;
        temp->totalSales+=bet;
    }
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
    MessageBox(hWnd,"����ɹ���","��ʾ",MB_OK);
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
    sprintf(box1,"������Ϣ���û�����%s ���룺%s ��%d",temp->name,temp->password,temp->userBalance);
    SendMessage(GetDlgItem(hWnd, ID_LISTBOX9), LB_ADDSTRING, 0, (LPARAM)box1);
}
void quiry_buyticket(HWND hWnd,char *name){
    Td_t *temp=T->next;
    int flag=0;
    if(temp==NULL){
        MessageBox(hWnd,"δ��ѯ��������Ϣ��","��ʾ",MB_OK);
        return;
    }
    while(temp!=NULL){
        if(!strcmp(temp->name,name)){
            flag=1;
            char box1[200];
            sprintf(box1,"������Ϣ���ںţ�%s ID��%d ���ۣ�%d ע����%d ����״̬��%d ������룺%d %d %d %d %d %d %d",temp->issueID,temp->ticketID,temp->unitPrice,temp->betNumber,temp->lotteryState,temp->Number[0],temp->Number[1],temp->Number[2],temp->Number[3],temp->Number[4],temp->Number[5],temp->Number[6]);
            SendMessage(GetDlgItem(hWnd, ID_LISTBOX10), LB_ADDSTRING, 0, (LPARAM)box1);
        }
        temp=temp->next;
    }
    if(flag!=1){
        MessageBox(hWnd,"δ��ѯ��������Ϣ��","��ʾ",MB_OK);
    }
}
void quiry_userwin(HWND hWnd,char *name){
    int flag=0;
    Td_t *temp=Pwinner->next;
    if(temp==NULL){
        MessageBox(hWnd,"δ��ѯ���н���Ϣ��","��ʾ",MB_OK);
        return;
    }while(temp!=NULL){
        if(!strcmp(temp->name,name)){
            flag=1;
            char box1[200];
            sprintf(box1,"�н���Ϣ���ںţ�%s ID��%d ���ۣ�%d ע����%d �ҽ���%d �н���%d ������룺%d %d %d %d %d %d %d",temp->issueID,temp->ticketID,temp->unitPrice,temp->betNumber,temp->state,temp->jackPots,temp->Number[0],temp->Number[1],temp->Number[2],temp->Number[3],temp->Number[4],temp->Number[5],temp->Number[6]);
            SendMessage(GetDlgItem(hWnd, ID_LISTBOX11), LB_ADDSTRING, 0, (LPARAM)box1);
        }
        temp=temp->next;
    }
    if(flag!=1){
        MessageBox(hWnd,"����û���н���¼��","��ʾ",MB_OK);
    }
}
int modify_userName(HWND hWnd,char *name1,char *name2){
    USER *temp=U->next;
    Td_t *temp1=T->next;
    while(temp!=NULL){
        if(!strcmp(temp->name,name1)){
            break;
        }
        temp=temp->next;
    }
    int flag=0;
    flag=check(U,name2);
    if(flag!=0){
        MessageBox(hWnd,"�û����ظ������������룡","��ʾ",MB_OK);
        return flag;
    }
    strcpy(temp->name,name2);
    while(temp1!=NULL){
        if(!strcmp(temp1->name,name1)){
            strcpy(temp1->name,name2);
        }
        temp1=temp1->next;
    }
    putticket_txt(T);
    putprevwinner_txt(T);
    putUser_txt(U);
    Td_t *temp3=getprvewinner_txt();
    Pwinner->next=temp3->next;
    MessageBox(hWnd,"�޸ĳɹ���","��ʾ",MB_OK);
    return flag;
}
void modify_userPassword(HWND hWnd,char *password,char *name){
    USER *temp=U->next;
    while(temp!=NULL){
        if(!strcmp(temp->name,name)){
            break;
        }
        temp=temp->next;
    }
    strcpy(temp->password,password);
    putUser_txt(U);
    MessageBox(hWnd,"�޸ĳɹ���","��ʾ",MB_OK);
}
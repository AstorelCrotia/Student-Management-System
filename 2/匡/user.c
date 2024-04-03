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
void registerUser(USER *users){//ע���û�
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
        printf("�����ڴ�ʧ�ܣ�\n");
        exit(0);
    }
    while(1){
        printf("�������û�����");
        scanf("%s",name);
        flag=check(users,name);
        if(flag==1){
            printf("���û����Ѿ����ڣ����������룡\n");
        }else{
            break;
        }
    }
    while(1){
        printf("���������룺");
        GetPasscode(code1);
        printf("\n���ٴ��������룺");
        GetPasscode(code2);
        if(strcmp(code1,code2)==0){
            break;
        }else{
            printf("�����������벻һ�£����������룡\n");
        }
    }
    strcpy(newuser->name,name);
    strcpy(newuser->password,code1);
    newuser->userBalance=0;
    temp->next=newuser;
    temp=newuser;
    temp->next=NULL;
    putUser_txt(users);
    printf("\nע��ɹ���\n");
    delay(3);
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
void recharge(USER *users,char *name){
    USER *temp=users->next;
    while(temp!=NULL){
        if(strcmp(temp->name,name)==0){
            break;
        }
        temp=temp->next;
    }
    int money=0;
    printf("�����������ֵ�Ľ�");
    scanf("%d",&money);
    temp->userBalance+=money;
    putUser_txt(users);
    printf("��ֵ�ɹ����������Ϊ%d\n",temp->userBalance);
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
            SendMessage(GetDlgItem(hWnd, ID_LISTBOX5), LB_ADDSTRING, 0, (LPARAM)"���ڲ�Ʊ��δ���ۣ�");
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
    MessageBox(hWnd,"��","��ʾ",MB_OK);
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
    MessageBox(hWnd,"2222","��ʾ",MB_OK);
    if(p->userBalance<sum){
        MessageBox(hWnd,"���㣬���ֵ��","��ʾ",MB_OK);
        return;
    }else{
        p->userBalance-=sum;
        temp->currentPrizePool+=sum;
        temp->totalSales+=bet;
    }
    MessageBox(hWnd,"������","��ʾ",MB_OK);
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
void quiry_buyticket(Td_t *ticket,char *name){
    Td_t *temp=ticket->next;
    int flag=0;
    if(temp==NULL){
        printf("δ��ѯ�����Ĺ����¼��\n");
        return;
    }
    printf("���Ĺ����¼���£�\n");
    while(temp!=NULL){
        if(!strcmp(temp->name,name)){
            flag=1;
            printf("�����ںţ�%s ��ƱID��%d ��Ʊ���ۣ�%d ע����%d ����״̬��%d ������룺%d %d %d %d %d %d %d\n",temp->issueID,temp->ticketID,temp->unitPrice,temp->betNumber,temp->lotteryState,temp->Number[0],temp->Number[1],temp->Number[2],temp->Number[3],temp->Number[4],temp->Number[5],temp->Number[6]);
        }
        temp=temp->next;
    }
    if(flag!=1){
        printf("���Ĺ����¼Ϊ�գ�\n");
    }
}
void quiry_userwin(Td_t *pwinner,char *name){
    int flag=0;
    Td_t *temp=pwinner->next;
    if(temp==NULL){
        printf("�����н���¼Ϊ�գ�\n");
        return;
    }while(temp!=NULL){
        if(!strcmp(temp->name,name)){
            flag=1;
            printf("�����ںţ�%s ��ƱID��%d ��Ʊ���ۣ�%d ע����%d �ҽ���%d �н���%d ������룺%d %d %d %d %d %d %d\n",temp->issueID,temp->ticketID,temp->unitPrice,temp->betNumber,temp->state,temp->jackPots,temp->Number[0],temp->Number[1],temp->Number[2],temp->Number[3],temp->Number[4],temp->Number[5],temp->Number[6]);
        }
        temp=temp->next;
    }
    if(flag!=1){
        printf("����δ�л񽱣���Ӵ����������Ʊ��\n");
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
        printf("�������޸ĵ��û�����");
        scanf("%s",name1);
        flag=check(users,name1);
        if(flag==0){
            break;
        }else{
            printf("���û����Ѿ����ڣ����������룡\n");
        }
    }
    strcpy(temp->name,name1);
    putUser_txt(users);
    printf("�޸ĳɹ���\n");
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
        printf("\n������ԭ���룺");
        GetPasscode(code);
        if(!strcmp(temp->password,code)){
            while (1){
                printf("\n�������޸ĺ�����룺");
                GetPasscode(code1);
                printf("\n���ٴ������޸ĺ�����룺");
                GetPasscode(code2);
                if(!strcmp(code1,code2)){
                    strcpy(temp->password,code1);
                    printf("\n�޸ĳɹ�!\n");
                    putUser_txt(users);
                    return;
                }else{
                    printf("\n�������벻һ�£����������룡\n");
                    }
                }
        }else{
            if(flag==0){
                printf("\nԭ�����������������࣬������ڽ����޸ģ�\n");
                return;
            }
            else{
                printf("\nԭ��������㻹��%d�λ��ᣬ���������룡\n",flag);
                flag--;
            }
        }
    }
}
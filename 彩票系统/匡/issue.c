#include "head.h"

Id_t *getIssue_txt(){
    Id_t *head,*p,*temp;
    head=malloc(sizeof(Id_t));
    if(head==NULL){
        printf("申请内存失败！\n");
        exit(0);
    }
    p=head;
    head->next=NULL;
    FILE *fp=fopen("issue.txt","rb");
    if(fp==NULL){
        printf("连接服务器失败！");
        exit(0);
    }
    while(1){
        temp=malloc(sizeof(Id_t));
        if(fscanf(fp,"发行期号：%s 彩票单价：%d 开奖状态：%d 当期售出总数：%d 奖池总金额：%d 中奖号码：%d %d %d %d %d %d %d\n",temp->issueID,&temp->unitPrice,&temp->lotteryState,&temp->totalSales,&temp->currentPrizePool,&temp->winningNumbers[0],&temp->winningNumbers[1],&temp->winningNumbers[2],&temp->winningNumbers[3],&temp->winningNumbers[4],&temp->winningNumbers[5],&temp->winningNumbers[6])==EOF)break;
        p->next=temp;
        p=temp;
        p->next=NULL;
    }
    fclose(fp);
    free(temp);
    temp=NULL;
    return head;
}
void putIssue_txt(Id_t *head){
    FILE *fp = fopen("issue.txt", "wb");
    if (fp == NULL) {
        printf("无法打开文件！");
        exit(0);
    }
    Id_t *temp=head->next;
    while(temp!=NULL){
        fprintf(fp, "发行期号：%s 彩票单价：%d 开奖状态：%d 当期售出总数：%d 奖池总金额：%d 中奖号码：%d %d %d %d %d %d %d\n",temp->issueID,temp->unitPrice,temp->lotteryState,temp->totalSales,temp->currentPrizePool,temp->winningNumbers[0],temp->winningNumbers[1],temp->winningNumbers[2],temp->winningNumbers[3],temp->winningNumbers[4],temp->winningNumbers[5],temp->winningNumbers[6]);
        temp=temp->next;
    }
    fclose(fp);
}
void Issue_lottery(int unitPrice,int currentPrizePool,HWND hWnd){
    if(unitPrice<=0&&currentPrizePool<=0){
        MessageBox(hWnd, "单价或者总奖金输入有误！\n", "提示", MB_OK);
        return; 
    }
    Id_t *temp=I->next,*p=I;
    while(temp!=NULL){
        if(temp->lotteryState!=1){
            MessageBox(hWnd, "已发售的彩票还未开奖！\n", "提示", MB_OK);
            return;
        }else{
            temp=temp->next;
            p=p->next;
        }
    }
    Id_t *newissue=malloc(sizeof(Id_t));
    getData(newissue->issueID);
    newissue->lotteryState=0;
    rand_winNumber(newissue);
    newissue->totalSales=0;
    newissue->unitPrice=unitPrice;
    if(p==I){
        newissue->currentPrizePool=currentPrizePool;
    }else{
        newissue->currentPrizePool=p->currentPrizePool+currentPrizePool;
    }
    p->next=newissue;
    p=newissue;
    p->next=NULL;
    putIssue_txt(I);
    char message[100];
    sprintf(message, "发行期号：%s 彩票单价：%d 开奖状态：%d 奖池总金额：%d", p->issueID,p->unitPrice,p->lotteryState,p->currentPrizePool);
    MessageBox(hWnd, message, "提示", MB_OK);
    newissue=NULL;
    free(newissue);
}
void rand_winNumber(Id_t *head){
    srand(time(0));
    for(int i=0;i<7;i++){
        if(i<5){
            head->winningNumbers[i]=rand()%32;
        }else{
            head->winningNumbers[i]=rand()%10;
        }
    }
}
void Draw_lottery(HWND hWnd){
    Id_t *temp=I;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    if(temp==I){
          MessageBox(hWnd, "还未发售彩票！\n", "提示", MB_OK);
          return;
    }
    temp->lotteryState=1;
    MessageBox(hWnd, "开奖成功！\n", "提示", MB_OK);
    paylevel();
    payout();
    putIssue_txt(I);
    putticket_txt(T);
    putUser_txt(U);
    putprevwinner_txt(T);
    Td_t *temp1=getprvewinner_txt();
    Pwinner->next=temp1->next;
}
void paylevel(){
    Id_t *temp1=I;
    Td_t *temp2=T->next;
    int count1=0;
    int count2=0;
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        if(!strcmp(temp2->issueID,temp1->issueID)){
            for(int i=0;i<7;i++){
                if(i<=5){
                    if(temp1->winningNumbers[i]==temp2->Number[i]){
                        count1++;
                    }
                }else{
                    if(temp1->winningNumbers[i]==temp2->Number[i]){
                        count2++;
                    }
                }
            }
            if(count1==6&&count2==1){
                temp2->lotteryState=1;
            }else if(count1<6&&count1>=3&&count2==1){
                temp2->lotteryState=2;
            }else if(count1>=1&&count1<3&&count2==1){
                temp2->lotteryState=3;
            }else{
                temp2->lotteryState=5;
            }
        }
        temp2=temp2->next;
    }
}
void payout(){
    USER *temp1=U->next;
    Td_t *temp2=T->next;
    Id_t *temp3=I;
    while(temp3->next!=NULL){
        temp3=temp3->next;
    }
    while(temp2!=NULL){
        if(!strcmp(temp3->issueID,temp2->issueID)){
            while(temp1!=NULL){
                int money=0;
                if(!strcmp(temp1->name,temp2->name)&&temp2->state==0){
                    if(temp2->lotteryState==1){
                        money=300000*(temp2->betNumber);
                        temp1->userBalance+=money;
                    }else if(temp2->lotteryState==2){
                        money=100000*(temp2->betNumber);
                        temp1->userBalance+=money;
                    }else if(temp2->lotteryState==3){
                        money=30000*(temp2->betNumber);
                        temp1->userBalance+=money;
                    }else{
                        temp1->userBalance+=0;
                    }
                    temp2->jackPots=money;
                    temp3->currentPrizePool-=money;
                    temp2->state=1;
                    break;
                }
                temp1=temp1->next;
            }
        }
        temp1=temp1=U->next;
        temp2=temp2->next;
    }
}
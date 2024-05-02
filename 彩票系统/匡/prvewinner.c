#include "head.h"

Td_t *getprvewinner_txt(){
    Td_t *head,*p,*temp;
    head=malloc(sizeof(Td_t));
    if(head==NULL){
        printf("申请内存失败！\n");
        exit(0);
    }
    p=head;
    head->next=NULL;
    FILE *fp=fopen("prvewinner.txt","rb");
    if(fp==NULL){
        printf("连接服务器失败！");
        exit(0);
    }
    while(1){
        temp=malloc(sizeof(Td_t));
        if(fscanf(fp,"发行期号：%s 彩票ID：%d 彩票单价：%d 注数：%d 兑奖：%d 中奖金额：%d 购买者：%s 购买号码：%d %d %d %d %d %d %d\n",temp->issueID,&temp->ticketID,&temp->unitPrice,&temp->betNumber,&temp->state,&temp->jackPots,temp->name,&temp->Number[0],&temp->Number[1],&temp->Number[2],&temp->Number[3],&temp->Number[4],&temp->Number[5],&temp->Number[6])==EOF)break;
        p->next=temp;
        p=temp;
        p->next=NULL;
    }
    fclose(fp);
    free(temp);
    temp=NULL;
    return head;
}
void putprevwinner_txt(Td_t *head){
    FILE *fp = fopen("prvewinner.txt", "wb");
    if (fp == NULL) {
        printf("无法打开文件！");
        exit(0);
    }
    Td_t *temp=head->next;
    while(temp!=NULL){
        if(temp->lotteryState!=5){
            fprintf(fp,"发行期号：%s 彩票ID：%d 彩票单价：%d 注数：%d 兑奖：%d 中奖金额：%d 购买者：%s 购买号码：%d %d %d %d %d %d %d\n",temp->issueID,temp->ticketID,temp->unitPrice,temp->betNumber,temp->state,temp->jackPots,temp->name,temp->Number[0],temp->Number[1],temp->Number[2],temp->Number[3],temp->Number[4],temp->Number[5],temp->Number[6]);
        }
        temp=temp->next;
    }
    fclose(fp);
}
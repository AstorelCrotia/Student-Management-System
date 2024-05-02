#include "head.h"

Td_t *getprvewinner_txt(){
    Td_t *head,*p,*temp;
    head=malloc(sizeof(Td_t));
    if(head==NULL){
        printf("�����ڴ�ʧ�ܣ�\n");
        exit(0);
    }
    p=head;
    head->next=NULL;
    FILE *fp=fopen("prvewinner.txt","rb");
    if(fp==NULL){
        printf("���ӷ�����ʧ�ܣ�");
        exit(0);
    }
    while(1){
        temp=malloc(sizeof(Td_t));
        if(fscanf(fp,"�����ںţ�%s ��ƱID��%d ��Ʊ���ۣ�%d ע����%d �ҽ���%d �н���%d �����ߣ�%s ������룺%d %d %d %d %d %d %d\n",temp->issueID,&temp->ticketID,&temp->unitPrice,&temp->betNumber,&temp->state,&temp->jackPots,temp->name,&temp->Number[0],&temp->Number[1],&temp->Number[2],&temp->Number[3],&temp->Number[4],&temp->Number[5],&temp->Number[6])==EOF)break;
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
        printf("�޷����ļ���");
        exit(0);
    }
    Td_t *temp=head->next;
    while(temp!=NULL){
        if(temp->lotteryState!=5){
            fprintf(fp,"�����ںţ�%s ��ƱID��%d ��Ʊ���ۣ�%d ע����%d �ҽ���%d �н���%d �����ߣ�%s ������룺%d %d %d %d %d %d %d\n",temp->issueID,temp->ticketID,temp->unitPrice,temp->betNumber,temp->state,temp->jackPots,temp->name,temp->Number[0],temp->Number[1],temp->Number[2],temp->Number[3],temp->Number[4],temp->Number[5],temp->Number[6]);
        }
        temp=temp->next;
    }
    fclose(fp);
}
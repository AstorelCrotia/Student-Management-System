#include "head.h"

int admin_login(char *name,char *password){
    USER *temp=U;
    int flag=0;
    if(!strcmp(temp->name,name)&&!strcmp(temp->password,password)){
        flag=1;
    }
    return flag;
}
void quire_admin(HWND hWnd){
    USER *temp=U;
    char message[100] = ""; 
    sprintf(message, "������%s�����룺%s����%d\n", temp->name, temp->password, temp->userBalance);
    MessageBox(hWnd, message, "����Ա��Ϣ", MB_OK);
}
void quire_admintoUserlist(HWND hWnd){
    USER *temp1=U->next;
    if(temp1==NULL){
        SendMessage(GetDlgItem(hWnd, ID_LISTBOX1), LB_ADDSTRING, 0, (LPARAM)"�û��б�Ϊ��");
        return;
    }
    while(temp1!=NULL){
        SendMessage(GetDlgItem(hWnd, ID_LISTBOX1), LB_ADDSTRING, 0, (LPARAM)temp1->name);
        temp1=temp1->next;
    }
}
void quire_admintoUser(HWND hWnd,char *name){
    USER *temp1=U->next;
    Td_t *temp2=T->next;
    Td_t *temp3=Pwinner->next;
    int flag=0;
    int flag1=0;
    int flag2=0;
    while(temp1!=NULL){
        if(!strcmp(temp1->name,name)){
            flag=1;
            char box1[100];
            sprintf(box1,"������%s ��%d",name,temp1->userBalance);
            SendMessage(GetDlgItem(hWnd, ID_LISTBOX4), LB_ADDSTRING, 0, (LPARAM)box1);
            while(temp2!=NULL){
                if(!strcmp(temp2->name,name)){
                    flag1=1;
                    char box2[200];
                    sprintf(box2,"�����¼���ںţ�%s ID��%d ���ۣ�%d ע����%d ״̬��%d �ҽ���%d �û���%s ���룺%d %d %d %d %d %d %d",temp2->issueID,temp2->ticketID,temp2->unitPrice,temp2->betNumber,temp2->lotteryState,temp2->state,temp2->name,temp2->Number[0],temp2->Number[1],temp2->Number[2],temp2->Number[3],temp2->Number[4],temp2->Number[5],temp2->Number[6]);
                    SendMessage(GetDlgItem(hWnd, ID_LISTBOX2), LB_ADDSTRING, 0, (LPARAM)box2);
                }
                temp2=temp2->next;
            }
            if(flag1!=1){
                SendMessage(GetDlgItem(hWnd, ID_LISTBOX2), LB_ADDSTRING, 0, (LPARAM)"��Ʊ��¼Ϊ�գ�");
            }
            while(temp3!=NULL){
                if(!strcmp(temp3->name,name)){
                    flag2=1;
                    char box3[200];
                    sprintf(box3,"�н���¼���ںţ�%s ID��%d ���ۣ�%d ע����%d �ҽ���%d �н���%d �û���%s ���룺%d %d %d %d %d %d %d",temp3->issueID,temp3->ticketID,temp3->unitPrice,temp3->betNumber,temp3->state,temp3->jackPots,temp3->name,temp3->Number[0],temp3->Number[1],temp3->Number[2],temp3->Number[3],temp3->Number[4],temp3->Number[5],temp3->Number[6]);
                    SendMessage(GetDlgItem(hWnd, ID_LISTBOX3), LB_ADDSTRING, 0, (LPARAM)box3);
                }
                temp3=temp3->next;
            }
            if(flag2!=1){
                SendMessage(GetDlgItem(hWnd, ID_LISTBOX3), LB_ADDSTRING, 0, (LPARAM)"�н���¼Ϊ�գ�");
            }
        }
        temp1=temp1->next;
    }
    if(flag!=1){
        SendMessage(GetDlgItem(hWnd, ID_LISTBOX4), LB_ADDSTRING, 0, (LPARAM)"���û������ڣ�");
    }
}
void quire_Pwinner(HWND hWnd){
    Id_t *temp=I->next;
    if(temp->lotteryState==0){
        MessageBox(hWnd, "���������ڲ�Ʊ��", "��ʾ", MB_OK);
        return;
    }
    while(temp!=NULL&&temp->lotteryState==1){
        SendMessage(GetDlgItem(hWnd, ID_LISTBOX), LB_ADDSTRING, 0, (LPARAM)temp->issueID);
        temp=temp->next;
    }
}
void quire_Pwinner1(HWND hWnd,char *issueID){
    Td_t *temp1=Pwinner->next;
    int flag=0;
    char message[10000]="";
    while(temp1!=NULL){
        if(!strcmp(temp1->issueID,issueID)){
            char box[200];
            flag=1;
            sprintf(box,"�ں�:%s,��ƱID:%d,����:%d,ע��:%d,�ҽ�:%d,����:%d,�û�:%s\n",temp1->issueID,temp1->ticketID,temp1->unitPrice,temp1->betNumber,temp1->state,temp1->jackPots,temp1->name);
            strcat(message,box);
        }
        temp1=temp1->next;
    }
    if(flag!=1){
        MessageBox(hWnd, "���ڲ�Ʊû���н��ߣ�", "��ʾ", MB_OK);
        return;
    }
    MessageBox(hWnd, message, "�����н���Ϣ", MB_OK);
}
void quire_curr(HWND hWnd){
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
    sprintf(box1,"��Ʊ��Ϣ���ںţ�%s ���ۣ�%d �����۳���%d ���ؽ�%d �н����룺%d %d %d %d %d %d %d",temp->issueID,temp->unitPrice,temp->totalSales,temp->currentPrizePool,temp->winningNumbers[0],temp->winningNumbers[1],temp->winningNumbers[2],temp->winningNumbers[3],temp->winningNumbers[4],temp->winningNumbers[5],temp->winningNumbers[6]);
    SendMessage(GetDlgItem(hWnd, ID_LISTBOX5), LB_ADDSTRING, 0, (LPARAM)box1);
    while(temp1!=NULL){
        if(!strcmp(temp1->issueID,temp->issueID)){
            char box2[200];
            flag=1;
            sprintf(box2,"��Ʊ��Ϣ��ID��%d ע����%d �û���%s ������룺%d %d %d %d %d %d %d",temp1->ticketID,temp1->betNumber,temp1->name,temp1->Number[0],temp1->Number[1],temp1->Number[2],temp1->Number[3],temp1->Number[4],temp1->Number[5],temp1->Number[6]);
            SendMessage(GetDlgItem(hWnd, ID_LISTBOX5), LB_ADDSTRING, 0, (LPARAM)box2);
        }
        temp1=temp1->next;
    }
    if(flag!=1){
        SendMessage(GetDlgItem(hWnd, ID_LISTBOX5), LB_ADDSTRING, 0, (LPARAM)"��δ�й����¼��");
    }
}
void quire_prvelist(HWND hWnd){
    Id_t *temp=I->next;
    if(temp->lotteryState==0){
        MessageBox(hWnd, "���������ڲ�Ʊ��", "��ʾ", MB_OK);
        return;
    }
    while(temp!=NULL&&temp->lotteryState==1){
        SendMessage(GetDlgItem(hWnd, ID_LISTBOX6), LB_ADDSTRING, 0, (LPARAM)temp->issueID);
        temp=temp->next;
    }
}
void quire_prve(HWND hWnd,char *id){
    Id_t *temp=I->next;
    Td_t *temp1=T->next;
    int flag=0;
    int flag1=0;
    while(temp!=NULL&&temp->lotteryState==1){
        if(!strcmp(temp->issueID,id)){
            flag=1;
            char box1[200];
            sprintf(box1,"��Ʊ��Ϣ���ںţ�%s ���ۣ�%d �۳�������%d �����ܽ�%d �н����룺%d %d %d %d %d %d %d",temp->issueID,temp->unitPrice,temp->totalSales,temp->currentPrizePool,temp->winningNumbers[0],temp->winningNumbers[1],temp->winningNumbers[2],temp->winningNumbers[3],temp->winningNumbers[4],temp->winningNumbers[5],temp->winningNumbers[6]);
            SendMessage(GetDlgItem(hWnd, ID_LISTBOX7), LB_ADDSTRING, 0, (LPARAM)box1);
            while(temp1!=NULL){
                if(!strcmp(temp1->issueID,temp->issueID)){
                    flag1=1;
                    char box2[200];
                    sprintf(box2,"ID��%d ע����%d �û���%s ������룺%d %d %d %d %d %d %d",temp1->ticketID,temp1->betNumber,temp1->name,temp1->Number[0],temp1->Number[1],temp1->Number[2],temp1->Number[3],temp1->Number[4],temp1->Number[5],temp1->Number[6]);
                    SendMessage(GetDlgItem(hWnd, ID_LISTBOX7), LB_ADDSTRING, 0, (LPARAM)box2);
                }
                temp1=temp1->next;
            }
            if(flag1!=1){
                SendMessage(GetDlgItem(hWnd, ID_LISTBOX7), LB_ADDSTRING, 0, (LPARAM)"���ڲ�Ʊ���˹���");
            }
            break;
        }
        temp=temp->next;
    }
    if(flag!=1){
        printf("���ڲ�Ʊ�����ڣ�\n");
    }
}
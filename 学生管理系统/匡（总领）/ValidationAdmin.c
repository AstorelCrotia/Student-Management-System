#include "head.h"
int ValidationAdmin(Administratorlist *Admin) //��֤����
{
    Administratorlist *trueuser=Admin;
    Administratorlist *sup=Admin;
    char name[20]="0";
    char code[20]="0";
    int flag = 2;
    int sc=0;
    printf("���������Ա�û�����");
    scanf("%s",name);
    while(trueuser!=NULL)
    {   
        if(!strcmp(trueuser->username,name)){
            break;
        }
        trueuser=trueuser->next;
        if(trueuser==NULL)
        {
            printf("����Ա�˻�������,����������!\n");
            printf("���������Ա�û�����");
            scanf("%s",name);
            trueuser=Admin;
        }
    }
    printf("���������룺");
    GetPasscode(code);
    char *trueCode=decrypt(trueuser->code);//��ý��ܺ������
    while (1)
    {
        if(flag==0){
            printf("\n������Ĵ��������������,�����Զ��˳�\n");
            exit(1);
        }
        if(!strcmp(trueCode,code)&&!strcmp(trueuser->username,sup->username)){
            printf("\n��¼�ɹ���\n");
            sc=1; 
            break;
        }else if(!strcmp(trueCode,code)){
            printf("\n��¼�ɹ���\n");
            sc=2;
            break;
        }else{
            printf("\n�������,�㻹��%d���������,�������������룡\n",flag);
            printf("���������룺");
            GetPasscode(code);
            flag--;
        }
    }
    return sc;
}
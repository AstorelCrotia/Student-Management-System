#include "head.h"

int ValidationStu() //��֤����
{
    Administrator tureuser;
    char name[20]="0";
    char code[20]="0";
    int flag = 2;
    int sc=0;
    FILE* file_read = fopen("users.txt","r");
    if(file_read == NULL)
    {
        printf("���ӷ�����ʧ�ܣ�\n");
        return;
    }
    fread(&tureuser,sizeof(Administrator),1,file_read);
    printf("������ѧ���û�����");
    scanf("%s",name);
    while(1)
    {
        if(!strcmp(tureuser.username,name)){
            break;
        }else{
            if(!feof(file_read)){
                fread(&tureuser,sizeof(Administrator),1,file_read);
            }else{
                printf("ѧ���˻�������,����������!\n");
                printf("������ѧ���û�����");
                scanf("%s",name);
            }
        }
    }
    printf("���������룺");
    scanf("%s",code);
    while (strcmp(tureuser.code,code)){
        getPassCode(tureuser.code);
        if(!strcmp(tureuser.code,code)){
            sc=1;
            return sc; 
        }else if(flag==0){
            printf("������Ĵ��������������,�����Զ��˳�\n");
            exit(1);
        }
        else{
            printf("�������,�㻹��%d���������,�������������룡\n",flag);
            printf("���������룺");
            scanf("%s",code);
            flag--;
        }
    }
}
#include "head.h"

void Validation(char username) //��֤����
{
    int tureusername = 0;
    int flag = 0;
    FILE* file_read = fopen("users.txt","r");
    if(file_read == NULL)
    {
        printf("���ӷ�����ʧ�ܣ�\n");
        return;
    }
    fread(tureusername,sizeof(int),1,file_read);
    while(username == tureusername)
    {
        printf("�û��������ڣ�\n��������롰1���������룬���롰2���˳���");
        scanf("%d",flag);
        if (flag == 2)
        {
            break;
        }
        else
        {
            printf("�������û���:");
            scanf("%s",username);
        }
    }
    printf("�û�����");
    fclose(file_read);
}
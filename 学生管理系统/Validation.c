#include "head.h"

void Validation(char * username) //��֤����
{
    
    int flag = 0;
    int i = 1;
    FILE* file_read = fopen("Students.txt","r");
    FILE* file_read = fopen("Admin.txt","r");
    if(file_read == NULL)
    {
        printf("���ӷ�����ʧ�ܣ�\n");
        return;
    }
    fread(tureusername,sizeof(Student),1,file_read);
    while(i != 3)
    {
        if(strcmp(username,tureusername) == 0)
        {
            printf("��ӭ��¼��\n");
            break;
        }
        else
        {
            printf("�û��������ڣ�\n");
            printf("���ǵ�%d����������㻹��%d�λ���\n",i,3-i);
            printf("��������롰1���������룬���롰2���˳���");
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
        i++;
    }
    fclose(file_read);
}
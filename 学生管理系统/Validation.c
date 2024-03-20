#include "head.h"

void Validation(char * username) //验证功能
{
    
    int flag = 0;
    int i = 1;
    FILE* file_read = fopen("Students.txt","r");
    FILE* file_read = fopen("Admin.txt","r");
    if(file_read == NULL)
    {
        printf("连接服务器失败！\n");
        return;
    }
    fread(tureusername,sizeof(Student),1,file_read);
    while(i != 3)
    {
        if(strcmp(username,tureusername) == 0)
        {
            printf("欢迎登录！\n");
            break;
        }
        else
        {
            printf("用户名不存在！\n");
            printf("这是第%d次输入错误，你还有%d次机会\n",i,3-i);
            printf("你可以输入“1”重新输入，输入“2”退出：");
            scanf("%d",flag);
            if (flag == 2)
            {
                break;
            }
            else
            {
                printf("请输入用户名:");
                scanf("%s",username);
            }
        }
        i++;
    }
    fclose(file_read);
}
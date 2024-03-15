#include "head.h"

void Validation(char username) //验证功能
{
    int tureusername = 0;
    int flag = 0;
    FILE* file_read = fopen("users.txt","r");
    if(file_read == NULL)
    {
        printf("连接服务器失败！\n");
        return;
    }
    fread(tureusername,sizeof(int),1,file_read);
    while(username == tureusername)
    {
        printf("用户名不存在！\n你可以输入“1”重新输入，输入“2”退出：");
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
    printf("用户存在");
    fclose(file_read);
}
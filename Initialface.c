#include "head.h"

char Initialface() //初始界面
{
    char username[20] = "0";
    printf("欢迎登录学生管理系统！\n");
    printf("请输入用户名:");
    scanf("%s",username);
    return username;
}

#include "head.h"

int Initialface() //初始界面
{   
    int i=0;
    printf("欢迎登录学生管理系统！\n");
    printf("请选择您的登录方式\n");
    printf("1.管理员登录     2.学生登录\n");
    scanf("%d",&i);
    return i;
}
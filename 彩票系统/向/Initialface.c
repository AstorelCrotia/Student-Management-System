#include "head.h"

void Initialface(char *id) //初始界面
{
    printf("============================\n");
    printf("|  欢迎登录彩票系统！      |\n");
    printf("============================\n");
    printf("请输入用户名:");
    scanf("%19s",id);
}
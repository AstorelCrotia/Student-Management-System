#include "head.h"

void Back(int *sc) //初始界面
{
    printf("============================\n");
    printf("|  重新登录输入“1”         |\n");
    printf("|                          |\n");
    printf("|  退出系统输入其他        |\n");
    printf("============================\n");
    printf("你的输入：");
    scanf(" %d",sc);
}
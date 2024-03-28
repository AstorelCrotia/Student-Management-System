#include "head.h"

void Initialface(int *sc) //初始界面
{
    printf("============================\n");
    printf("|  欢迎登录彩票系统！      |\n");
    printf("|                          |\n");
    printf("|  请选择你需要的功能！    |\n");
    printf("|                          |\n");
    printf("|  已有账户登录输入“1”     |\n");
    printf("|                          |\n");
    printf("|  注册账户输入“2”         |\n");
    printf("|                          |\n");
    printf("|  退出系统输入其他        |\n");
    printf("============================\n");
    printf("你的输入：");
    scanf(" %d",sc);
}
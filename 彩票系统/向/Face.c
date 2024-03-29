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

void Userface(int *sc,char *id) //用户界面
{
    printf("====================================\n");
    printf("|  欢迎用户：%s登录彩票系统！      |\n",id);
    printf("|                                |\n");
    printf("|  请选择你需要的功能！          |\n");
    printf("|                                |\n");
    printf("|  购买彩票输入“1”               |\n");
    printf("|                                |\n");
    printf("|  查询信息输入“2”               |\n");
    printf("|                                |\n");
    printf("|  提取余额输入“3”               |\n");
    printf("|                                |\n");
    printf("|  充值余额输入“4”               |\n");
    printf("|                                |\n");
    printf("|  修改密码输入“5”               |\n");
    printf("|                                |\n");
    printf("|  退出系统输入其他              |\n");
    printf("====================================\n");
    printf("你的输入：");
    scanf("%d",sc);
}

void Adminface(int *sc,char *id) //管理员界面
{
    printf("====================================\n");
    printf("|  欢迎用户：%s登录彩票系统！      |\n",id);
    printf("|                                |\n");
    printf("|  请选择你需要的功能！          |\n");
    printf("|                                |\n");
    printf("|  彩票开奖输入“1”               |\n");
    printf("|                                |\n");
    printf("|  查询信息输入“2”               |\n");
    printf("|                                |\n");
    printf("|  修改信息输入“3”               |\n");
    printf("|                                |\n");
    printf("|  删除信息输入“4”               |\n");
    printf("|                                |\n");
    printf("|  退出系统输入其他              |\n");
    printf("====================================\n");
    printf("你的输入：");
    scanf("%d",sc);
}

void Superface(int *sc) //超管界面
{
    printf("============================\n");
    printf("|  欢迎超管登录彩票系统！   |\n");
    printf("|                          |\n");
    printf("|  请选择你需要的功能！    |\n");
    printf("|                          |\n");
    printf("|  录入新管理输入“1”       |\n");
    printf("|                          |\n");
    printf("|  退出系统输入其他        |\n");
    printf("============================\n");
    printf("你的输入：");
    scanf(" %d",sc);
}
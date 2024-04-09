#include "head.h"

void adminQuery(int *sc) // 管理员查询
{
    *sc = 0;
    while (*sc != 8)
    {
        *sc = 0;
        printf("====================================\n");
        printf("|  欢迎使用查询功能！            |\n");
        printf("|                                |\n");
        printf("|  请选择你需要的功能！          |\n");
        printf("|                                |\n");
        printf("|  条件查询用户信息输入“1”       |\n");
        printf("|                                |\n");
        printf("|  条件查询购票历史输入“2”       |\n");
        printf("|                                |\n");
        printf("|  条件查询历史开奖输入“3”       |\n");
        printf("|                                |\n");
        printf("|  查询所有用户信息输入“4”       |\n");
        printf("|                                |\n");
        printf("|  查询所有历史购票输入“5”       |\n");
        printf("|                                |\n");
        printf("|  查询所有历史中奖输入“6”       |\n");
        printf("|                                |\n");
        printf("|  查询彩票中心营收输入“7”       |\n");
        printf("|                                |\n");
        printf("|  退出系统输入其他              |\n");
        printf("====================================\n");
        printf("你的输入：");
        scanf(" %d", sc);
        switch (*sc)
        {
        case 1:
            conditionQueryuser();
            break;
        case 2:
            conditionQuerybuy();
            break;
        case 3:
            conditionQuerywin();
            break;
        case 4:
            allQueryuser();
            break;
        case 5:
            allnQueryubuy();
            break;
        case 6:
            allQuerywin();
            break;
        case 7:
            Querymoney();
            break;
        default:
            *sc = 8;
            break;
        }
    }
}

void userQuery(int *sc, char *id) // 用户查询
{
    *sc = 0;
    while (*sc != 6)
    {
        *sc = 0;
        printf("====================================\n");
        printf("|  欢迎使用查询功能！            |\n");
        printf("|                                |\n");
        printf("|  请选择你需要的功能！          |\n");
        printf("|                                |\n");
        printf("|  查询自己的信息输入“1”         |\n");
        printf("|                                |\n");
        printf("|  查询自己历史购票输入“2”       |\n");
        printf("|                                |\n");
        printf("|  查询自己历史中奖输入“3”       |\n");
        printf("|                                |\n");
        printf("|  退出系统输入其他              |\n");
        printf("====================================\n");
        printf("你的输入：");
        scanf(" %d", sc);
        switch (*sc)
        {
        case 1:
            Showuser(id);
            break;
        case 2:
            conditionQueryuserbuy(id);
            break;
        case 3:
            userQuerywin(id);
            break;
        default:
            *sc = 6;
            break;
        }
    }
}

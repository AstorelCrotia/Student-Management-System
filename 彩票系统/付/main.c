#include "head.h"
#include <time.h>

int main()
{
    len = 0;      // 用户ID
    len_buy = 0;  // 购票信息个数,用户排序
    len_user = 0; // 用户个数

    //----------用户注册文件是否存在--------
    struct person *p = NULL, *H = NULL;
    FILE *fp;
    H = person_creat_head(H);
    if ((fp = fopen("user.txt", "rt")) == NULL) // 文件不存在
    {
        p = H;
    }
    else
    {
        fclose(fp);         // 放在读之前
        p = r_user_file(H); // 文件存在先读取内容
    }

    //---------以下购买彩票信息文件是否存在------
    struct buy_ticket *buy_H = NULL, *buy_p = NULL;
    buy_H = buy_creat_head(buy_H);
    buy_p = buy_H;
    if ((fp = fopen("buy.txt", "rt")) == NULL) // 文件不存在
    {
        buy_p = buy_H;
    }
    else
    {
        fclose(fp);
        buy_p = r_buy_file(buy_H); // 文件存在先读取内容
    }
    /*----------以上购买彩票信息----------------*/

    /*----------以下存放访客个数-----------------*/
    int visit;
    if ((fp = fopen("buy.txt", "rt")) == NULL) // 文件不存在
    {
        visit = 0;
    }
    else
    {
        fclose(fp);
        visit = r_visit_file(); // 文件存在先读取内容
    }
    visit++; // 访客数量加1
    w_visit_file(visit);
    /*------------以上存放访客个数-------------*/

    menu_build(); // 欢迎界面
    printf("****您是第 %d 位访客！****\n", visit);
    /*------下-延时函数-------------*/
    time_t start, end; // 定义时间开始与结束
    double dif;
    time(&start);
    while (dif < 5) // 时间小于5s一直在循环
    {
        time(&end);
        dif = difftime(end, start);
    }
    /*------上-延时函数-------------*/
    //	getchar();
    while (1)
    {
        ticketdayth = buy_H->ticket_dayth; // 头节点的dayth保存期号，彩民可以购买的期号
        main_menu();
        scanf("%d", &menu_select);
        getchar(); // 防止输入字符时进入死循环
        switch (menu_select)
        {
        case 0: // 需提示保存
            if (save_flag == 1)
            {
                printf("信息更改，是否保存到文件！y/n\n");
                if (getchar() == 'y')
                {
                    w_user_file(H); // 用户信息写入文件
                }
            }
            w_buy_file(buy_H); // 购票信息写入文件
            thanks();          // 退出感谢子菜单
            exit(0);
            break;
        case 1: // 管理员登录
            admin_menu1(H, buy_H);
            break;
        case 2:                                    // 彩民登录
            buy_p = person_menu2(H, buy_p, buy_H); // 把购票最后一个节点的地址返回到此
            break;
        case 3: // 用户注册
            p = add_user(H, p);
            break;
        case 4:
            printf("退出系统...\n");
            thanks();
            break;
        default:
            printf("\n 选择有误！任意键返回菜单！\n");
            getchar();
            break;
        }
        menu_select = 9; // 跳入输入有误，如果用户没输数字，会进入default
    }
    return 0;
}

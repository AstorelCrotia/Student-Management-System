#include "head.h"
#include <time.h>

void admin_signin(struct Person *p, struct buy_ticket *buy_p)
{
    char name_now[20];
    char passwd_now1[20];
    char passwd_now2[20];
    int i = 0;

    while (1)
    {
        printf("请输入用户名：");
        scanf("%s", name_now);
        printf("\n");
        printf("请输入密码：");
        scanf("%s", passwd_now2);
        printf("\n");
        strcpy(passwd_now1, passwd_now2);
        if (strcmp(p->name, name_now) != 0 || strcmp(p->password, passwd_now1) != 0)
        {
            i++;
            if (i >= 3)
            {
                printf("密码错误次数三次！任意键返回主菜单");
                getchar();
                getchar();
                break;
            }
            printf("用户名输入错误！请重新输入：\n");
        }
        else
        {
            i = 0;
            break;
        }
    }
    if (i == 0) // 信息正确
    {
        while (choice)
        {
            printf("管理员你好！\n");
            printf("1、摇号\t\t2、查看信息\t\t3、修改信息\t\t4、删除信息\t\t5、购票信息排序\t\t0、返回主菜单");
            printf("你希望进行的操作为：");
            scanf("%d", &choice);
            getchar();
            printf("\n");
            switch (choice)
            {
            case 0: // 返回主菜单
                break;
            case 1: // 摇号
                Game(p, buy_p);
                break;
            case 2:
                admin_view(p, buy_p);
                break;
            case 3:
                admin_update(p);
                break;
            case 4:
                admin_delete(p, buy_p);
                break;
            case 5:
                admin_sort(p, buy_p);
                break;
            default:
                printf("选择无效！任意键返回菜单！");
                getchar();
                choice = 0;
                break;
            }
        }
    }
}

void Game(struct Person *p, struct buy_ticket *buy_p)
{
    struct news prize;
    int flag = 0; // 中奖信号
    struct buy_ticket *temp = buy_p;
    int x = 0, y = 0, z = 0; // 三种类型的彩票
    printf("确认开始摇号(y/n)?", buy_p->ticket_dayth);
    if (getchar() == 'y')
    {
        srand((unsigned)time(NULL));
        x = rand() % 20 + 1; // 鼠彩
        y = rand() % 20 + 1; // 猫彩
        z = rand() % 20 + 1; // 狗彩
        buy_p->mouse_ID = x;
        buy_p->cat_ID = y;
        buy_p->dog_ID = z;
        buy_p->ticket_sum = 0;
        printf("号码抽取中...\n");
        time_t start, end;
        double dif;
        time(&start);
        while (dif < 5)
        {
            time(&end);
            dif = difftime(end, start);
        }
        struct tm *tm_ptr;
        time_t the_time;
        (void)time(&the_time);
        tm_ptr = localtime(&the_time);

        // 公布中奖信息
        printf("\n第%d期的中奖号码是：\n", buy_p->ticket_dayth);
        printf("鼠鼠彩票：%d\n", x);
        printf("猫猫彩票：%d\n", y);
        printf("狗狗彩票：%d\n", z);
        printf("抽奖时间：%02d年%02d月%02d日 %02d-%02d-%02d\n", tm_ptr->tm_year - 100, tm_ptr->tm_mon + 1, tm_ptr->tm_mday, tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);
        printf("\n");
        printf("中奖人信息为：\n");
        printf("ID\t姓名\t期号\t  类型\t\t号码\t数量\t开奖状态  中奖情况  中奖金额 \n");

        while (temp->next != NULL)
        {
            if (temp->next->ticket_dayth == buy_p->ticket_dayth) // 购买当期判断奖池减少，记录彩民
            {
                temp->next->ticket_status = 0;
                switch (temp->next->ticket_type)
                {
                case mouse_ticket:
                    if (temp->next->ticket_number == x)
                    {
                        temp->next->ticket_win = 1;
                        temp->next->ticket_number = x;
                        temp->next->ticket_winmoney = temp->next->ticket_amount * mouse_win;
                        buy_p->ticket_sum += temp->next->ticket_winmoney;
                        add_winmoney(p, temp->next->person_id, temp->next->ticket_amount * mouse_win);
                    }
                    break;
                case cat_ticket:
                    if (temp->next->ticket_number == y)
                    {
                        temp->next->ticket_win = 1;
                        temp->next->ticket_number = y;
                        temp->next->ticket_winmoney = temp->next->ticket_amount * cat_win;
                        buy_p->ticket_sum += temp->next->ticket_winmoney;
                        add_winmoney(p, temp->next->person_id, temp->next->ticket_amount * cat_win);
                    }
                    break;
                case dog_ticket:
                    if (temp->next->ticket_number == z)
                    {
                        temp->next->ticket_win = 1;
                        temp->next->ticket_number = z;
                        temp->next->ticket_winmoney = temp->next->ticket_amount * dog_win;
                        buy_p->ticket_sum += temp->next->ticket_winmoney;
                        add_winmoney(p, temp->next->person_id, temp->next->ticket_amount * dog_win);
                    }
                    break;
                default:
                    break;
                }

                if (temp->next->ticket_win)
                {
                    flag = 1;
                    printf("%d\t%s\t%d", temp->next->person_id, temp->next->person_name, temp->next->ticket_dayth);
                    if (temp->next->ticket_type == mouse_ticket)
                        printf("\t鼠鼠彩票");
                    else if (temp->next->ticket_type == cat_ticket)
                        printf("\t猫猫彩票");
                    else
                        printf("\t狗狗彩票");
                    printf("\t%d\t%d", temp->next->ticket_number, temp->next->ticket_amount);
                    if (temp->next->ticket_status)
                        printf("\t未开奖");
                    else
                        printf("\t已开奖");
                    if (temp->next->ticket_win)
                        printf("    中  奖");
                    else
                        printf("    未中奖");
                    printf("\t%d\n", temp->next->ticket_winmoney);
                    winer_file(temp->next);
                }
            }
            temp = temp->next;
        }
        if (!flag)
            printf("本期没有人中奖！\n");
        p->balance -= buy_p->ticket_sum;
        printf("奖池金额为:%d元\n", p->balance);
        prize.dayth = buy_p->ticket_dayth;
        prize.mouse_ticket = x;
        prize.cat_ticket = y;
        prize.dog_ticket = z;
        prize.sum = buy_p->ticket_sum;
        prize.year = tm_ptr->tm_year - 100;
        prize.month = tm_ptr->tm_mon + 1;
        prize.day = tm_ptr->tm_mday;
        prize.hour = tm_ptr->tm_hour;
        prize.min = tm_ptr->tm_min;
        prize.sec = tm_ptr->tm_sec;
        w_wininformation_file(prize); // 保存中奖信息
        buy_p->ticket_dayth++;

        printf("任意键返回...");
        getchar();
        getchar();
    }
}

void add_winmoney(struct Person *p, int id, int money)
{
    while (p->next != NULL)
    {
        if (p->next->id == id)
        {
            p->next->balance += money;
            break;
        }
        p = p->next;
    }
}

void admin_view(struct Person *p, struct buy_ticket *buy_p)
{
    while (choice != 0)
    {
        printf("1、管理员信息\t\t2、历史中奖信息\t\t3、历史中奖人信息\t\t4、彩民基本信息\t\t5、所有购票信息\n6、按ID查找\t\t7、按期号查找\t\t0、返回上一级\n");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 0:
            break;
        case 1:
            printf("ID：%d\t姓名：%s\t密码：%s\t余额：%d元\n", p->id, p->name, p->password, p->balance);
            printf("任意键退出...");
            getchar();
            break;
        case 2:
            r_wininformation_file();
            printf("任意键返回...");
            getchar();
            break;
        case 3:
            r_winner_file();
            printf("任意键返回...");
            getchar();
            break;
        case 4:
            user_information(p);
            break;
        case 5:
            view_allbuy_news(buy_p);
            break;
        case 6:
            ID_check_buynews(buy_p);
            break;
        case 7:
            dayth_check_buynews(buy_p);
            break;
        default:
            choice = 0;
            printf("选择有误！任意键返回...");
            getchar();
            break;
        }
        if(choice==0)
        {
            choice=1;
            break;
        }
    }
}

void user_information(struct Person *p)
{
    while (p->next != NULL)
    {
        printf("ID；%d\t姓名：%s\t密码：%s\t金额：%d元\n", p->next->id, p->next->name, p->next->password, p->next->balance);
        p = p->next;
    }
    printf("任意键返回...");
    getchar();
}

void view_allbuy_news(struct buy_ticket *buy_p)
{
    printf("所有购票信息\n");
    while (buy_p->next != NULL)
    {
        printf("ID：%d\t姓名：%s\t期号：%d\t\t类型：%s\t号码：%d数量：%d\t", buy_p->next->person_id, buy_p->next->person_name, buy_p->next->ticket_dayth, buy_p->next->ticket_type, buy_p->next->ticket_number, buy_p->next->ticket_amount);
        if (buy_p->next->ticket_status)
            printf("开奖状态：未开奖\t");
        else
            printf("开奖状态：已开奖\t");
        if (buy_p->next->ticket_win)
            printf("中奖状态：已中奖\t");
        else
            printf("中奖状态：未中奖\t");
        printf("%d\n", buy_p->next->ticket_sum);
        buy_p = buy_p->next;
    }
    printf("任意键返回...");
    getchar();
}

void ID_check_buynews(struct buy_ticket *buy_p)
{
    int id;
    printf("请输入查找用户的ID：");
    scanf("%d", &id);
    while (buy_p->next != NULL)
    {
        if (buy_p->next->person_id == id)
        {
            printf("查找的购票信息为:\t\tID：%d\t姓名：%s\t期号：%d\t类型：%s\t号码：%d\t数量：%d\t", buy_p->next->person_id, buy_p->next->person_name, buy_p->next->ticket_dayth, buy_p->next->ticket_type, buy_p->next->ticket_number, buy_p->next->ticket_amount);
            if (buy_p->next->ticket_status)
                printf("开奖状态：未开奖\t");
            else
                printf("开奖状态：已开奖\t");
            if (buy_p->next->ticket_win)
                printf("中奖状态：已中奖\t");
            else
                printf("中奖状态：未中奖\t");
            printf("%d\n", buy_p->next->ticket_sum);
        }
        buy_p = buy_p->next;
    }
    printf("任意键返回...");
    getchar();
    getchar();
}

void dayth_check_buynews(struct buy_ticket *buy_p)
{
    int dayth;
    printf("请输入查找的期号：");
    scanf("%d", &dayth);
    while (buy_p->next != NULL)
    {
        if (buy_p->next->ticket_dayth == dayth)
        {
            printf("查找的购票信息为:\t\tID：%d\t姓名：%s\t期号：%d\t类型：%s\t号码：%d\t数量：%d\t", buy_p->next->person_id, buy_p->next->person_name, buy_p->next->ticket_dayth, buy_p->next->ticket_type, buy_p->next->ticket_number, buy_p->next->ticket_amount);
            if (buy_p->next->ticket_status)
                printf("开奖状态：未开奖\t");
            else
                printf("开奖状态：已开奖\t");
            if (buy_p->next->ticket_win)
                printf("中奖状态：已中奖\t");
            else
                printf("中奖状态：未中奖\t");
            printf("%d\n", buy_p->next->ticket_sum);
        }
        buy_p = buy_p->next;
    }
    printf("任意键返回...");
    getchar();
    getchar();
}
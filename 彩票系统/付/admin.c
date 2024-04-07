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
        printf("请输入密码：");
        mask_signin_password(passwd_now2);
        Signin_vertification(vertification, CODE_LENGTH);
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
            printf("**********************************\n");
            printf("管理员你好！\n");
            printf("你可供选择的操作有:\n");
            printf("1、摇号\t\t2、查看信息\t3、修改信息\t4、删除信息\t5、购票信息排序\t0、返回主菜单\n");
            printf("你希望进行的操作为：");
            scanf("%d", &choice);
            getchar();
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
                admin_updata(p);
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
    printf("确认开始摇号(y/n)?");
    if (getchar() == 'y')
    {
        srand((unsigned)time(NULL));
        x = rand() % ticket_max + 1; // 鼠彩
        y = rand() % ticket_max + 1; // 猫彩
        z = rand() % ticket_max + 1; // 狗彩
        buy_p->person_id = x;
        buy_p->ticket_number = y;
        buy_p->ticket_amount = z;
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
        printf("\n第%d期的中奖号码是:\n", buy_p->ticket_dayth);
        printf("鼠鼠彩票：%d\n", x);
        printf("猫猫彩票：%d\n", y);
        printf("狗狗彩票：%d\n", z);
        printf("抽奖时间：%02d年%02d月%02d日 %02d-%02d-%02d\n", tm_ptr->tm_year - 100, tm_ptr->tm_mon + 1, tm_ptr->tm_mday, tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);
        printf("中奖人信息为：\n");
        printf("ID\t姓名\t期号\t  类型\t号码\t数量\t开奖状态  中奖情况  中奖金额 \n");

        while (temp->next != NULL)
        {
            if (temp->next->ticket_dayth == buy_p->ticket_dayth)
            {
                temp->next->ticket_status = 0;
                switch (temp->next->ticket_type)
                {
                case mouse_ticket:
                    if (temp->next->ticket_number == x)
                    {
                        temp->next->ticket_win = 1;                                                  
                        temp->next->ticket_winmoney = temp->next->ticket_amount * mouse_win;           
                        buy_p->ticket_sum += temp->next->ticket_winmoney;                             
                        add_winmoney(p, temp->next->person_id, temp->next->ticket_amount * mouse_win); 
                    }
                    break;
                case cat_ticket:
                    if (temp->next->ticket_number == y)
                    {
                        temp->next->ticket_win = 1;                                        
                        temp->next->ticket_winmoney = temp->next->ticket_amount * cat_win; 
                        buy_p->ticket_sum += temp->next->ticket_winmoney;
                        add_winmoney(p, temp->next->person_id, temp->next->ticket_amount * cat_win); 
                    }
                    break;
                case dog_ticket:
                    if (temp->next->ticket_number == z)
                    {
                        temp->next->ticket_win = 1;
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
                    printf("%d\t%s\t%d",
                           temp->next->person_id,
                           temp->next->person_name,
                           temp->next->ticket_dayth);
                    if (temp->next->ticket_type == mouse_ticket)
                        printf("\t鼠鼠彩票");
                    else if (temp->next->ticket_type == cat_ticket)
                        printf("\t猫猫彩票");
                    else
                        printf("\t狗狗彩票");
                    printf("\t%d\t%d",
                           temp->next->ticket_number,
                           temp->next->ticket_amount);
                    if (temp->next->ticket_status)
                        printf("\t未开奖");
                    else
                        printf("\t已开奖");
                    if (temp->next->ticket_win)
                        printf("    中  奖");
                    else
                        printf("    未中奖");
                    printf("\t%d\n", temp->next->ticket_winmoney);
                    w_winer_file(temp->next);
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
        w_wininformation_file(prize); 
        buy_p->ticket_dayth++;
        save_flag = 1;
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
            printf("ID:%d\t姓名:%s\t密码:%s\t余额:%d元\n", p->id, p->name, p->password, p->balance);
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
        if (choice == 0)
        {
            choice = 1;
            break;
        }
    }
}

void user_information(struct Person *p)
{
    while (p->next != NULL)
    {
        printf("ID:%d\t姓名:%s\t密码:%s\t金额:%d元\n", p->next->id, p->next->name, p->next->password, p->next->balance);
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
        printf("ID:%d\t姓名:%s\t期号:%d\t号码:%d数量:%d\t", buy_p->next->person_id, buy_p->next->person_name, buy_p->next->ticket_dayth, buy_p->next->ticket_number, buy_p->next->ticket_amount);
        if (buy_p->next->ticket_type == mouse_ticket)
            printf("\t类型:鼠鼠彩票");
        else if (buy_p->next->ticket_type == cat_ticket)
            printf("\t类型:猫猫彩票");
        else
            printf("\t类型:狗狗彩票");
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
    printf("请输入查找用户的ID:");
    scanf("%d", &id);
    while (buy_p->next != NULL)
    {
        if (buy_p->next->person_id == id)
        {
            printf("ID:%d\t姓名:%s\t期号:%d\t号码:%d数量:%d\t", buy_p->next->person_id, buy_p->next->person_name, buy_p->next->ticket_dayth, buy_p->next->ticket_number, buy_p->next->ticket_amount);
            if (buy_p->next->ticket_type == mouse_ticket)
            {
                printf("\t类型:鼠鼠彩票");
            }
            else if (buy_p->next->ticket_type == cat_ticket)
            {
                printf("\t类型:猫猫彩票");
            }
            else
            {
                printf("\t类型:狗狗彩票");
            }
            if (buy_p->next->ticket_status)
            {
                printf("开奖状态：未开奖\t");
            }
            else
            {
                printf("开奖状态：已开奖\t");
            }
            if (buy_p->next->ticket_win)
            {
                printf("中奖状态：已中奖\t");
            }
            else
            {
                printf("中奖状态：未中奖\t");
            }
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
            printf("ID:%d\t姓名:%s\t期号:%d\t号码:%d数量:%d\t", buy_p->next->person_id, buy_p->next->person_name, buy_p->next->ticket_dayth, buy_p->next->ticket_number, buy_p->next->ticket_amount);
            if (buy_p->next->ticket_type == mouse_ticket)
                printf("\t类型:鼠鼠彩票");
            else if (buy_p->next->ticket_type == cat_ticket)
                printf("\t类型:猫猫彩票");
            else
                printf("\t类型:狗狗彩票");
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

void admin_updata(struct Person *p)
{
    struct Person *q;
    while (choice != 0)
    {
        printf("1、修改管理员信息\t2、修改彩民密码\t3、追加金额\t0、返回上一级\n");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 0:
            break;
        case 1:
            adminself_updata(p);
            break;
        case 2:
            q = admin_user(p);
            if (q != NULL)
            {
                q = q->next;
                admin_change(q);
            }
            else
            {
                printf("未找到该信息！任意键返回...");
                getchar();
            }
            break;
        case 3:
            q = admin_user(p);
            q = q->next;
            admin_add_money(q);
            break;
        default:
            choice = 0;
            printf("选择无效！任意键返回...");
            getchar();
            break;
        }
        if (choice == 0)
        {
            choice = 1;
            break;
        }
    }
}

void adminself_updata(struct Person *p)
{
    char password1[20];
    char password2[20];
    char admin_password[20];
    char name[20];
    int i = 0;

    while (choice != 0)
    {
        printf("1、修改姓名\t2、修改密码\t3、修改奖池金额\t0、返回上一级\n");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 0:
            break;
        case 1:
            printf("请输入新用户名：");
            scanf("%s", name);
            getchar();
            printf("请确认修改用户名：(y/n)");
            if (getchar() == 'y')
            {
                save_flag = 1;
                strcpy(p->name, name);
                printf("修改成功！任意键返回...");
                getchar();
                getchar();
            }
            else
            {
                printf("无效输入！任意键返回...");
                getchar();
            }
            break;
        case 2:
            printf("请输入旧密码：");
            mask_signin_password(admin_password);
            if (strcmp(admin_password, p->password) == 0)
            {
                while (1)
                {
                    if (i > 2)
                    {
                        printf("错误次数过多！任意键返回...");
                        getchar();
                        getchar();
                        break;
                    }
                    printf("请输入新密码：");
                    mask_password(password1);
                    printf("请再次输入密码：");
                    mask_signin_password(password2);
                    if (strcmp(password1, password2) == 0)
                    {
                        save_flag = 1;
                        strcpy(p->password, password2);
                        printf("密码已更新！任意键返回...");
                        getchar();
                        break;
                    }
                    else
                    {
                        i++;
                        printf("两次密码不一致！请重新输入！\n");
                    }
                }
            }
            else
            {
                printf("密码错误！任意键返回...");
                getchar();
            }
            break;
        case 3:
            admin_add_money(p);
            break;
        default:
            choice = 0;
            printf("选择无效！任意键返回...");
            getchar();
            break;
        }
        if (choice == 0)
        {
            choice = 3;
            break;
        }
    }
}

void admin_add_money(struct Person *p)
{
    int money;
    printf("余额为：");
    printf("%d 元\n", p->balance);
    printf("请输入追加奖池金额：");
    scanf("%d", &money);
    getchar();
    printf("确认追加奖池:(y/n)");
    if (getchar() == 'y')
    {
        save_flag = 1;
        p->balance += money;
        printf("追加后的金额为：");
        printf("%d 元\t任意键返回...\n", p->balance);
        getchar();
    }
    else
    {
        printf("追加失败！");
    }
}

struct Person *admin_user(struct Person *p)
{
    int id = 0;
    char name[20];
    while (choice != 0)
    {
        printf("请输入要查找的是:\n1、姓名\t2、ID\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            choice = 0;
            break;
        case 1:
            printf("您要查找的姓名为:");
            scanf("%s", name);
            while (p->next != NULL)
            {
                if (strcmp(p->next->name, name) == 0)
                {
                    return p;
                }
                p = p->next;
            }
            break;
        case 2:
            printf("您要查找的ID为:");
            scanf("%d", &id);
            while (p->next != NULL)
            {
                if (p->next->id == id)
                {
                    return p;
                }
                p = p->next;
            }
            break;
        default:
            printf("无效输入，任意键返回...");
            getchar();
            break;
        }
    }
    return NULL;
}

void admin_change(struct Person *p)
{
    char password1[20];
    char password2[20];
    int i = 0;
    printf("彩民信息为:ID:%d\t姓名:%s\t密码:%s\t金额:%d元\n", p->id, p->name, p->password, p->balance);
    while (1)
    {
        if (i > 2)
        {
            printf("错误次数过多！任意键返回...");
            getchar();
            getchar();
            break;
        }
        printf("请输入新密码：");
        mask_password(password1);
        printf("请再次输入密码：");
        mask_signin_password(password2);
        if (strcmp(password1, password2) == 0)
        {
            save_flag = 1;
            strcpy(p->password, password2);
            printf("密码已更新！任意键返回...");
            getchar();
            getchar();
            break;
        }
        else
        {
            i++;
            printf("两次密码不一致！请重新输入！\n");
        }
    }
}

void admin_delete(struct Person *p, struct buy_ticket *buy_p)
{
    struct Person *q = NULL;
    struct Person *temp = NULL;
    while (choice != 0)
    {
        printf("**********************************\n");
        printf("1、删除用户\t2、根据ID删除购票信息\t3、根据类型删除购票信息\t4、根据期号删除购票信息\t0、返回上一级\n");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 0:
            break;
        case 1:
            q = admin_user(p);
            if (q != NULL)
            {
                printf("彩民的基本信息为:ID:%d\t姓名:%s\t密码:%s\t金额:%d元\n", q->next->id, q->next->name, q->next->password, q->next->balance);
                printf("确认删除(y/n)?\n");
                getchar();
                if (getchar() == 'y')
                {
                    len_buy--;
                    save_flag = 1;
                    temp = q->next;
                    q->next = temp->next;
                    printf("删除成功！任意键返回...\n");
                    free(temp);
                    getchar();
                    getchar();
                }
                else
                {
                    printf("取消操作！任意键返回...");
                    getchar();
                    getchar();
                }
            }
            else
            {
                printf("所查询的用户不存在！\n");
                getchar();
            }
            break;
        case 2:
            id_del_buynews(buy_p);
        case 3:
            type_del_buynews(buy_p);
        case 4:
            dayth_del_buynews(buy_p);
            break;
        default:
            choice = 0;
            printf("选择无效！任意键返回...");
            getchar();
            break;
        }
        if (choice == 0)
        {
            choice = 1;
            break;
        }
    }
}

void id_del_buynews(struct buy_ticket *buy_p)
{
    int id;
    struct buy_ticket *temp = NULL;
    printf("请输入需要删除信息的ID:");
    scanf("%d", &id);
    getchar();
    printf("确定删除信息(y/n)");
    if (getchar() == 'y')
    {
        while (buy_p->next != NULL)
        {
            if (buy_p->next->person_id == id && buy_p->next->ticket_status == 0)
            {
                temp = buy_p->next;
                buy_p->next = buy_p->next->next;
                printf("删除成功，结点已销毁！\n");
                free(temp);
                len_buy--;
            }
            else
                buy_p = buy_p->next;
        }
        printf("未开奖的彩票无法删除！任意键返回...");
        getchar();
        getchar();
    }
    else
    {
        printf("操作取消！任意键返回...");
        getchar();
        getchar();
    }
}

void type_del_buynews(struct buy_ticket *buy_p)
{
    int type;
    struct buy_ticket *temp = NULL;
    printf("选择需要删除信息的彩票类型(1、鼠鼠彩票 2、猫猫彩票  3、狗狗彩票):");
    scanf("%d", &type);
    getchar();
    printf("请确认信息(y/n):");
    if (getchar() == 'y')
    {
        while (buy_p->next != NULL)
        {
            if (buy_p->next->ticket_type == type && buy_p->next->ticket_status == 0)
            {
                temp = buy_p->next;
                buy_p->next = buy_p->next->next;
                printf("删除成功！结点已销毁！\n");
                free(temp);
                len_buy--;
            }
            else
                buy_p = buy_p->next;
        }
        printf("未开奖的彩票无法删除！任意键返回...");
        getchar();
        getchar();
    }
    else
    {
        printf("已取消操作！任意键返回...");
        getchar();
        getchar();
    }
}

void dayth_del_buynews(struct buy_ticket *buy_p)
{
    int dayth;
    struct buy_ticket *temp = NULL;
    printf("请输入需要删除信息的期号：");
    scanf("%d", &dayth);
    getchar();
    printf("请确认删除信息：(y/n)");
    if (getchar() == 'y')
    {
        while (buy_p->next != NULL)
        {
            if (buy_p->next->ticket_dayth == dayth && buy_p->next->ticket_status == 0)
            {
                temp = buy_p->next;
                buy_p->next = buy_p->next->next;
                printf("删除成功！节点已销毁！");
                free(temp);
                len_buy--;
            }
            else
                buy_p = buy_p->next;
        }
        printf("未开奖的彩票无法删除！任意键返回...");
        getchar();
        getchar();
    }
    else
    {
        printf("放弃操作！任意键返回...");
        getchar();
        getchar();
    }
}

void admin_sort(struct Person *p, struct buy_ticket *buy_p)
{
    while (choice != 0)
    {
        printf("1、按账号余额排序\t\t2、按期号排序\t\t3、按购票总数排序\t\t0、返回上一级\n");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 0:
            break;
        case 1:
            sortfun(p, buy_p);
            break;
        case 2:
            sortfun(p, buy_p);
            break;
        case 3:
            sortfun(p, buy_p);
            break;
        default:
            choice = 0;
            printf("选择无效！任意键返回...");
            getchar();
            break;
        }
        if (choice == 0)
        {
            choice = 1;
            break;
        }
    }
}

void sortfun(struct Person *H, struct buy_ticket *buy_H)
{
    int i, j;
    struct Person *p = H;
    struct Person *temp = NULL;
    struct buy_ticket *buy_p = buy_H;
    struct buy_ticket *buy_temp = NULL;
    if (choice == 1)
    {
        for (i = len_user - 2; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (p->next->balance < p->next->next->balance)
                {
                    temp = p->next;
                    p->next = temp->next;
                    temp->next = p->next->next;
                    p->next->next = temp;
                }
                p = p->next;
            }
            p = H;
        }
        printf("排序后的信息为：\n");
        user_information(H);
    }
    else if (choice == 2)
    {
        for (i = len_buy - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (buy_p->next->ticket_dayth > buy_p->next->next->ticket_dayth)
                {
                    buy_temp = buy_p->next;
                    buy_p->next = buy_temp->next;
                    buy_temp->next = buy_p->next->next;
                    buy_p->next->next = buy_temp;
                }
                buy_p = buy_p->next;
            }
            buy_p = buy_H;
        }
        printf("排序后的购票信息为：\n");
        view_allbuy_news(buy_H);
    }
    else
    {
        for (i = len_buy - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (buy_p->next->ticket_amount < buy_p->next->next->ticket_amount)
                {
                    buy_temp = buy_p->next;
                    buy_p->next = buy_temp->next;
                    buy_temp->next = buy_p->next->next;
                    buy_p->next->next = buy_temp;
                }
                buy_p = buy_p->next;
            }
            buy_p = buy_H;
        }
        printf("\t排序后购票信息为:\n");
        view_allbuy_news(buy_H);
    }
}

void mask_password(char *password)
{  
    do
    {
        int m = 0;
        int length = 0;
        int hasDigit = 0;
        int hasLetter = 0;
        while (1)
        {
            ch = _getch();
            if (ch == 13)
            {
                break;
            }
            else if (ch == 8)
            {
                if (m > 0)
                {
                    printf("\b \b");
                    m--;
                }
            }
            else if (isprint(ch))
            {
                password[m++] = ch;
                printf("*");
            }
        }
        password[m] = '\0';
        printf("\n");
        length = strlen(password);
        if (length < 8 || length >12)
        {
            printf("密码必须在8-12位!\n");
        }
        else
        {
            for (m = 0; m < length; m++)
            {
                if (isdigit(password[m]))
                {
                    hasDigit = 1;
                }
                else if (isalpha(password[m]))
                {
                    hasLetter = 1;
                }
            }
            if (!hasDigit || !hasLetter)
            {
                printf("必须同时包含数字和字母！\n");
            }
            else
            {
                break;
            }
        }
    } while (1);
}

void mask_signin_password(char *password)
{  
        int m = 0;
        while (1)
        {
            ch = _getch();
            if (ch == 13)
            {
                break;
            }
            else if (ch == 8)
            {
                if (m > 0)
                {
                    printf("\b \b");
                    m--;
                }
            }
            else if (isprint(ch))
            {
                password[m++] = ch;
                printf("*");
            }
        }
        password[m] = '\0';
        printf("\n");
}
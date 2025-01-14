#include "head.h"
#include <time.h>
// 新用户注册;
struct Person *signup(struct Person *p, struct Person *q)
{
    char passwd1[20];
    char passwd2[20];
    char name[20];
    int i = 0;
    int flag = 1;
    struct Person *newuser = NULL;

    while (1)
    {
        printf("请输入用户名:");
        scanf("%s", name);
        flag = check_user(name, p);

        if (flag == 0)
        {
            i = 0;
            break;
        }
        else
        {
            printf("用户名已存在！\n");
            i++;
            if (i == 3)
            {
                printf("错误输入三次，任意键返回主菜单！\n");
                getchar();
                getchar();
                break;
            }
        }
    }

    if (!flag)
    {
        while (1)
        {
            printf("请输入密码：");
            mask_password(passwd1);
            printf("再次输入确认密码:");
            mask_password(passwd2);
            i++;

            if (i == 3)
            {
                printf("输入超过三次！任意键返回...\n");
                getchar();
                getchar();
                break;
            }

            if (strcmp(passwd1, passwd2) == 0)
            {
                break;
            }
            else
                printf("密码输入不一致，请重新输入！\n");
        }

        if (i != 3)
        {
            len++;
            len_user++;
            save_flag = 1;
            newuser = (struct Person *)malloc(sizeof(struct Person));

            if (newuser == NULL)
            {
                printf("分配空间错误！\n");
                exit(0);
            }

            newuser->next = NULL;
            newuser->id = len;
            strcpy(newuser->password, passwd1);
            strcpy(newuser->name, name);
            newuser->balance = user_init_money;
            printf("注册成功！任意键返回...");
            getchar();
            getchar();
            q->next = newuser;
            q = newuser;
        }
    }
    return q;
}

struct buy_ticket *signin(struct Person *p, struct buy_ticket *buy_p, struct buy_ticket *buy_q)
{
    char name[20];
    char password[20];
    struct Person *q = p;
    int i = 0;

    while (1)
    {
        printf("请输入用户名:");
        scanf("%s", name);
        printf("请输入密码:");
        mask_signin_password(password);
        Signin_vertification(vertification, CODE_LENGTH);
        while (q->next != NULL)
        {
            if (strcmp(q->next->name, name) == 0 && strcmp(q->next->password, password) == 0)
            {
                break;
            }
            q = q->next;
        }
        if (q->next == NULL)
        {
            i++;
            if (i >= 3)
            {
                printf("密码错误多次！任意键返回...\n");
                getchar();
                getchar();
                break;
            }
            printf("用户名或密码输入错误！请重新输入！\n");
        }
        else
        {
            i = 0;
            break;
        }
        q = p;
    }
    if (i == 0)
    {
        while (choice != 0)
        {
            printf("**********************************\n");
            printf("%s,您好!", name);
            printf("你可供选择的操作有:\n");
            printf("1、购票\t2、查看个人信息\t3、修改信息\t4、用户充值\t0、返回主菜单\n");
            printf("您的选择是:");
            scanf("%d", &choice);
            getchar();
            switch (choice)
            {
            case 0:
                choice = 0;
                return buy_p;
                break;
            case 1:
                buy_p = user_buy_ticket(buy_p, q->next, p);
                break;
            case 2:
                printf("您的个人信息为:ID:%d\t\t姓名:%s\t\t密码:%s\t\t余额:%d\n", q->next->id, q->next->name, q->next->password, q->next->balance);
                user_view_ticket(q->next, buy_q);
                printf("任意键继续...");
                getchar();
                break;
            case 3:
                user_update(q, q->next);
                break;
            case 4:
                user_recharge(q, name);
                break;
            default:
                printf("选择有误！任意键返回...\n");
                getchar();
                choice = 0;
                break;
            }
        }
    }
    return buy_q;
}

struct buy_ticket *user_buy_ticket(struct buy_ticket *p, struct Person *user, struct Person *q)
{
    struct buy_ticket *newticket = NULL;
    while (choice != 0)
    {
        newticket = (struct buy_ticket *)malloc(sizeof(struct buy_ticket));
        if (newticket == NULL)
        {
            printf("头节点分配空间失败！\n");
            exit(0);
        }
        newticket->next = NULL;

        printf("您的账户余额为：%d元\n", user->balance);
        if (user->balance < ticket_value)
        {
            printf("余额不足，请充值！按任意键退出！");
            getchar();
            return p;
        }
        while (1)
        {
            printf("请选择您要下注的类型:1、鼠鼠\t2、猫猫\t3、狗狗\t0、返回上一级\n");
            scanf("%d", &newticket->ticket_type);
            if (newticket->ticket_type < 0 || newticket->ticket_type > 3)
            {
                printf("没有您输入的类型！请重新输入！\n");
            }
            else
            {
                break;
            }
        }
        if (newticket->ticket_type == 0)
            return p;
        while (1)
        {
            printf("请输入您要购买的号码(1-20):");
            scanf("%d", &newticket->ticket_number);
            if (newticket->ticket_number < 1 || newticket->ticket_number > 20)
            {
                printf("您输入的号码不在范围内！请重新输入！\n");
            }
            else
            {
                break;
            }
        }
        printf("您要购买的数量：");
        scanf("%d", &newticket->ticket_amount);
        newticket->person_id = user->id;
        strcpy(newticket->person_name, user->name);
        newticket->ticket_dayth = ticketdayth;
        newticket->ticket_status = 1;
        newticket->ticket_win = 0;
        newticket->ticket_sum = newticket->ticket_amount * ticket_value;
        if (newticket->ticket_sum > user->balance)
        {
            printf("账户余额不足，请充值！任意键返回...");
            getchar();
            return p;
        }
        else
        {
            len_buy++;
            p->next = newticket;
            p = newticket;
            user->balance = user->balance - newticket->ticket_sum;
            q->balance += newticket->ticket_sum;
            printf("购票成功！\n");
            printf("您购买的是：%d\n", newticket->ticket_type);
            printf("彩票期号:%d 期\n", newticket->ticket_dayth);
            printf("彩票号码:%d \n", newticket->ticket_number);
            printf("彩票数量:%d 注\n", newticket->ticket_amount);
            printf("总金额:%d 元\n", newticket->ticket_sum);
            if (newticket->ticket_status == 1)
            {
                printf("未开奖\n");
            }
            else
            {
                if (!newticket->ticket_win)
                {
                    printf("未中奖，祝您下次好运！\n");
                }
                else
                {
                    printf("恭喜您中奖了，金额为:%d元\n", newticket->ticket_amount * ticket_win_money);
                }
            }
            save_flag = 1;
            printf("任意键返回...");
            getchar();
            getchar();
        }
    }
    return p;
}

void user_view_ticket(struct Person *p, struct buy_ticket *buy_p)
{
    struct buy_ticket *temp = buy_p;
    printf("上期中奖号码是：鼠鼠:%d\t猫猫:%d\t狗狗:%d\t下期彩票:%d\n", temp->person_id, temp->ticket_amount, temp->ticket_sum, temp->ticket_dayth);
    printf("您的购票信息为：\n");
    printf("ID\t姓名\t期号\t\t类型\t\t号码\t数量\t\t开奖状态\t中奖情况\t购票金额\t\n");
    while (temp->next != NULL)
    {
        if (temp->next->person_id == p->id)
        {
            printf("%d\t%s\t%d\t\t", temp->next->person_id, temp->next->person_name, temp->next->ticket_dayth);
            if (temp->next->ticket_type == mouse_ticket)
                printf("鼠鼠彩票\t");
            else if (temp->next->ticket_type == cat_ticket)
                printf("猫猫彩票\t");
            else
                printf("狗狗彩票\t");
            printf("%d\t%d\t\t", temp->next->ticket_number, temp->next->ticket_amount);
            if (temp->next->ticket_status)
                printf("未开奖\t\t");
            else
                printf("已开奖\t\t");
            if (temp->next->ticket_win)
                printf("已中奖\t\t");
            else
                printf("未中奖\t\t");
            printf("%d\n", temp->next->ticket_sum);
        }
        temp = temp->next;
    }
}

void user_update(struct Person *p, struct Person *q)
{
    char password1[20];
    char password2[20];
    char admin_password[20];
    char oldpass[20];
    char name[20];
    int i = 0, flag = 1;

    while (choice != 0)
    {
        printf("1、修改用户名\t\t2、修改密码\t\t0、返回上一级\n");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 0:
            choice = 0;
            break;
        case 1:
            while (1)
            {
                printf("请输入新用户名：");
                scanf("%s", name);
                flag = check_user(name, p);
                if (!flag)
                {
                    getchar();
                    printf("请确认修改用户名(y/n)?");
                    if (getchar() == 'y')
                    {
                        save_flag = 1;
                        strcpy(p->name, name);
                        printf("修改成功！\n");
                        getchar();
                    }
                    else
                    {
                        printf("按任意键返回...\n");
                        getchar();
                    }
                    break;
                }
                else
                {
                    printf("\n用户名已存在!请重新输入!");
                    i++;
                    if (i == 3)
                    {
                        printf("输入重复过多！任意键返回主菜单！\n");
                        getchar();
                        getchar();
                        break;
                    }
                }
            }
            i = 0;
            break;
        case 2:
            printf("请输入旧密码:");
            mask_signin_password(oldpass);
            strcpy(admin_password, oldpass);
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
                    printf("请输入新密码:");
                    mask_password(password1);
                    printf("请再次输入密码：");
                    mask_signin_password(password2);
                    if (strcmp(password1, password2) == 0)
                    {
                        save_flag = 1;
                        strcpy(q->password, password1);
                        printf("密码已更新！任意键返回！");
                        getchar();
                        break;
                    }
                    else
                    {
                        i++;
                        printf("两次密码不相同！请重新输入！\n");
                    }
                }
            }
            else
            {
                printf("密码错误！任意键返回...");
                getchar();
            }
            break;
        default:
            choice = 0;
            printf("任意键返回...");
            getchar();
            break;
        }
        if (choice == 0)
        {
            choice = 2;
            break;
        }
    }
}

int check_user(char name[20], struct Person *p)
{
    while (p->next != NULL)
    {
        if (strcmp(p->name, name) == 0)
        {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

struct Person *user_recharge(struct Person *p, char name[])
{
    int num;
    while (p != NULL && strcmp(p->name, name) != 0)
    {
        p = p->next;
    }
    printf("您目前的余额为:%d", p->balance);
    printf("您想充值的金额为:");
    while (scanf("%d", &num) != 1)
    {
        while (getchar() != '\n')
        {
            printf("请输入正确的整数金额!");
        }
    }
    p->balance += num;
    printf("您现在的余额为:%d\n", p->balance);
    return p;
}

void Signin_vertification(char *code, int size)
{
    const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; 
    char userinput[CODE_LENGTH + 1];
    int charset_size = sizeof(charset) - 1;

    while (1)
    {
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            code[i] = charset[rand() % charset_size]; 
        }
        code[size] = '\0'; 
        printf("验证码(%s):", code);
        scanf("%s", userinput);
        if (strcmp(userinput, code) == 0)
        {
            break;
        }
        else
        {
            printf("验证码错误！请重新输入！\n");
        }
    }
}

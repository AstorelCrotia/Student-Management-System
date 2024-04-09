#include "head.h"

void conditionQueryuser() // 条件查询用户
{
    char input[20] = "\0";
    User uid = {0};
    int flag = 0;
    printf("============================\n");
    printf("请输入你要查询的用户名：");
    scanf("%19s", input);
    while (getchar() != '\n')
        ;
    FILE *file_read = fopen("users.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "用户名：%s  密码：%s  余额：%f\n", uid.uid, uid.code, &uid.balance) != EOF)
    {
        if (strcmp(input, uid.uid) == 0)
        {
            printf("============================\n");
            printf("|  用户名：%s             |\n", uid.uid);
            printf("|  密码：%s              |\n", uid.code);
            printf("|  账户余额：%.2f           |\n", uid.balance);
            printf("============================\n");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("============================\n");
        printf("|  用户名不存在！          |\n");
        printf("============================\n");
    }
    fclose(file_read);
}

void conditionQuerybuy() // 条件查询购票历史
{
    char input[20] = "\0";
    Lottery uid = {0};
    int flag = 0;
    printf("============================\n");
    printf("请输入你要查询的用户名：");
    scanf("%19s", input);
    while (getchar() != '\n')
        ;
    FILE *file_read = fopen("history.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "彩票id：%s  购买用户：%s  期号：%s  彩票类型：%d  用户号码：%s  中奖号码：%s  是否开奖：%d  是否中奖：%d  购买日期：%s  开奖日期：%s\n",
                  uid.tid, uid.uid, uid.did, &uid.category, uid.usernumber, uid.winnumber,
                  &uid.draw, &uid.win, uid.buydate, uid.windate) != EOF)
    {
        if (strcmp(input, uid.uid) == 0)
        {
            printf("============================\n");
            printf("|  彩号：%s             |\n", uid.tid);
            printf("|  期号：%s             |\n", uid.did);
            if (uid.category == 1)
            {
                printf("|  类型：bbg彩             |\n");
            }
            else if (uid.category == 2)
            {
                printf("|  类型：A彩             |\n");
            }
            else
            {
                printf("|  类型：B彩             |\n");
            }
            printf("|  用户彩码：%s             |\n", uid.usernumber);
            printf("|  中奖彩码：%s             |\n", uid.winnumber);
            if (uid.win == 1)
            {
                printf("|  是否中奖：中奖！          |\n");
            }
            else
            {
                printf("|  是否中奖：没有！          |\n");
            }
            printf("|  购买日期：%s         |\n", uid.buydate);
            printf("|  开奖日期：%s         |\n", uid.windate);
            printf("============================\n");
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("============================\n");
        printf("|  用户暂无历史信息！       |\n");
        printf("============================\n");
    }
    fclose(file_read);
}

void conditionQuerywin() // 条件查询历史开奖
{
    char input[20] = "\0";
    Lottery uid = {0};
    int flag = 0;
    printf("============================\n");
    printf("请输入你要查询的期号：");
    scanf("%19s", input);
    while (getchar() != '\n')
        ;
    FILE *file_read = fopen("history.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "彩票id：%s  购买用户：%s  期号：%s  彩票类型：%d  用户号码：%s  中奖号码：%s  是否开奖：%d  是否中奖：%d  购买日期：%s  开奖日期：%s\n",
                  uid.tid, uid.uid, uid.did, &uid.category, uid.usernumber, uid.winnumber,
                  &uid.draw, &uid.win, uid.buydate, uid.windate) != EOF)
    {
        if (strcmp(input, uid.did) == 0)
        {
            printf("============================\n");
            printf("|  彩号：%s             |\n", uid.tid);
            printf("|  户号：%s             |\n", uid.uid);
            if (uid.category == 1)
            {
                printf("|  类型：bbg彩             |\n");
            }
            else if (uid.category == 2)
            {
                printf("|  类型：A彩             |\n");
            }
            else
            {
                printf("|  类型：B彩             |\n");
            }
            printf("|  用户彩码：%s             |\n", uid.usernumber);
            printf("|  中奖彩码：%s             |\n", uid.winnumber);
            if (uid.win == 1)
            {
                printf("|  是否中奖：中奖！          |\n");
            }
            else
            {
                printf("|  是否中奖：没有！          |\n");
            }
            printf("|  购买日期：%s         |\n", uid.buydate);
            printf("|  开奖日期：%s         |\n", uid.windate);
            printf("============================\n");
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("============================\n");
        printf("|  无该期号！              |\n");
        printf("============================\n");
    }
    fclose(file_read);
}

void allQueryuser() // 查询所有用户信息
{
    User uid = {0};
    int i = 1;
    FILE *file_read = fopen("users.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    printf("============================\n");
    while (fscanf(file_read, "用户名：%s  密码：%s  余额：%f\n", uid.uid, uid.code, &uid.balance) != EOF)
    {
        printf("|  第%d位用户：  ", i);
        printf("用户名：%s  ", uid.uid);
        printf("密码：%s  ", uid.code);
        printf("账户余额：%.2f     |\n", uid.balance);
        i++;
    }
    printf("============================\n");
    fclose(file_read);
}

void allnQueryubuy() // 查询所有历史购票
{
    Lottery uid = {0};
    FILE *file_read = fopen("history.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "彩票id：%s  购买用户：%s  期号：%s  彩票类型：%d  用户号码：%s  中奖号码：%s  是否开奖：%d  是否中奖：%d  购买日期：%s  开奖日期：%s\n",
                  uid.tid, uid.uid, uid.did, &uid.category, uid.usernumber, uid.winnumber,
                  &uid.draw, &uid.win, uid.buydate, uid.windate) != EOF)
    {
        printf("============================\n");
        printf("|  彩号：%s             |\n", uid.tid);
        printf("|  户号：%s             |\n", uid.uid);
        printf("|  期号：%s             |\n", uid.did);
        if (uid.category == 1)
        {
            printf("|  类型：bbg彩             |\n");
        }
        else if (uid.category == 2)
        {
            printf("|  类型：A彩             |\n");
        }
        else
        {
            printf("|  类型：B彩             |\n");
        }
        printf("|  用户彩码：%s             |\n", uid.usernumber);
        printf("|  中奖彩码：%s             |\n", uid.winnumber);
        if (uid.win == 1)
        {
            printf("|  是否中奖：中奖！          |\n");
        }
        else
        {
            printf("|  是否中奖：没有！          |\n");
        }
        printf("|  购买日期：%s         |\n", uid.buydate);
        printf("|  开奖日期：%s         |\n", uid.windate);
        printf("============================\n");
    }
    fclose(file_read);
}

void allQuerywin() // 查询所有历史开奖
{
    Lottery uid = {0};
    int flag = 0;
    FILE *file_read = fopen("history.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    printf("============================\n");
    while (fscanf(file_read, "彩票id：%s  购买用户：%s  期号：%s  彩票类型：%d  用户号码：%s  中奖号码：%s  是否开奖：%d  是否中奖：%d  购买日期：%s  开奖日期：%s\n",
                  uid.tid, uid.uid, uid.did, &uid.category, uid.usernumber, uid.winnumber,
                  &uid.draw, &uid.win, uid.buydate, uid.windate) != EOF)
    {
        if (uid.win == 1)
        {
            printf("============================\n");
            printf("|  彩号：%s             |\n", uid.tid);
            printf("|  户号：%s             |\n", uid.uid);
            printf("|  期号：%s             |\n", uid.tid);
            if (uid.category == 1)
            {
                printf("|  类型：bbg彩             |\n");
            }
            else if (uid.category == 2)
            {
                printf("|  类型：A彩             |\n");
            }
            else
            {
                printf("|  类型：B彩             |\n");
            }
            printf("|  用户彩码：%s             |\n", uid.usernumber);
            printf("|  中奖彩码：%s             |\n", uid.winnumber);
            printf("|  购买日期：%s             |\n", uid.buydate);
            printf("|  开奖日期：%s             |\n", uid.windate);
            printf("============================\n");
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("============================\n");
        printf("|  无中奖号！              |\n");
        printf("============================\n");
    }
    fclose(file_read);
}

void Querymoney() // 查询彩票中心营收
{
    Revenue uid = {0};
    float balance = 0;
    FILE *file_read = fopen("revenue.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "发生用户：%s  发生时间：%s  彩票类型：%d  发生金额：%f\n",
            uid.uid,uid.buydate,&uid.category,&uid.money) != EOF)
    {
        printf("============================\n");
        printf("|  发生用户：%s             |\n", uid.uid);
        if (uid.category == 1)
        {
            printf("|  类型：bbg彩             |\n");
        }
        else if (uid.category == 2)
        {
            printf("|  类型：A彩             |\n");
        }
        else
        {
            printf("|  类型：B彩             |\n");
        }
        printf("|  发生金额：%s               |\n", uid.buydate);
        printf("|  发生金额：%.2f             |\n", uid.money);
        balance += uid.money;
        printf("|  资金余额：%.2f             |\n", balance);
        printf("============================\n");
    }
    fclose(file_read);
}

void Showuser(char *id) // 用户查询自己信息
{
    User uid = {0};
    FILE *file_read = fopen("users.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "用户名：%s  密码：%s  余额：%f\n", uid.uid, uid.code, &uid.balance) != EOF)
    {
        if (strcmp(id, uid.uid) == 0)
        {
            printf("============================\n");
            printf("|  用户名：%s             |\n", uid.uid);
            printf("|  密码：%s              |\n", uid.code);
            printf("|  账户余额：%.2f           |\n", uid.balance);
            printf("============================\n");
            break;
        }
    }
    fclose(file_read);
}

void conditionQueryuserbuy(char *id) // 条件查询购票历史
{
    Lottery uid = {0};
    int flag = 0;
    FILE *file_read = fopen("history.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    while (fscanf(file_read, "彩票id：%s  购买用户：%s  期号：%s  彩票类型：%d  用户号码：%s  中奖号码：%s  是否开奖：%d  是否中奖：%d  购买日期：%s  开奖日期：%s\n",
                  uid.tid, uid.uid, uid.did, &uid.category, uid.usernumber, uid.winnumber,
                  &uid.draw, &uid.win, uid.buydate, uid.windate) != EOF)
    {
        if (strcmp(id, uid.uid) == 0)
        {
            printf("============================\n");
            printf("|  彩号：%s             |\n", uid.tid);
            printf("|  期号：%s             |\n", uid.did);
            if (uid.category == 1)
            {
                printf("|  类型：bbg彩             |\n");
            }
            else if (uid.category == 2)
            {
                printf("|  类型：A彩             |\n");
            }
            else
            {
                printf("|  类型：B彩             |\n");
            }
            printf("|  用户彩码：%s             |\n", uid.usernumber);
            printf("|  中奖彩码：%s             |\n", uid.winnumber);
            if (uid.win == 1)
            {
                printf("|  是否中奖：中奖！          |\n");
            }
            else
            {
                printf("|  是否中奖：没有！          |\n");
            }
            printf("|  购买日期：%s             |\n", uid.buydate);
            printf("|  开奖日期：%s             |\n", uid.windate);
            printf("============================\n");
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("============================\n");
        printf("|  用户暂无历史信息！       |\n");
        printf("============================\n");
    }
    fclose(file_read);
}

void userQuerywin(char *id) // 查询所有历史开奖
{
    Lottery uid = {0};
    int flag = 0;
    FILE *file_read = fopen("history.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  连接服务器失败！        |\n");
        printf("============================\n");
        return;
    }
    printf("============================\n");
    while (fscanf(file_read, "彩票id：%s  购买用户：%s  期号：%s  彩票类型：%d  用户号码：%s  中奖号码：%s  是否开奖：%d  是否中奖：%d  购买日期：%s  开奖日期：%s\n",
                  uid.tid, uid.uid, uid.did, &uid.category, uid.usernumber, uid.winnumber,
                  &uid.draw, &uid.win, uid.buydate, uid.windate) != EOF)
    {
        if (uid.win == 1 && strcmp(id, uid.uid) == 0)
        {
            printf("============================\n");
            printf("|  彩号：%s             |\n", uid.tid);
            printf("|  户号：%s             |\n", uid.uid);
            printf("|  期号：%s             |\n", uid.did);
            if (uid.category == 1)
            {
                printf("|  类型：bbg彩             |\n");
            }
            else if (uid.category == 2)
            {
                printf("|  类型：A彩             |\n");
            }
            else
            {
                printf("|  类型：B彩             |\n");
            }
            printf("|  用户彩码：%s             |\n", uid.usernumber);
            printf("|  中奖彩码：%s             |\n", uid.winnumber);
            printf("|  购买日期：%s             |\n", uid.buydate);
            printf("|  开奖日期：%s             |\n", uid.windate);
            printf("============================\n");
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("============================\n");
        printf("|  无中奖号！              |\n");
        printf("============================\n");
    }
    fclose(file_read);
}
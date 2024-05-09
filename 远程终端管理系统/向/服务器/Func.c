#include "head.h"

void Orfunc(int *arg) // 初始线程
{
    int cli_fd = *arg;
    pthread_t tid = 0;
    int flag = 0;
    PL date = {};
    UD user = {};
    recv(cli_fd, &date, sizeof(date), 0);
    switch (date.type)
    {
    case 0:
        Validation(cli_fd, date, &flag, &user);
        while (flag != 1)
        {
            recv(cli_fd, &date, sizeof(date), 0);
            Validation(cli_fd, date, &flag, &user);
        }
        Validationcode(cli_fd, date, &flag, user);
        break;
    case 1:
        Registeruser(cli_fd, date, &flag);
        while (flag != 0)
        {
            recv(cli_fd, &date, sizeof(date), 0);
            Registeruser(cli_fd, date, &flag);
        }
        strcat(user.uid, date.date);
        recv(cli_fd, &date, sizeof(date), 0);
        strcat(user.code, date.date);
        printf("用户名：%s  密码：%s\n",user.uid, user.code);
        Registerwrite(user);
        break;
    default:
        break;
    }
}

void Chatfunc(int cli_fd) // 聊天线程
{
    char buf[128] = {};
    int i = 0;
    while (1)
    {
        int bytes = recv(cli_fd, buf, 127, 0);
        if (bytes <= 0)
        {
            Login();
            printf("client is disconnect...\n");
            Logout();
            break;
        }
        if (i == 0)
        {
            i++;
            continue;
        }
        Login();
        printf("从端口%d收到内容；%s\n", cli_fd, buf);
        Logout();
        memset(buf, 0, 128);
    }
}
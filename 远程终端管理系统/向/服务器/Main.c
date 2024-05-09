#include "head.h"

UD *UDhead = NULL;
UL *ULhead = NULL;

int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0)
    {
        Login();
        perror("创建套接字失败");
        Logout();
        return 1;
    }
    struct sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        Login();
        perror("ip地址绑定失败");
        Logout();
        close(sockfd);
        return 1;
    }
    if (listen(sockfd, 20) < 0)
    {
        Login();
        perror("监听连接失败");
        Logout();
        close(sockfd);
        return 1;
    }
    Login();
    printf("服务器架设在%s:%d上\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
    Logout();
    struct sockaddr_in r_addr = {};
    socklen_t len = sizeof(r_addr);
    while (1)
    {
        int cli_fd = accept(sockfd, (struct sockaddr *)&r_addr, &len);
        if (cli_fd < 0)
        {
            Login();
            perror("accept error");
            Logout();
            close(sockfd);
            return 1;
        }
        Userin(cli_fd, &r_addr, ULhead);
        Login();
        printf("客户端ip:%s:%d上线,编号%d\n", inet_ntoa(r_addr.sin_addr), ntohs(r_addr.sin_port), cli_fd);
        Logout();
        pthread_t tid = 0;
        pthread_create(&tid, NULL, (void *)Orfunc, (void *)&cli_fd);
    }
    close(sockfd);
    return 0;
}
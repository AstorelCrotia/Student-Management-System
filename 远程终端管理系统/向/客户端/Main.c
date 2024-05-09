#include "head.h"

int main()
{
    int flag = 0;
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0)
    {
        perror("socket error");
        return 1;
    }
    struct sockaddr_in svr_addr = {};
    svr_addr.sin_family = AF_INET;
    svr_addr.sin_port = htons(8888);
    svr_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (struct sockaddr *)&svr_addr, sizeof(svr_addr)) < 0)
    {
        perror("connect error");
        close(sockfd);
        return 1;
    }
    Welcome(sockfd, &flag);
    if (flag == 0)
    {
        close(sockfd);
        return 0;
    }
    printf("请输入你要发送的消息:");
    char buf[128] = {};
    while (1)
    {
        scanf("%127s", buf);
        if (strcmp(buf, "/exit") == 0)
        {
            break;
        }
        send(sockfd, buf, strlen(buf), 0);
        memset(buf, 0, 128);
    }
    close(sockfd);
    return 0;
}
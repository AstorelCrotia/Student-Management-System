#include "head.h"

void recv_msg(int sockfd)
{
    while (1)
    {
        char buf[128] = {};
        int bytes = recv(sockfd, buf, 127, 0);
        printf(" ’µΩ£∫%s\n", buf);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

typedef struct UserDate
{
    char uid[20];
    char code[20];
    struct User *next;
} UD;

typedef struct UserList
{
    int user;
    struct sockaddr_in addr;
    socklen_t len;
    struct User *next;
} UL;

typedef struct Protocol
{
    int type;
    int size;
    char date[128];
} PL;

void Welcome(int sockfd, int *flag); // ��ʼ��¼
void type1(PL date, int sockfd, char *buf); // ע���֧
void type0(PL date, int sockfd, char *buf); // ��¼��֧
void Rgcode(PL date, int sockfd); // ����ע��
void Lgcode(PL date, int sockfd,int *flag); // ��¼����
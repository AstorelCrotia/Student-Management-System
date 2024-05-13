#ifndef _SERVER_H_
#define _SERVER_H_

//头文件
#include <netdb.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include <time.h>
#include <errno.h>
#include <pthread.h>

//服务器套接字，定义为全局变量
int server_sockfd;

//创建套接字函数
void socket_creat();

//填充服务器地址信息函数
void set_serveraddr(struct sockaddr_in* serveraddr);

//接收处理客户端信息函数
void deal(int service_sockfd);


#endif

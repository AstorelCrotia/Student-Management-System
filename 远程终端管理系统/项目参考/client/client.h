#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <netdb.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>

#include "data_type.h"

//信号捕捉函数
void sig_handler(int signo);

//注册函数
void regist();

//登录函数
void login();

//功能模块函数（界面）
void function();

//登录成功后的操作函数（单独分离出来的）
void userlogin(int client_sockfd,Data data);

#endif

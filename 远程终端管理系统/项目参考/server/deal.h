#ifndef _DEAL_CLIENT_H__
#define _DEAL_CLIENT_H__

			/*************系统头文件**************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <signal.h>
#include <time.h>
#include <errno.h>
#include <arpa/inet.h>
#include <pthread.h> 

FILE* fp_log;//定义日志文件指针为全局变量

pthread_mutex_t mutex;//互斥锁定义为全局变量 

			/*************************信号捕捉函数*************************/
void sig_handler(int signo);

			/*************用户结构体--链表**************/
typedef struct user{
	int type;
	char username[20];
	char passwd[20];
}User;

typedef struct user_link{
	User data;
	struct user_link* next;
}User_link;

User_link* userhead;

			/*************会话记录结构体--链表**************/
typedef struct conversation{
	char username[20];//登录用户
	char client_ip[20];//用户ip
	char login_time[30];//登录时间
	int  client_sockfd;//登录客户端的套接字
	int flag;//用户状态，0在线，1不在线
}Conversation;

typedef struct conversation_link{
	struct conversation data;
	struct conversation_link* next;
}Conversation_link;
Conversation_link* conversationhead;


				/*************心跳数据结构体***********/
typedef struct  heart{
		int client_sockfd;
		int count;
}Heart;

				/*************心跳异常处理函数***********/
void* heart_fun(void* arg);


				/*************线程调用函数***************/
void * readfun(void *arg); 


				/***********输出客户端地址信息************/
void out_addr(struct sockaddr_in* clientaddr);

				/***********登录数据包处理函数************/
void login_type(Data data,int client_sockfd,User_link* userhead,Conversation_link* conversationhead); //登录数据包处理函数
void login_case1(Data data,int client_sockfd,User_link* userhead,Conversation_link* conversationhead);//登录附属函数1
void login_case2(Data data,int client_sockfd,User_link* userhead,Conversation_link* conversationhead);//登录附属函数2
void insert_conversation(Data data,Conversation_link* conversationhead,int client_sockfd);//会话链表插入函数


				/***********注册数据包处理函数*************/
void regist_type(Data data,int client_sockfd);

 
				/***********命令数据包处理函数*************/ 										
void command_type(Data data,int client_sockfd);


				/**********在线用户数据包处理函数**********/ 										 
void online_type(Data data,int client_sockfd); 

	
				/************用户聊天函数******************/ 
void chat_singal_type(); 
void chat_group_type();


				/************删除在线结点函数***************/
void delete_node(Data data);


				/**********用户信息载入保存函数*************/
void load_userfile();
void insert_user(User data);
void save_user();

				/**********获取当前时间函数*****************/
char* time_record();

				/*************注销链表处理函数***************/
void destroy_User_link();
void destroy_Conversation_link();


#endif

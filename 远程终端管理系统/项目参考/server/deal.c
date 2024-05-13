#include "data_type.h"
#include "deal.h"
#include "server.h"

//服务器处理客户端请求函数
void deal(int server_sockfd)
{
	signal(SIGINT,sig_handler);

	printf("服务器开始运行......\n");

	fp_log = fopen("日志文件.txt","a");	//以追加的方式来打开日志文件

	userhead = calloc(1,sizeof(User_link));	//用户头节点创建
	userhead->next = NULL;
	conversationhead = calloc(1,sizeof(Conversation_link));	//会话头节点创建;
	conversationhead->next = NULL;

	load_userfile();	//载入用户文件

	struct sockaddr_in clientaddr;
	socklen_t len = sizeof(clientaddr);

	int client_sockfd;

	pthread_attr_t attr;	//创建线程属性
	pthread_attr_init(&attr);	//初始化线程属性
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);	//设置线程的分离属性

	while(1)	//不断accept接受客户端请求，没有请求会阻塞
	{
		client_sockfd = accept(server_sockfd,(struct sockaddr*)&clientaddr,&len);
		fprintf(fp_log,"时间：%s>客户端：%d 链接了服务器\n\n",time_record(),client_sockfd);
		if(client_sockfd<0)
		{
			perror("accept error");
			continue;
		}
		out_addr(&clientaddr);	//输出链接的客户端的地址信息
		pthread_t client_id;	//用来存放创建的线程
		pthread_create(&client_id,&attr,readfun,(void*)client_sockfd);	//创建线程
		pthread_attr_destroy(&attr);	//销毁线程属性
	}
	return;
}


//信号处理函数
void sig_handler(int signo)
{
	if(signo == SIGINT)
	{
		printf("\n服务器正在退出......\n");
		sleep(1);

		close(server_sockfd);	//关闭服务器套接字
		fclose(fp_log);		//关闭日志文件
		fp_log = NULL;
		destroy_Conversation_link();	//销毁会话链表
		destroy_User_link();	//销毁用户链表
		exit(0);
	}
}

//线程处理函数
void* readfun(void *arg)
{
	pthread_mutex_init(&mutex,NULL);	//初始化互斥锁
	int client_sockfd = (int)arg;
	Data data;	//用来接受客户端的机构体
	Heart heart_data;	//用来统计心跳包
	heart_data.count = 0;
	heart_data.client_sockfd = client_sockfd;
	
	while(1)	//循环接受客户端发送的请求
	{
		pthread_t pthread_id;
		pthread_create(&pthread_id,NULL,heart_fun,(void*)&heart_data);//心跳线程

		memset(&data,0,sizeof(data));
		int retval = read(client_sockfd,&data,sizeof(Data));
		pthread_cancel(pthread_id);		//在处理别类型数据时，把心跳线程停掉。
		if(retval ==-1)
		{
			printf("读取失败\n");
			break;
		}
		if(retval == 0)
		{
			printf("用户已关闭！\n");
			break;
		}
		
		pthread_mutex_lock(&mutex);		//对所有的共享操作上锁

		switch(data.type)	//判断数据类型，根据不同类型接收对应的数据
		{
			case TYPE_LOG:	login_type(data,client_sockfd,userhead,conversationhead);
							break;		//登录数据包处理函数
			case TYPE_REG:	regist_type(data,client_sockfd);
							break;		//注册数据包处理函数
			case TYPE_HRT:	//心跳包函数
				{
					heart_data.count =0;	//心跳计数清零
					Conversation_link* p_conversationhead = conversationhead;
					p_conversationhead = p_conversationhead->next;
					while(p_conversationhead != NULL)	//遍历到最后节点
					{
						if(heart_data.client_sockfd == p_conversationhead->data.client_sockfd)
						{
							printf("客户端:%d\t用户:%s is live!\n",heart_data.client_sockfd,p_conversationhead->data.username);
							break;	//打印用户心跳信息
						}
						p_conversationhead = p_conversationhead->next;
					}
					break;
				}
			case TYPE_CMD:	command_type(data,client_sockfd);
							break;	//命令数据包处理函数
			case TYPE_ONL:	//online_type(data,client_sockfd);
							break;	//在线用户数据包处理函数;
			case TYPE_CHT_SIG:	//chat_single_type(data,client_sockfd);
								break;	//单聊
			case TYPE_CHT_GRP:	//chat_group_type(data,client_sockfd);
								break;	//群聊
			case TYPE_QUT:	delete_node(data);
							fprintf(fp_log,"时间：%s>用户：%s 退出\n\n",time_record(),data.username);
							printf("用户%s 已经退出。\n",data.username);
							break;	//用户关闭处理函数
			case TYPE_EXIT:	printf("客户端：%d 已关闭！\n",client_sockfd);
							break;	//用户关闭处理函数，删除节点
			default:		printf("无此类型数据\n");
							break;
		}
		pthread_mutex_unlock(&mutex);
		if(TYPE_EXIT == data.type)
		{
			break;	//线程结束，退出;
		}
	}
	//日志
	fprintf(fp_log,"时间：%s>客户端：%d 断开链接...\n\n",time_record(),client_sockfd);

	close(client_sockfd);	//关闭套接字
	pthread_mutex_destroy(&mutex);	//销毁互斥锁
		
	return (void*)0;
}

//输出客户端地址信息
void out_addr(struct sockaddr_in* clientaddr)
{
	int port = ntohs(clientaddr->sin_port);
	char client_ip[16];
	memset(client_ip,0,sizeof(client_ip));

	inet_ntop(AF_INET,&clientaddr->sin_addr.s_addr,client_ip,sizeof(client_ip));

	printf("客户端ip:%s\t端口：%d\t链接到服务器...\n",client_ip,port);
}

//获取当前时间函数
char *time_record()
{
	time_t now_time;	//记录当前时间
	now_time = time(NULL);
	return ctime(&now_time);
}

//注销用户链表
void destroy_User_link()
{
	User_link* p_userhead = userhead;
	User_link* pre_userhead = userhead;
	p_userhead = p_userhead->next;
	while(NULL != p_userhead)
	{
		pre_userhead = p_userhead->next;
		free(p_userhead);
		p_userhead = pre_userhead;
	}
	free(userhead);
	userhead = NULL;

	return;

}

//注销会话链表
void destroy_Conversation_link()
{
	Conversation_link* p_conversationhead = conversationhead;
	Conversation_link* pre_conversationhead = conversationhead;
	p_conversationhead = p_conversationhead->next;
	while(NULL != p_conversationhead)
	{
		pre_conversationhead = p_conversationhead->next;
		free(p_conversationhead);
		p_conversationhead = pre_conversationhead;
	}
	free(conversationhead);
	conversationhead = NULL;

	return;

}




//心跳异常处理函数
void* heart_fun(void* arg)
{
	Heart* heart_data = (Heart*)arg;	//处理心跳包数据的结构体变量
	Conversation_link* p_conversationhead = conversationhead;
	Conversation_link* pre_conversationhead = p_conversationhead;
	p_conversationhead = p_conversationhead->next;
	while(p_conversationhead != NULL)
	{
		if(heart_data->client_sockfd == p_conversationhead->data.client_sockfd)
		{
			break;
		}
		pre_conversationhead = p_conversationhead;
		p_conversationhead = p_conversationhead->next;
	}

	while(1)
	{
		sleep(1);
		heart_data->count++;
		if((heart_data->count) == 15)	//找到对应的在线客户，删除节点，关闭套接字
		{
			if(p_conversationhead != NULL)
			{
				fprintf(fp_log,"时间：%s>用户：%s    异常退出！\n\n",time_record(),p_conversationhead->data.username);
				printf("客户端：%d\t用户：%s    异常退出！\n",heart_data->client_sockfd,p_conversationhead->data.username);
				pre_conversationhead->next = p_conversationhead->next;
				free(p_conversationhead);
				p_conversationhead = NULL;
				close(heart_data->client_sockfd);
			}
			else
			{
				printf("客户端：%d\t用户（无）   异常退出!\n",heart_data->client_sockfd);
				fprintf(fp_log,"时间：%s>客户端：%d    异常退出！\n",time_record(),heart_data->client_sockfd);

			}
			return NULL;
		}
	}
	return NULL;
}


//注册数据包处理函数
void regist_type(Data data,int client_sockfd)
{
	User_link* p_userhead = userhead;
	User_link* pre_userhead = p_userhead;
	p_userhead = p_userhead->next;
	
	while(NULL != p_userhead)	//遍历
	{
		pre_userhead = p_userhead;
		if(strcmp(data.username,p_userhead->data.username) != 0)
		{
			p_userhead = p_userhead->next;
		}
		else
		{
			data.retval = 1;		//1表示用户已存在，注册失败;
			write(client_sockfd,&data,sizeof(Data));
			return;
		}
	}
	//此时已经注册成功
	fprintf(fp_log,"时间：%s>用户：%s 注册成功\n\n",time_record(),data.username);

	data.retval = 0;	//0表示注册成功
	write(client_sockfd,&data,sizeof(data));

	User user;	//把注册的用户插入链表并保存
	strcpy(user.username,data.username);
	strcpy(user.passwd,data.passwd);
	User_link* newnode = calloc(1,sizeof(User_link));
	pre_userhead->next = newnode;
	newnode->data = user;
	newnode->next = NULL;

	save_user();	//保存数据

}


//删除在线节点函数
void delete_node(Data data)
{
	Conversation_link* p_conversationhead = conversationhead;
	Conversation_link* pre_conversationhead = p_conversationhead;
	p_conversationhead = p_conversationhead->next;

	while(p_conversationhead != NULL)	//遍历到最后
	{
		if(strcmp(data.username,p_conversationhead->data.username) == 0)
		{
			pre_conversationhead->next = p_conversationhead->next;
			free(p_conversationhead);
			p_conversationhead = NULL;
			break;
		}
		pre_conversationhead = p_conversationhead;
		p_conversationhead = p_conversationhead->next;
	}
}

//命令数据包处理函数
void command_type(Data data,int client_sockfd)
{
	fprintf(fp_log,"时间：%s>用户：%s    发送了shell指令：%s\n",time_record(),data.username,data.shell_send);
	system("touch shell.db");	//创建一个缓存文件
	int fd = open("shell.db",O_RDWR,0777);
	int save_fd = dup(1);
	dup2(fd,1);

	int retval = system(data.shell_send);	//执行客户端传来的指令，写进fd;
	dup2(save_fd,1);

	if(retval != 0)	//system命令错误，返回2;
	{
		data.retval = 2;
		write(client_sockfd,&data,sizeof(data));
		return;
	}
	lseek(fd,SEEK_SET,0);	//移动文件指针到头部
	read(fd,data.shell_rec,sizeof(data.shell_rec));	//将执行结果从fd读取到data.shell_rec;
	close(fd);

	system("rm shell.db");	//删除缓存文件
	write(client_sockfd,&data,sizeof(data));

	return;
}

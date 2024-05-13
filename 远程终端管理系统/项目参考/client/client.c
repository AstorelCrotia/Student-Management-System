//#include "data_type.h"
#include "client.h"

int client_sockfd;	//定义为全局变量

int main()
{
	signal(SIGINT,sig_handler);	//调用信号函数，控制客户端退出
	signal(SIGALRM,sig_handler);	//调用信号函数，控制客户端

	client_sockfd = socket(AF_INET,SOCK_STREAM,0);	//创建套接字
	if(client_sockfd<0)
	{
		perror("socket error");
		exit(1);
	}

	struct sockaddr_in serveraddr;	//专用地址结构体
	memset(&serveraddr,0,sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(8888);
	inet_pton(AF_INET,"127.0.0.1",&serveraddr.sin_addr.s_addr);

	if(connect(client_sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr))<0)	//链接到服务器端
	{
		perror("connet error");
		exit(1);
	}

	alarm(1);		//触发闹钟信号，给服务器发心跳包;

	function();		//功能模块，界面

	Data data;	//正常退出客户端，给服务器发送一个退出的包;
	data.type = TYPE_EXIT;
	
	write(client_sockfd,&data,sizeof(data));
	close(client_sockfd);

	printf("\t \t\033[33m您已退出《IOTEK》客户端！欢迎下次光临！\033[0m\n");

	return 0;
}


//设置一个信号捕捉来控制
void sig_handler(int signo)
{
	if(signo == SIGINT)		//捕捉ctrl+C，来关闭客户端
	{
		printf("\t \t\033[33m您已退出《IOTEK》客户端！欢迎下次光临！\033[0m\n");
		Data data;	//正常退出客户端，给服务器发送一个退出的包;
		data.type = TYPE_EXIT;
	
		write(client_sockfd,&data,sizeof(data));
		close(client_sockfd);
		exit(1);
	}
	if(signo == SIGALRM)	//接受闹钟信号，发送心跳包
	{
		Data data;
		data.type = TYPE_HRT;	//设置数据包类型为心跳类型
		int retval = write(client_sockfd,&data,sizeof(data));
		if(retval == -1)
		{
			printf("服务器端已关闭，即将退出《IOTEK》客户端\n");
			exit(0);
		}
		alarm(3);
	}
}


//功能界面函数
void function()
{
	while(1)
	{
		system("clear");
		printf("\t \t\033[33m***********欢迎进入《IOTEK》客户端*********\033[0m\n");
		printf("\t \t\033[33m***              1：用户注册            ***\033[0m\n");
		printf("\t \t\033[33m***              2：用户登录            ***\033[0m\n");
		printf("\t \t\033[33m***              0：推出客户端          ***\033[0m\n");
		printf("\t \t\033[33m*******************************************\033[0m\n");
		printf("请输入选项: \n");
		int choose = -1;
		scanf("%d",&choose);
		while(getchar()!='\n');
		
		switch(choose)
		{
			case 1:	regist();
					break;
			case 2:	login();
					break;
			case 0:	break;
			default:	printf("输入错误，请重新输入！\n");
		}
		if(choose == 0 || choose == 2)
		{
			break;		//登录过如果失败，就推出界面，重新登录客户端;
		}
	}
}


//用户注册函数
void regist()
{
	Data data;	//定义一个数据包
	memset(&data,0,sizeof(Data));	//初始化
	printf("请输入用户名:");
	scanf("%s",data.username);
	while(getchar()!='\n');
	
	printf("请输入密码:");
	scanf("%s",data.passwd);
	while(getchar()!='\n');

	data.type = TYPE_REG;

	write(client_sockfd,&data,sizeof(data));	//发送数据给服务器处理
	memset(&data,0,sizeof(Data));
	read(client_sockfd,&data,sizeof(data));		//读取服务器返回的数据

	if( data.retval == 0)	//返回值0为成功注册，1为该用户已注册过
	{
		printf("注册成功，正在返回主菜单......\n");
		sleep(1);
		system("clear");
	}
	else
	{
		printf("该用户已存在，无法注册，正在返回主菜单......\n");
		sleep(1);
		system("clear");
	}
}

void login()
{
	Data data;	//定义一个数据包;
	int count = 1;
	while(1)	//控制输入帐号密码次数，3次不对返回;
	{
		memset(&data,0,sizeof(Data));	//一定要初始化
		printf("请输入用户名：");
		scanf("%s",data.username);
		printf("请输入密码：");
		scanf("%s",data.passwd);
		data.type = TYPE_LOG;
		data.retval = 1;
		
		write(client_sockfd,&data,sizeof(data));	//把数据发送给服务器
		memset(&data,0,sizeof(Data));	//一定要初始化
		read(client_sockfd,&data,sizeof(data));		//读取服务器返回的数据
		if(data.retval == 0)	//0为成功登陆，1为账户密码错误，2为用户已登陆
		{
			printf("登录成功，正在进入IOTEK终端...\n");
			sleep(1);
			userlogin(client_sockfd,data);	//进入终端模块
			break;
		}
		else if(data.retval == 2)
		{
			printf("该用户已在其他客户端登陆，您暂时无法登陆！\n");
			printf("即将退出IOTEK客户端\n");
			sleep(1);
			return;
		}
		else
		{
			printf("输入错误%d次，请重新输入用户名和密码！\033[33m（3次自动退出客户端）\33[0m\n",count);
			count++;
		}
		if(count == 4)	//输入错误3次，强制退出
		{
			printf("您已连续输入错误3次，即将被强制退出客户端......\n");
			sleep(1);
			break;
		}
	}

}

#include "server.h"
#include "data_type.h"


//主函数
int main()
{
	system("clear");
	server_sockfd = socket(AF_INET,SOCK_STREAM,0);	//创建套接字
	struct sockaddr_in serveraddr;
	set_serveraddr(&serveraddr);	//获得服务器地址ip等信息

	int opt = 1;
	int retOfset = 0; //防止address被占用
	if((retOfset = setsockopt(server_sockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt)))<0)
	{
		perror("setsocket error");
		exit(1);
	}

	//bind;将socket和地址绑定
	if(bind(server_sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr))<0)
	{
		perror("bind error");
		exit(1);
	}

	//list;监听
	if(listen(server_sockfd,20)<0)
	{
		perror("listen error");
		exit(1);
	}

	//接收客户端链接信息，处理客户端请求
	deal(server_sockfd);

	//结束服务器段
	printf("\n服务器正在退出......\n");
	close(server_sockfd);

	return 0;
}


//创建套接字
void socket_creat()
{
	server_sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(server_sockfd<0)
	{
		perror("socket error");
		exit(1);
	}
}


//填充服务器地址信息函数
void set_serveraddr(struct sockaddr_in* serveraddr)
{
	FILE* fp_pro = fopen("配置文件.txt","r");	//打开配置文件
	char server_ip[20];
	fscanf(fp_pro,"%s",server_ip);	//从文件里读取服务器ip
	printf("服务器ip: %s\n",server_ip);

	int port;
	fscanf(fp_pro,"%d",&port);
	printf("服务器端口：%d\n",port);

	memset(serveraddr,0,sizeof(struct sockaddr_in));	//初始化地址结构体变量
	serveraddr->sin_family = AF_INET;
	serveraddr->sin_port = htons(port);
	inet_pton(AF_INET,server_ip,&serveraddr->sin_addr.s_addr);

	fclose(fp_pro);
	fp_pro = NULL;
}


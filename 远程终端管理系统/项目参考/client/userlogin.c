#include "data_type.h"
#include "client.h"
#include "userlogin.h"

Data data2;	//用来控制ctrl+c信号，给服务器发送QUT类型的数据包
int fd2;	//用来控制ctrl+c信号，给服务器发送QUT类型的数据包

void userlogin(int client_sockfd,Data data)
{
	if(signal(SIGINT,sig_handler2) == SIG_ERR)	//调用信号函数，控制非正常退出
	{
		perror("signal sigint error");
		exit(1);
	}
	data2 = data;
	fd2 = client_sockfd;

	function2(client_sockfd,data);
	sleep(1);
	return;
}

void sig_handler2(int signo)
{
	if(signo == SIGINT)	//捕捉ctrl+c信号，关闭客户端
	{
		printf("\t\t\33[33m成功退出IOTEK客户端，欢迎下次再来...\33[0m\n");
		data2.type = TYPE_QUT; //发送退出包给服务器，让服务器删除节点;
		write(fd2,&data2,sizeof(data2));
		
		printf("\t\t\33[33m您已成功退出IOTEK客户端！\33[0m\n");
		data2.type = TYPE_EXIT;
		write(fd2,&data2,sizeof(data2));

		close(fd2);
		exit(0);

	}
}

void function2(int client_sockfd,Data data)
{
	while(1)
	{
		system("clear");

		printf("\t\t\t\33[34m*****欢迎进入IOTEK终端*****\33[0m\n");
		printf("\t\t\t\33[34m***  1:向服务器发送命令****\33[0m\n");
		printf("\t\t\t\33[34m***  2:单独聊天         ***\33[0m\n");
		printf("\t\t\t\33[34m***  3:群聊             ***\33[0m\n");
		printf("\t\t\t\33[34m***  4:查询在线客户     ***\33[0m\n");
		printf("\t\t\t\33[34m***  0:退出             ***\33[0m\n");
		printf("\t\t\t\33[34m***************************\33[0m\n");

		printf("请输入选项：");
		int choose = -1;
		scanf("%d",&choose);
		while(getchar() != '\n');
		switch(choose)
		{
			case 1:	shell_send(client_sockfd,data);
					break;
			case 2:	//single_chat(client_sockfd,data);
					break;
			case 3:	//group_chat(client_sockfd,data);
					break;
			case 4:	//user_online(client_sockfd,data);
					break;
			case 0:	
				{
					printf("\t\t\033[33m成功退出IOTEK终端，欢迎下次再来...\033[0m\n\n");
					data.type = TYPE_QUT;	//用户退出发送数据包给服务器，服务器删除节点
					write(client_sockfd,&data,sizeof(data));
					break;
				}
			default:	printf("输入错误，请重新输入：\n");
						sleep(1);
						break;
		}
		if(choose == 0)
		{
			break;
		}
	}	
}


//shell命令函数
void shell_send(int client_sockfd,Data data)
{
	data.type = TYPE_CMD;	//更改数据包类型
	printf("请输入要发送给服务器的命令：\n");
	fgets(data.shell_send,sizeof(data.shell_send),stdin);	//填写要发送的命令

	write(client_sockfd,&data,sizeof(data));
	memset(&data,0,sizeof(data));
	read(client_sockfd,&data,sizeof(data));
	if(data.retval == 2)
	{
		printf("命令输入错误！按回车键返回主菜单...\n");
		char a = '\0';
		scanf("%c",&a);
		return;
	}
	printf("服务器返回的结果：\n%s\n",data.shell_rec);
	char a = '\0';
	printf("请查看结果，按回车键返回主菜单...\n");
	scanf("%c",&a);

	return;

}


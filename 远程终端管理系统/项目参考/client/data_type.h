#ifndef _TYPE_H_
#define _TYPE_H_

typedef struct data
{
	int type;	//数据类型
	char username[20]; 	//用户名
	char passwd[20];	//用户密码
	int retval;			//用来控制返回值，1代表不正常，0正常
	char shell_send[30];	//客户端发送命令
	char shell_rec[1024];	//服务器返回结果
	char chat_name_rec[20];		//接受聊天的用户的名字
	char chat_name_send[20];	//发送聊天的用户的名字
	char chat_data[512];		//聊天内容，群聊单聊都用这个传递聊天内容
	char chat_time[30];			//聊天时间;
	int heart_send;		//客户端发送心跳包;
	char user_online[512];		//统计在线客户
}Data;

//用宏来定义一些协议，用于识别数据包的功能;
#define TYPE_LOG	1	//登录包
#define TYPE_REG	2	//注册包
#define TYPE_MSG	3	//消息包
#define TYPE_HRT	4	//心跳包
#define TYPE_CMD	5	//命令包
#define TYPE_ONL	6	//在线用户包
#define TYPE_CHT_SIG	7	//单聊包
#define TYPE_CHT_GRP	8	//群聊包
#define TYPE_QUT	9	//用户正常退出
#define TYPE_EXIT	10	//客户端退出
#define TYPE_CHT_REC	11	//聊天信息接受包

#endif

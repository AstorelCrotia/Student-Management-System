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
    struct UserDate *next;
} UD;

typedef struct UserList
{
    int user;
    struct sockaddr_in addr;
    socklen_t len;
    struct UserList *next;
} UL;

typedef struct Protocol
{
    int type;
    int size;
    char date[128];
} PL;

void Login();                                                  // 文件日志写入
void Logout();                                                 // 文件日志读取
void Logdate();                                                // 数据接口
void DelUL(int user, struct sockaddr_in *addr);                // 删除客户端链表
void DelUD(char *user);                                        // 删除用户链表
void Orfunc(int *cli_fd);                                       // 初始线程
void Chatfunc(int cli_fd);                                     // 聊天线程
void UserDT(int user, struct sockaddr_in *addr, UD *UDhead);   // 创建账户链表
void Userin(int user, struct sockaddr_in *addr, UL *ULhead);   // 创建客户端链表
void Registeruser(int sockfd, PL date, int *flag);             // 注册用户名
void Registerwrite(UD user);                                   // 注册内容写入文件
void Validationcode(int sockfd, PL date, int *flag, UD user); // 验证密码功能
void Validation(int sockfd, PL date, int *flag, UD *user);     // 验证用户名功能
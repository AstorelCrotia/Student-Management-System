#include "head.h"

int Interface(int usergroup,char username) //界面
{
    int sc = 0;
    if(usergroup == 1)
    {
        printf("欢迎管理员%s登录学生管理系统！\n",username);
        printf("请选择你需要的功能！”\n");
        printf("录入学生信息输入“1”        查修学生信息输入“2”\n");
        printf("修改学生信息输入“3”        删除学生信息输入“4”\n");
        printf("退出管理系统输入其它任意字符\n");
        scanf("%d",&sc);
    }
    else
    {
        printf("欢迎学生%s登录学生管理系统！\n",username);
        printf("请选择你需要的功能！”\n");
        printf("查询信息输入“1”        修改密码输入“2”\n");
        printf("退出管理系统输入其它任意字符\n");
        scanf("%d",&sc);
    }
    return sc;
}
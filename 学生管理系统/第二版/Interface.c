#include "head.h"

void Interface(int usergroup, char *username) // 界面
{
    int sc = 0;
    char flag = '\0';
    if (usergroup == 1)
    {
        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
        printf("欢迎管理员%s登录学生管理系统！\n", username);
        printf("请选择你需要的功能！”\n");
        printf("查询功能输入“1”        修改功能输入“2”\n");
        printf("录入功能输入“3”        删除功能输入“4”\n");
        printf("退出管理系统输入其它:");
        scanf("%d", &sc);
        switch (sc)
        {
        case 1:
            while (1)
            {
                Query(usergroup);
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("是否继续查询：（Y/N） ");
                scanf(" %c", &flag);
                if (flag == 'n' || flag == 'N')
                {
                    break;
                }
            }
            break;
        case 2:
            while (1)
            {
                // Modify(usergroup, username);
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("是否继续修改：（Y/N） ");
                scanf(" %c", &flag);
                if (flag == 'n' || flag == 'N')
                {
                    break;
                }
            }
            break;
        case 3:
            while (1)
            {
                Input(usergroup);
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("是否继续录入：（Y/N） ");
                scanf(" %c", &flag);
                if (flag == 'n' || flag == 'N')
                {
                    break;
                }
            }
            break;
        case 4:
            while (1)
            {
                // Delete(usergroup, username);
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("是否继续删除：（Y/N） ");
                scanf(" %c", &flag);
                if (flag == 'n' || flag == 'N')
                {
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    else if (usergroup == 2)
    {
        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
        printf("欢迎学生%s登录学生管理系统！\n", username);
        printf("请选择你需要的功能！”\n");
        printf("查询功能输入“1”        修改密码输入“2”\n");
        printf("退出管理系统输入其它:");
        scanf("%d", &sc);
        switch (sc)
        {
        case 1:
            while (1)
            {
                Query(usergroup);
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("是否继续查询：（Y/N） ");
                scanf(" %c", &flag);
                if (flag == 'n' || flag == 'N')
                {
                    break;
                }
            }
            break;
        case 2:
            while (1)
            {
                // Modify(usergroup, username);
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("是否继续修改：（Y/N） ");
                scanf(" %c", &flag);
                if (flag == 'n' || flag == 'N')
                {
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    else
    {
        return;
    }
}
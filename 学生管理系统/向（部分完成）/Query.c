#include "head.h"

void Query(int usergroup) // 查询
{
    int sc = 0;
    char input[20] = "\0";
    if (usergroup == 1)
    {
        while(1)
        {
            sc = 0;
            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
            printf("请选择你需要的功能！”\n");
            printf("查询学生信息请输入“1”        查询管理员信息请输入“2”\n");
            printf("退出查询功能输入其它:");
            scanf("%d", &sc);
            if (sc == 1)
            {
                Student *head = NULL;
                Student *temp = (Student *)malloc(sizeof(Student));
                Student s1 = {0};
                FILE *file_read = fopen("Students.txt", "r");
                if (file_read == NULL)
                {
                    printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                    printf("服务器连接失败\n");
                    break;
                }
                while (fread(&s1, sizeof(Student), 1, file_read) == 1)
                {
                    if (head == NULL)
                    {
                        head = s1;
                        temp = s1;
                    }
                    else
                    {
                        temp->next = s1;
                        temp = s1;
                    }
                }
                temp = head;
                sc = 0;
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("请选择你需要的功能！”\n");
                printf("根据指定的学生信息查询输入“1”        全部显示输入“2”\n");
                printf("退出查询功能输入其它:");
                scanf("%d", &sc);
                if (sc == 1)
                {
                    sc = 0;
                    printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                    printf("请选择你需要的功能！”\n");
                    printf("根据学生姓名查询输入“1”           根据学生数学成绩查询输入“2” \n");
                    printf("根据学生语文成绩查询输入“3”        根据学生英语成绩查询输入“4” \n");
                    printf("根据学生成绩排名查询输入“5”        退出查询功能输入其它 \n");
                    scanf("%d", &sc);
                    switch (sc)
                    {
                    case 1:
                        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                        printf("请输入要查询的姓名：");
                        scanf("%19s", input);
                        while (temp->next != NULL)
                        {
                            if (strcmp(input, temp->name) == 0)
                            {
                                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                                printf("该学生的id：%d，该学生的姓名：%s，该学生的性别：%s，该学生的年龄：%d，\n", s1.username, s1.name, s1.gender, s1.age);
                                printf("该学生的班级：%s，该学生的成绩名次：%d，\n", s1.class, s1.rank);
                                printf("该学生的数学成绩：%d，该学生的语文成绩：d，该学生的英语成绩：d，\n", s1.math, s1.chinese, s1.english);
                                printf("用户名已经存在！\n");
                                flag = 1;
                                break;
                            }
                        }
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    default:
                        break;
                    }
                }
                else if (sc == 2)
                {
                }
                else
                {
                    break;
                }
            }
            else if (sc == 2)
            {
                sc = 0;
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("请选择你需要的功能！”\n");
                printf("根据指定的管理员信息查询输入“1”      全部显示输入“2”\n");
                printf("退出查询功能输入其它:");
                scanf("%d", &sc);
                if (sc == 1)
                {
                }
                else if (sc == 2)
                {
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    else if (usergroup == 2)
    {
    }
    else
    {
        return;
    }
}
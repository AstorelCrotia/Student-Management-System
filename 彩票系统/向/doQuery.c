#include "head.h"

void conditionQueryuser() // 条件查询用户
{
    int rk = 0;
    int i = 0;
    int sc = 0;
    char input[20] = "\0";
    float score = 0;
    if (usergroup == 1)
    {
        while (1)
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
                Student *temp = NULL;
                Student *s1 = (Student *)malloc(sizeof(Student));
                if (s1 == NULL)
                {
                    printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                    printf("内存分配失败\n");
                    break;
                }
                FILE *file_read = fopen("Students.txt", "r");
                if (file_read == NULL)
                {
                    printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                    printf("服务器连接失败\n");
                    break;
                }
                while (fread(s1, sizeof(Student), 1, file_read) == 1)
                {
                    s1->next = NULL;
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
                    s1 = (Student *)malloc(sizeof(Student));
                    if (s1 == NULL)
                    {
                        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                        printf("内存分配失败\n");
                        break;
                    }
                }
                fclose(file_read);
                temp = head;
                if (temp == NULL)
                {
                    printf("数据获取失败\n");
                    free(s1);
                    return;
                }
                free(s1);
                Student s2 = {0};
                Student *end = NULL;
                while (1)
                {
                    int flag = 0;
                    while (temp->next != end)
                    {
                        if (temp->sum < temp->next->sum)
                        {
                            s2 = *temp;
                            *temp = *(temp->next);
                            *(temp->next) = s2;
                            flag = 1;
                        }
                        temp = temp->next;
                    }
                    if (flag == 0)
                    {
                        break;
                    }
                    end = temp;
                    temp = head;
                }
                temp = head;
                int i = 1;
                while (temp != NULL)
                {
                    temp->rank = i;
                    temp = temp->next;
                    i++;
                }
                // temp = head;
                // while (temp != NULL)
                //{
                //     Student *toFree = temp;
                //     temp = temp->next;
                //     free(toFree);
                // }
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
                    printf("根据学生成绩排名查询输入“5”        退出查询功能输入其它:");
                    scanf("%d", &sc);
                    switch (sc)
                    {
                    case 1:
                        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                        printf("请输入要查询的姓名：");
                        scanf("%19s", input);
                        temp = head;
                        while (temp != NULL)
                        {
                            if (strcmp(input, temp->name) == 0)
                            {
                                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                                printf("该学生的id：%s，该学生的姓名：%s，该学生的性别：%s，该学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                                printf("该学生的班级：%s，该学生的成绩名次：%d，\n", temp->class, temp->rank);
                                printf("该学生的数学成绩：%.1f，该学生的语文成绩：%.1f，该学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                                sc = 1;
                                break;
                            }
                            temp = temp->next;
                            sc = 0;
                        }
                        if (sc == 0)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("没有找到该姓名的学生!\n");
                        }
                        break;
                    case 2:
                        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                        printf("请输入要查询的数学成绩：");
                        scanf("%.1f", &score);
                        temp = head;
                        while (temp != NULL)
                        {
                            if (score == temp->math)
                            {
                                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                                printf("该学生的id：%s，该学生的姓名：%s，该学生的性别：%s，该学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                                printf("该学生的班级：%s，该学生的成绩名次：%d，\n", temp->class, temp->rank);
                                printf("该学生的数学成绩：%.1f，该学生的语文成绩：%.1f，该学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                                sc = 1;
                                break;
                            }
                            temp = temp->next;
                            sc = 0;
                        }
                        if (sc == 0)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("没有找到数学成绩为%.1f的学生!\n", score);
                        }
                        break;
                    case 3:
                        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                        printf("请输入要查询的语文成绩：");
                        scanf("%.1f", &score);
                        temp = head;
                        while (temp != NULL)
                        {
                            if (score == temp->chinese)
                            {
                                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                                printf("该学生的id：%s，该学生的姓名：%s，该学生的性别：%s，该学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                                printf("该学生的班级：%s，该学生的成绩名次：%d，\n", temp->class, temp->rank);
                                printf("该学生的数学成绩：%.1f，该学生的语文成绩：%.1f，该学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                                sc = 1;
                                break;
                            }
                            temp = temp->next;
                            sc = 0;
                        }
                        if (sc == 0)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("没有找到语文成绩为%.1f的学生!\n", score);
                        }
                        break;
                    case 4:
                        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                        printf("请输入要查询的英语成绩：");
                        scanf("%.1f", &score);
                        temp = head;
                        while (temp != NULL)
                        {
                            if (score == temp->english)
                            {
                                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                                printf("该学生的id：%s，该学生的姓名：%s，该学生的性别：%s，该学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                                printf("该学生的班级：%s，该学生的成绩名次：%d，\n", temp->class, temp->rank);
                                printf("该学生的数学成绩：%.1f，该学生的语文成绩：%.1f，该学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                                sc = 1;
                                break;
                            }
                            temp = temp->next;
                            sc = 0;
                        }
                        if (sc == 0)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("没有找到英语成绩为%.1f的学生!\n", score);
                        }
                        break;
                    case 5:
                        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                        printf("请输入要查询的姓名：");
                        scanf("%d", &rk);
                        temp = head;
                        while (temp != NULL)
                        {
                            if (rk == temp->rank)
                            {
                                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                                printf("该学生的id：%s，该学生的姓名：%s，该学生的性别：%s，该学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                                printf("该学生的班级：%s，该学生的成绩名次：%d，\n", temp->class, temp->rank);
                                printf("该学生的数学成绩：%.1f，该学生的语文成绩：%.1f，该学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                                sc = 1;
                                break;
                            }
                            temp = temp->next;
                            sc = 0;
                        }
                        if (sc == 0)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("没有找到该排名的学生!\n");
                        }
                        break;
                    default:
                        break;
                    }
                }
                else if (sc == 2)
                {
                    i = 1;
                    temp = head;
                    while (temp != NULL)
                    {
                        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                        printf("第%d位学生为\n",i);
                        printf("学生的id：%s，学生的姓名：%s，学生的性别：%s，学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                        printf("学生的班级：%s，学生的成绩名次：%d，\n", temp->class, temp->rank);
                        printf("学生的数学成绩：%.1f，学生的语文成绩：%.1f，学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                        temp = temp->next;
                        i++;
                    }
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
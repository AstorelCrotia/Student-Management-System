#include "head.h"

void Query(int usergroup) // 查询
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
                        i = 1;
                        sc = 0;
                        while (temp != NULL)
                        {
                            if (strcmp(input, temp->name) == 0)
                            {
                                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                                printf("第%d位学生为\n", i);
                                printf("该学生的id：%s，该学生的姓名：%s，该学生的性别：%s，该学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                                printf("该学生的班级：%s，该学生的密码：%s，该学生的成绩名次：%d，该学生的总成绩为：%.1f\n", temp->class, temp->code, temp->rank, temp->sum);
                                printf("该学生的数学成绩：%.1f，该学生的语文成绩：%.1f，该学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                                sc = 1;
                                i++;
                            }
                            temp = temp->next;
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
                        scanf("%f", &score);
                        temp = head;
                        i = 1;
                        sc = 0;
                        while (temp != NULL)
                        {
                            if (score == temp->math)
                            {
                                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                                printf("第%d位学生为\n", i);
                                printf("该学生的id：%s，该学生的姓名：%s，该学生的性别：%s，该学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                                printf("该学生的班级：%s，该学生的密码：%s，该学生的成绩名次：%d，该学生的总成绩为：%.1f\n", temp->class, temp->code, temp->rank, temp->sum);
                                printf("该学生的数学成绩：%.1f，该学生的语文成绩：%.1f，该学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                                sc = 1;
                                i++;
                            }
                            temp = temp->next;
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
                        scanf("%f", &score);
                        i = 1;
                        sc = 0;
                        temp = head;
                        while (temp != NULL)
                        {
                            if (score == temp->chinese)
                            {
                                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                                printf("第%d位学生为\n", i);
                                printf("该学生的id：%s，该学生的姓名：%s，该学生的性别：%s，该学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                                printf("该学生的班级：%s，该学生的密码：%s，该学生的成绩名次：%d，该学生的总成绩为：%.1f\n", temp->class, temp->code, temp->rank, temp->sum);
                                printf("该学生的数学成绩：%.1f，该学生的语文成绩：%.1f，该学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                                sc = 1;
                                i++;
                            }
                            temp = temp->next;
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
                        scanf("%f", &score);
                        i = 1;
                        temp = head;
                        sc = 0;
                        while (temp != NULL)
                        {
                            if (score == temp->english)
                            {
                                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                                printf("第%d位学生为\n", i);
                                printf("该学生的id：%s，该学生的姓名：%s，该学生的性别：%s，该学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                                printf("该学生的班级：%s，该学生的密码：%s，该学生的成绩名次：%d，该学生的总成绩为：%.1f\n", temp->class, temp->code, temp->rank, temp->sum);
                                printf("该学生的数学成绩：%.1f，该学生的语文成绩：%.1f，该学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                                sc = 1;
                                i++;
                            }
                            temp = temp->next;
                        }
                        if (sc == 0)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("没有找到英语成绩为%.1f的学生!\n", score);
                        }
                        break;
                    case 5:
                        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                        printf("请输入要查询的总分排名：");
                        scanf("%d", &rk);
                        i = 1;
                        sc = 0;
                        temp = head;
                        while (temp != NULL)
                        {
                            if (rk == temp->rank)
                            {
                                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                                printf("第%d位学生为\n", i);
                                printf("该学生的id：%s，该学生的姓名：%s，该学生的性别：%s，该学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                                printf("该学生的班级：%s，该学生的密码：%s，该学生的成绩名次：%d，该学生的总成绩为：%.1f\n", temp->class, temp->code, temp->rank, temp->sum);
                                printf("该学生的数学成绩：%.1f，该学生的语文成绩：%.1f，该学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                                sc = 1;
                                i++;
                            }
                            temp = temp->next;
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
                    printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                    printf("请选择你需要的功能！”\n");
                    printf("根据学生姓名逆序降序输入“1”           根据学生姓名升序排序输入“2” \n");
                    printf("根据学生数学成绩降序排序输入“3”       根据学生数学成绩升序排序输入“4” \n");
                    printf("根据学生语文成绩降序排序输入“5”       根据学生语文成绩升序排序输入“6” \n");
                    printf("根据学生英语成绩降序排序输入“7”       根据学生英语成绩升序排序输入“8” \n");
                    printf("根据学生总成绩降序排序输入“9”         根据学生总成绩升序排序输入“0” \n");
                    printf("退出查询功能输入其它:");
                    scanf("%d", &sc);
                    temp = head;
                    switch (sc)
                    {
                    case 1:
                        end = NULL;
                        while (1)
                        {
                            int flag = 0;
                            while (temp->next != end)
                            {
                                if (temp->name < temp->next->name)
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
                        while (temp != NULL)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("第%d位学生为\n", i);
                            printf("学生的id：%s，学生的姓名：%s，学生的性别：%s，学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                            printf("学生的班级：%s，该学生的密码：%s，学生的成绩名次：%d，学生的成绩总分：%.1f\n", temp->class, temp->code, temp->rank, temp->sum);
                            printf("学生的数学成绩：%.1f，学生的语文成绩：%.1f，学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                            temp = temp->next;
                            i++;
                        }
                        break;
                    case 2:
                        end = NULL;
                        temp = head;
                        while (1)
                        {
                            int flag = 0;
                            while (temp->next != end)
                            {
                                if (temp->name > temp->next->name)
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
                        while (temp != NULL)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("第%d位学生为\n", i);
                            printf("学生的id：%s，学生的姓名：%s，学生的性别：%s，学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                            printf("该学生的班级：%s，该学生的密码：%s，该学生的成绩名次：%d，该学生的总成绩为：%.1f\n", temp->class, temp->code, temp->rank, temp->sum);
                            printf("学生的数学成绩：%.1f，学生的语文成绩：%.1f，学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                            temp = temp->next;
                            i++;
                        }
                        break;
                    case 3:
                        end = NULL;
                        temp = head;
                        while (1)
                        {
                            int flag = 0;
                            while (temp->next != end)
                            {
                                if (temp->math < temp->next->math)
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
                        while (temp != NULL)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("第%d位学生为\n", i);
                            printf("学生的id：%s，学生的姓名：%s，学生的性别：%s，学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                            printf("该学生的班级：%s，该学生的密码：%s，该学生的成绩名次：%d，该学生的总成绩为：%.1f\n", temp->class, temp->code, temp->rank, temp->sum);
                            printf("学生的数学成绩：%.1f，学生的语文成绩：%.1f，学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                            temp = temp->next;
                            i++;
                        }
                        break;
                    case 4:
                        end = NULL;
                        temp = head;
                        while (1)
                        {
                            int flag = 0;
                            while (temp->next != end)
                            {
                                if (temp->math > temp->next->math)
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
                        while (temp != NULL)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("第%d位学生为\n", i);
                            printf("学生的id：%s，学生的姓名：%s，学生的性别：%s，学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                            printf("该学生的班级：%s，该学生的密码：%s，该学生的成绩名次：%d，该学生的总成绩为：%.1f\n", temp->class, temp->code, temp->rank, temp->sum);
                            printf("学生的数学成绩：%.1f，学生的语文成绩：%.1f，学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                            temp = temp->next;
                            i++;
                        }
                        break;
                    case 5:
                        end = NULL;
                        temp = head;
                        while (1)
                        {
                            int flag = 0;
                            while (temp->next != end)
                            {
                                if (temp->chinese < temp->next->chinese)
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
                        while (temp != NULL)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("第%d位学生为\n", i);
                            printf("学生的id：%s，学生的姓名：%s，学生的性别：%s，学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                            printf("该学生的班级：%s，该学生的密码：%s，该学生的成绩名次：%d，该学生的总成绩为：%.1f\n", temp->class, temp->code, temp->rank, temp->sum);
                            printf("学生的数学成绩：%.1f，学生的语文成绩：%.1f，学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                            temp = temp->next;
                            i++;
                        }
                        break;
                    case 6:
                        end = NULL;
                        temp = head;
                        while (1)
                        {
                            int flag = 0;
                            while (temp->next != end)
                            {
                                if (temp->chinese > temp->next->chinese)
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
                        while (temp != NULL)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("第%d位学生为\n", i);
                            printf("学生的id：%s，学生的姓名：%s，学生的性别：%s，学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                            printf("该学生的班级：%s，该学生的密码：%s，该学生的成绩名次：%d，该学生的总成绩为：%.1f\n", temp->class, temp->code, temp->rank, temp->sum);
                            printf("学生的数学成绩：%.1f，学生的语文成绩：%.1f，学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                            temp = temp->next;
                            i++;
                        }
                        break;
                    case 7:
                        end = NULL;
                        temp = head;
                        while (1)
                        {
                            int flag = 0;
                            while (temp->next != end)
                            {
                                if (temp->english < temp->next->english)
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
                        while (temp != NULL)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("第%d位学生为\n", i);
                            printf("学生的id：%s，学生的姓名：%s，学生的性别：%s，学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                            printf("该学生的班级：%s，该学生的密码：%s，该学生的成绩名次：%d，该学生的总成绩为：%.1f\n", temp->class, temp->code, temp->rank, temp->sum);
                            printf("学生的数学成绩：%.1f，学生的语文成绩：%.1f，学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                            temp = temp->next;
                            i++;
                        }
                        break;
                    case 8:
                        end = NULL;
                        temp = head;
                        while (1)
                        {
                            int flag = 0;
                            while (temp->next != end)
                            {
                                if (temp->english > temp->next->english)
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
                        while (temp != NULL)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("第%d位学生为\n", i);
                            printf("学生的id：%s，学生的姓名：%s，学生的性别：%s，学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                            printf("该学生的班级：%s，该学生的密码：%s，该学生的成绩名次：%d，该学生的总成绩为：%.1f\n", temp->class, temp->code, temp->rank, temp->sum);
                            printf("学生的数学成绩：%.1f，学生的语文成绩：%.1f，学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                            temp = temp->next;
                            i++;
                        }
                        break;
                    case 9:
                        end = NULL;
                        while (1)
                        {
                            temp = head;
                            int flag = 0;
                            while (temp->next != end)
                            {
                                if (temp->rank < temp->next->rank)
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
                        }
                        temp = head;
                        while (temp != NULL)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("第%d位学生为\n", i);
                            printf("学生的id：%s，学生的姓名：%s，学生的性别：%s，学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                            printf("该学生的班级：%s，该学生的密码：%s，该学生的成绩名次：%d，该学生的总成绩为：%.1f\n", temp->class, temp->code, temp->rank, temp->sum);
                            printf("学生的数学成绩：%.1f，学生的语文成绩：%.1f，学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                            temp = temp->next;
                            i++;
                        }
                        break;
                    case 0:
                        end = NULL;
                        temp = head;
                        while (1)
                        {
                            int flag = 0;
                            while (temp->next != end)
                            {
                                if (temp->rank > temp->next->rank)
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
                        while (temp != NULL)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("第%d位学生为\n", i);
                            printf("学生的id：%s，学生的姓名：%s，学生的性别：%s，学生的年龄：%d，\n", temp->username, temp->name, temp->gender, temp->age);
                            printf("该学生的班级：%s，该学生的密码：%s，该学生的成绩名次：%d，该学生的总成绩为：%.1f\n", temp->class, temp->code, temp->rank, temp->sum);
                            printf("学生的数学成绩：%.1f，学生的语文成绩：%.1f，学生的英语成绩：%.1f，\n", temp->math, temp->chinese, temp->english);
                            temp = temp->next;
                            i++;
                        }
                        break;
                    default:
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            else if (sc == 2)
            {
                Administrator *head = NULL;
                Administrator *temp = NULL;
                Administrator *s1 = (Administrator *)malloc(sizeof(Administrator));
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
                while (fread(s1, sizeof(Administrator), 1, file_read) == 1)
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
                    s1 = (Administrator *)malloc(sizeof(Administrator));
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
                sc = 0;
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("请选择你需要的功能！”\n");
                printf("根据指定的管理员信息查询输入“1”      全部显示输入“2”\n");
                printf("退出查询功能输入其它:");
                scanf("%d", &sc);
                if (sc == 1)
                {
                    printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                    printf("请输入要查询的管理员用户名：”\n");
                    scanf("%19s", input);
                    temp = head;
                    while (temp != NULL)
                    {
                        if (strcmp(input, temp->username) == 0)
                        {
                            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                            printf("该管理员的用户名：%s，该管理员的密码：%s", temp->username, temp->code);
                            sc = 1;
                            break;
                        }
                        temp = temp->next;
                    }
                    if (sc == 0)
                    {
                        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                        printf("没有找到该用户名的管理员!\n");
                    }
                }
                else if (sc == 2)
                {
                    i = 1;
                    temp = head;
                    while (temp != NULL)
                    {
                        printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                        printf("第%d位管理员为\n", i);
                        printf("该管理员的用户名：%s，该管理员的密码：%s", temp->username, temp->code);
                        temp = temp->next;
                        i++;
                    }
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
#include "head.h"

void Input(int usergroup) // 录入
{
    int sc = 0;
    printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
    printf("请选择你需要的功能！”\n");
    printf("录入学生信息请输入“1”        录入新管理员请输入“2”\n");
    printf("退出录入功能输入其它:");
    scanf("%d", &sc);
    if (sc == 2)
    {
        Administrator adminuser = {0};
        char input = '0';
        int flag = 0;
        while (1)
        {
            flag = 0;
            FILE *file_read = fopen("Admin.txt", "r");
            if (file_read == NULL)
            {
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("服务器连接失败\n");
                return;
            }
            Administrator admin = {0};
            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
            printf("请输入要录入的用户名：");
            scanf("%s", admin.username);
            while (fread(&adminuser, sizeof(Administrator), 1, file_read) == 1)
            {
                if (strcmp(admin.username, adminuser.username) == 0)
                {
                    printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                    printf("用户名已经存在！\n");
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("请输入密码：");
                scanf("%19s", admin.code);
            }
            FILE *file_write = fopen("Admin.txt", "a");
            if (file_write == NULL)
            {
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("连接服务器失败\n");
                return;
            }
            fwrite(&admin, sizeof(Administrator), 1, file_write);
            fclose(file_write);
            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
            printf("是否继续：（Y/N） \n");
            scanf(" %c", &input);
            if (input == 'n' || input == 'N')
            {
                break;
            }
        }
    }
    else if (sc == 1)
    {
        Student studentuser = {0};
        Student *head = NULL;
        Student *temp = NULL;
        char input = '0';
        int flag = 0;
        while (1)
        {
            flag = 0;
            FILE *file_read = fopen("Students.txt", "r");
            if (file_read == NULL)
            {
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("服务器连接失败\n");
                return;
            }
            Student student = {0};
            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
            printf("请输入要录入的学生学号：");
            scanf("%s", student.username);
            while (fread(&studentuser, sizeof(Student), 1, file_read) == 1)
            {
                if (strcmp(student.username, studentuser.username) == 0)
                {
                    printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                    printf("用户名已经存在！\n");
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("请输入学生的姓名：");
                scanf("%19s", student.name);
                printf("请输入学生的性别：");
                scanf("%9s", student.gender);
                printf("请输入学生的密码：");
                scanf("%19s", student.code);
                printf("请输入学生的班级：");
                scanf("%19s", student.class);
                printf("请输入学生的数学成绩：");
                scanf("%f", &student.math);
                printf("请输入学生的语文成绩：");
                scanf("%f", &student.chinese);
                printf("请输入学生的英语成绩：");
                scanf("%f", &student.english);
                printf("请输入学生的年龄：");
                scanf("%d", &student.age);
            }
            FILE *file_write = fopen("Students.txt", "a");
            if (file_write == NULL)
            {
                printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
                printf("连接服务器失败\n");
                return;
            }
            fwrite(&student, sizeof(Student), 1, file_write);
            fclose(file_write);
            printf("0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#\n");
            printf("是否继续：（Y/N） \n");
            scanf(" %c", &input);
            if (input == 'n' || input == 'N')
            {
                break;
            }
        }
    }
    else
    {
        return;
    }
}
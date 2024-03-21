#include "head.h"

void Validation(char *username, int *usergroup, int *sc) // 验证用户名功能
{
    Student turestudent = {0};
    Administrator tureadmin = {0};
    int i = 1;
    int flag = 0;
    char code[20] = "\0";
    FILE *file_student = fopen("Students.txt", "r");
    if (file_student == NULL)
    {
        printf("连接服务器失败！\n");
        *sc = 1;
        return;
    }
    FILE *file_admin = fopen("Admin.txt", "r");
    if (file_admin == NULL)
    {
        printf("连接服务器失败！\n");
        *sc = 1;
        return;
    }
    while (i != 3)
    {
        flag = 0;
        while (fread(&turestudent, sizeof(Student), 1, file_student) == 1)
        {
            if (strcmp(username, turestudent.username) == 0)
            {
                printf("用户名存在！\n");
                *usergroup = 2;
                flag = 2;
                break;
            }
        }
        rewind(file_student);
        while (fread(&tureadmin, sizeof(Administrator), 1, file_admin) == 1)
        {
            if (strcmp(username, tureadmin.username) == 0)
            {
                printf("用户名存在！\n");
                *usergroup = 1;
                flag = 2;
                break;
            }
        }
        rewind(file_admin);
        if (flag == 2)
        {
            break;
        }
        else
        {
            printf("用户名不存在！\n");
            printf("这是第%d次输入错误，你还有%d次机会\n", i, 3 - i);
            printf("你可以输入“1”重新输入，输入其他退出：");
            scanf("%d", &flag);
            if (flag == 1)
            {
                printf("请输入用户名:");
                scanf("%19s", username);
                i++;
            }
            else
            {
                break;
            }
        }
        if (i == 3)
        {
            printf("错误三次，程序退出!\n");
        }
    }
    if (*usergroup == 2)
    {
        i = 1;
        flag = 0;
        printf("请输入密码：");
        scanf("%19s", code);
        while (i != 3)
        {
            while (fread(&turestudent, sizeof(Student), 1, file_student) == 1)
            {
                if (strcmp(code, turestudent.code) == 0)
                {
                    printf("欢迎登录！\n");
                    flag = 2;
                    break;
                }
                rewind(file_student);
            }
            if (flag == 2)
            {
                break;
            }
            else
            {
                printf("密码不正确！\n");
                printf("这是第%d次输入错误，你还有%d次机会\n", i, 3 - i);
                printf("你可以输入“1”重新输入，输入其他退出：");
                scanf("%d", &flag);
                if (flag == 1)
                {
                    printf("请输入密码:");
                    scanf("%19s", code);
                    i++;
                }
                else
                {
                    *usergroup = 0;
                    break;
                }
            }
            if (i == 3)
            {
                *usergroup = 0;
                printf("错误三次，程序退出!\n");
            }
        }
    }
    else if (*usergroup == 1)
    {
        i = 1;
        flag = 0;
        printf("请输入密码：");
        scanf("%19s", code);
        while (i != 3)
        {
            while (fread(&tureadmin, sizeof(Administrator), 1, file_admin) == 1)
            {
                if (strcmp(code, tureadmin.code) == 0)
                {
                    printf("欢迎登录！\n");
                    flag = 2;
                    break;
                }
            }
            rewind(file_admin);
            if (flag == 2)
            {
                break;
            }
            else
            {
                printf("密码不正确！\n");
                printf("这是第%d次输入错误，你还有%d次机会\n", i, 3 - i);
                printf("你可以输入“1”重新输入，输入其他退出：");
                scanf("%d", &flag);
                if (flag == 1)
                {
                    printf("请输入密码:");
                    scanf("%19s", code);
                    i++;
                }
                else
                {
                    *usergroup = 0;
                    break;
                }
            }
            if (i == 3)
            {
                *usergroup = 0;
                printf("错误三次，程序退出!\n");
            }
        }
    }
    fclose(file_student);
    fclose(file_admin);
}
#include "head.h" //系统初始化

int main()
{
    Administrator *head = NULL;
    Administrator *temp = NULL;
    char input = '0';
    while (1)
    {
        Administrator *admin = (Administrator *)malloc(sizeof(Administrator));
        if(admin == NULL)
        {
            printf("内存分配失败\n");
            return 1;
        }
        printf("请输入用户名：");
        scanf("%s", admin->username);
        printf("请输入密码：");
        scanf("%s", admin->code);
        admin->next = NULL;
        if (head == NULL)
        {
            head = admin;
            temp = admin;
        }
        else
        {
            temp->next = admin;
            temp = admin;
        }
        printf("是否继续输入：（Y/N） \n");
        scanf(" %c", &input);
        if (input == 'n' || input == 'N')
        {
            break;
        }
    }
    FILE *file_write = fopen("admin.txt", "a");
    if (file_write == NULL)
    {
        printf("创建失败\n");
        return 1;
    }
    temp = head;
    while (temp != NULL)
    {
        fprintf(file_write,"用户名：%s\n",temp->username);
        fprintf(file_write,"密码：%s\n",temp->code);
        temp = temp->next;
    }
    fclose(file_write);
    temp = head;
    while (temp != NULL)
    {
        Administrator *Free = temp;
        temp = temp->next;
        free(Free);
    }
    return 0;
}
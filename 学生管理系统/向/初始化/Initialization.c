#include "head.h" //ϵͳ��ʼ��

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
            printf("�ڴ����ʧ��\n");
            return 1;
        }
        printf("�������û�����");
        scanf("%s", admin->username);
        printf("���������룺");
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
        printf("�Ƿ�������룺��Y/N�� \n");
        scanf(" %c", &input);
        if (input == 'n' || input == 'N')
        {
            break;
        }
    }
    FILE *file_write = fopen("admin.txt", "a");
    if (file_write == NULL)
    {
        printf("����ʧ��\n");
        return 1;
    }
    temp = head;
    while (temp != NULL)
    {
        fprintf(file_write,"�û�����%s\n",temp->username);
        fprintf(file_write,"���룺%s\n",temp->code);
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
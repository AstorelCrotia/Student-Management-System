#include "head.h"

void Initialization() // ϵͳ��ʼ����д�볬��
{
    User admin = {0};
    User tureadmin = {0};
    int flag = 0;
    FILE *file_write = fopen("admin.txt", "a");
    if (file_write == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    FILE *file_read = fopen("admin.txt", "r");
    if (file_read == NULL)
    {
        printf("============================\n");
        printf("|  ���ӷ�����ʧ�ܣ�        |\n");
        printf("============================\n");
        return;
    }
    strcpy(admin.uid, "admin");
    while (fscanf(file_read, "�û�����%s  ���룺%s  ��%f\n", tureadmin.uid, tureadmin.code, &tureadmin.balance) != EOF)
    {
        if (strcmp(admin.uid, tureadmin.uid) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        fclose(file_write);
        return;
    }
    strcpy(admin.code, "123");
    fprintf(file_write, "�û�����%s  ���룺%s  ��%.2f\n", admin.uid, admin.code, admin.balance);
    fclose(file_write);
    return;
}
#include "head.h" 

void Initialization()//ϵͳ��ʼ����д�볬��
{
    User admin = {0};
    FILE *file_write = fopen("admin.txt", "w");
    if (file_write == NULL)
    {
        printf("ϵͳ����ʧ��\n");
        return;
    }
    strcpy(admin.uid,"admin");
    strcpy(admin.code,"123");
    fwrite(&admin, sizeof(User), 1, file_write);
    fclose(file_write);
    return;
}
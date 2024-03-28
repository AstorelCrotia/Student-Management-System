#include "head.h" 

void Initialization()//系统初始化，写入超管
{
    User admin = {0};
    FILE *file_write = fopen("admin.txt", "w");
    if (file_write == NULL)
    {
        printf("系统创建失败\n");
        return;
    }
    strcpy(admin.uid,"admin");
    strcpy(admin.code,"123");
    fwrite(&admin, sizeof(User), 1, file_write);
    fclose(file_write);
    return;
}
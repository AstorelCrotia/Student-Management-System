#include "head.h"

char Initialface() //��ʼ����
{
    char username[20] = "0";
    printf("��ӭ��¼ѧ������ϵͳ��\n");
    printf("�������û���:");
    scanf("%s",username);
    return username;
}
#include "head.h"

void InDate(lottery *date)
{
    date->date = time(NULL);
    return;
}

void OutDate(lottery *date)
{
    struct tm *localTime;
    localTime = localtime(&date->date);
    printf("ʱ�䣺�����ʱ��Ϊ��%d-%d-%d %d:%d:%d\n",
           localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
           localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
    return;
}
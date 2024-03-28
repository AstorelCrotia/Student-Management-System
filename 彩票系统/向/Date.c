#include "head.h"

void InbuyDate(lottery *date)
{
    date->buydate = time(NULL);
    return;
}

void InwinDate(lottery *date)
{
    date->windate = time(NULL);
    return;
}

void OutbuyDate(lottery *date)
{
    struct tm *localTime;
    localTime = localtime(&date->buydate);
    printf("ʱ�䣺�����ʱ��Ϊ��%d-%d-%d %d:%d:%d\n",
           localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
           localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
    return;
}

void OutwinDate(lottery *date)
{
    struct tm *localTime;
    localTime = localtime(&date->windate);
    printf("ʱ�䣺�����ʱ��Ϊ��%d-%d-%d %d:%d:%d\n",
           localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
           localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
    return;
}
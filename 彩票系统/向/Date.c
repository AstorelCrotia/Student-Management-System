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
    printf("时间：购买的时间为：%d-%d-%d %d:%d:%d\n",
           localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
           localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
    return;
}
#include "head.h"

void InbuyDate(Lottery *date) 
{
    date->buydate = time(NULL);
    return;
}

void InwinDate(Lottery *date)
{
    date->windate = time(NULL);
    return;
}

void OutbuyDate(Lottery *date)
{
    struct tm *localTime;
    localTime = localtime(&date->buydate);
    printf("时间：购买的时间为：%d-%d-%d %d:%d:%d\n",
           localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
           localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
    return;
}

void OutwinDate(Lottery *date)
{
    struct tm *localTime;
    localTime = localtime(&date->windate);
    printf("时间：购买的时间为：%d-%d-%d %d:%d:%d\n",
           localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
           localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
    return;
}

void didDate(Lottery *date)
{
    struct tm *localTime;
    localTime = localtime(&date->windate);
    snprintf(date->did, sizeof(date->did), "%d-%d-%d", localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday);
    return;
}
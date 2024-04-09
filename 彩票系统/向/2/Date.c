#include "head.h"

void InbuyDate(Lottery *date)
{
    time_t buytime = time(NULL);
    struct tm *localTime;
    localTime = localtime(&buytime);
    snprintf(date->tid, sizeof(date->tid), "%s%d%d%d%d", date->tid, localTime->tm_mday, localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
    snprintf(date->buydate, sizeof(date->buydate), "%d-%d-%d-%d:%d:%d", localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
             localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
    return;
}

void InwinDate(Lottery *date)
{
    time_t buytime = time(NULL);
    struct tm *localTime;
    localTime = localtime(&buytime);
    snprintf(date->windate, sizeof(date->windate), "%d-%d-%d-%d:%d:%d", localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
             localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
    return;
}

void didDate(Lottery *date1, Lottery *date2)
{
    if (strcmp(date2->did, "") == 0)
    {
        time_t buytime = time(NULL);
        struct tm *localTime;
        localTime = localtime(&buytime);
        snprintf(date1->did, sizeof(date1->did), "%d-%d-%d", localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday);
        return;
    }
    else
    {
        strcpy(date1->did, date2->did);
    }
}

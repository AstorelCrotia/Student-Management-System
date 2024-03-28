#include "head.h"

int main()
{
    char id[20];
    int group = 0;
    int sc = 0;
    Initialization();
    Initialface(&sc);
    Mjudgment(&sc,&group,id);
    if (group == 0)
    {
        return 0;
    }
    return 0;
}


    //printf("%d\n",sc);
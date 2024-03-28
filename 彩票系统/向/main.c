#include "head.h"

int main()
{
    char id[20];
    int group = 0;
    int sc = 1;
    Initialization();
    while (sc == 1 || sc == 2)
    {
        Initialface(&sc);
        Mjudgment(&sc, &group, id);
    }
    return 0;
}

// printf("%d\n",sc);
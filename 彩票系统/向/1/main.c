#include "head.h"

int main()
{
    char id[20] = "\0";
    int group = 0;
    int sc = 1;
    Initialization();
    while (1)
    {
        while (sc == 1 || sc == 2)
        {
            Initialface(&sc);
            if (sc == 1 || sc == 2)
            {
                Mjudgment(&sc, &group, id);
            }
            else
            {
                return 0;
            }
        }
        userjudgment(&sc, &group, id);
        Back(&sc);
        if (sc != 1)
        {
            return 0;
        }
    }
    return 0;
}

// printf("%d\n",sc);
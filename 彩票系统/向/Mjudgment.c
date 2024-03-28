#include "head.h"

void Mjudgment(int *sc, int *group, char *id)
{
    switch (*sc)
    {
    case 1:
        Validation(id, group);
        if (*group == 1 || *group == 2)
        {
            *sc = 3;
        }
        break;
    case 2:
        Register();
        break;
    default:
        break;
    }
}
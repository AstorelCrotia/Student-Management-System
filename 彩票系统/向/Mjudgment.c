#include "head.h"

void Mjudgment(int *sc,int *group,char *id)
{
    switch (*sc)
    {
    case 1:
        Validation(id, group);
        break;
    case 2:
        Register();
        break;
    default:
        break;
    }
}
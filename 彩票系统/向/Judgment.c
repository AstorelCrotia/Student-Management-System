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
        Registeruser();
        break;
    default:
        break;
    }
}

void userjudgment(int *sc, int *group, char *id)
{
    if (*group == 1)
    {
        Userface(sc, id);
    }
    else if (*group == 2)
    {
        if (strcmp(id, "admin") == 0)
        {
            while (1)
            {
                Superface(sc);
                if (*sc == 1)
                {
                    Registeradmin();
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            while (*sc != 5)
            {
                Adminface(sc, id);
                switch (*sc)
                {
                case 1:
                    adminQuery(sc);
                    break;
                case 2:
                    adminQuery(sc);
                    break;
                case 3:
                    adminQuery(sc);
                    break;
                case 4:
                    adminQuery(sc);
                    break;
                default:
                    *sc = 5;
                    break;
                }
            }
        }
    }
}
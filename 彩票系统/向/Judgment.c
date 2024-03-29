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
        while (*sc != 6)
        {
            Userface(sc, id);
            switch (*sc)
            {
            case 1:
                break;
            case 2:
                Showuser(id);
                break;
            case 3:
                adminModify(sc);
                break;
            case 4:
                Delete(sc);
                break;
            case 5:
                Delete(sc);
                break;
            default:
                *sc = 6;
                break;
            }
        }
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
                    break;
                case 2:
                    adminQuery(sc);
                    break;
                case 3:
                    adminModify(sc);
                    break;
                case 4:
                    Delete(sc);
                    break;
                default:
                    *sc = 5;
                    break;
                }
            }
        }
    }
}

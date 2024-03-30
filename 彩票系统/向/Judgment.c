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
        while (*sc != 7)
        {
            Userface(sc, id);
            switch (*sc)
            {
            case 1:
                Buy(sc,id);
                *sc = 0;
                break;
            case 2:
                userQuery(sc, id);
                *sc = 0;
                break;
            case 3:
                usermoneyModify(id, 1);
                *sc = 0;
                break;
            case 4:
                usermoneyModify(id, 2);
                *sc = 0;
                break;
            case 5:
                usercodeModify(id);
                *sc = 0;
                break;
            default:
                *sc = 7;
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
                    *sc = 0;
                    break;
                case 2:
                    adminQuery(sc);
                    *sc = 0;
                    break;
                case 3:
                    adminModify(sc);
                    *sc = 0;
                    break;
                case 4:
                    Delete(sc);
                    *sc = 0;
                    break;
                default:
                    *sc = 5;
                    break;
                }
            }
        }
    }
}

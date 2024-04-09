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
    *sc = 0;
    if (*group == 1)
    {
        while (*sc != 7)
        {
            Userface(sc, id);
            switch (*sc)
            {
            case 1:
                Buy(sc, id);
                break;
            case 2:
                userQuery(sc, id);
                break;
            case 3:
                usermoneyModify(id, 1);
                break;
            case 4:
                usermoneyModify(id, 2);
                break;
            case 5:
                usercodeModify(id);
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
                    winlottery(sc);
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

#include "head.h"

int main()
{
    Student s1 = {0};
    char username[20] = "0";
    int usergroup = 0;
    int sc = 0;
    Initialface(username);
    Validation(username);
    Interface(usergroup,username);
    switch (sc)
    {
    case 1:
        Input(usergroup,username);
        break;
    case 2:
        Query(s1);
        break;
    case 3:
        Modify(usergroup,username);
        break;
    case 4:
        Delete(usergroup,username);
        break;
    default:
        break;
    }
}
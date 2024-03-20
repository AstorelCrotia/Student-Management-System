#include "head.h"

int main()
{
    Student s1 = {0};
    char username[20] = "0";
    int usergroup = 0;
    int sc = 0;
    Initialface(&username);
    Validation(&username,&usergroup,&sc);
    if(sc == 1 && usergroup != 0)
    {
        return 0;
    }
    Interface(username,usergroup,&sc);
    return 0;
}
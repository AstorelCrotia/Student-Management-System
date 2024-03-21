#include "head.h"

int main()
{
    Student s1 = {0};
    char username[20] = "0";
    int usergroup = 0;
    int sc = 0;
    int flag = 0;
    Initialface(&username);
    Validation(&username,&usergroup,&sc,&flag);
    if(sc == 1 && usergroup != 0)
    {
        return 0;
    }
    Interface(usergroup,username,&sc);
    return 0;
}
#include "head.h"

int main()
{
    Student s1 = {0};
    Student* head = createlist();
    char username[20] = "0";
    int usergroup = 0;
    int sc = 0;
    Initialface(username);
    Validation(username,usergroup);
    Interface(username,usergroup,sc);
    switch (sc)
    {
    case 1:
        Input();
        break;
    case 2:
        Query(s1);
        break;
    case 3:
        Modify();
        break;
    case 4:
        Delete();
        break;
    default:
        break;
    }
}
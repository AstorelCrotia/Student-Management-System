#include "head.h"

int main()
{
    Initialization();
    char id[20];
    int group = 0;
    Initialface(id);
    Validation(id, &group);
    if (group == 0)
    {
        return 0;
    }
    return 0;
}
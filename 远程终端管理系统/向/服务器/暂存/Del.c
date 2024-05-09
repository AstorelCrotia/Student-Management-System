#include "head.h"

void DelUL(int user, struct sockaddr_in *addr) // 删除客户端链表
{
    UL *p = ULhead;
    UL *prev = NULL;
    while (p != NULL)
    {
        if (user == p->user)
        {
            break;
        }
        prev = p;
        p = p->next;
    }
    if (p == NULL)
    {
        return;
    }
    if (prev == NULL)
    {
        ULhead = p->next;
    }
    else
    {
        prev->next = p->next;
    }
    free(p);
    p = NULL;
}

void DelUD(char *user) // 删除用户链表
{
    UD *p = UDhead;
    UD *prev = NULL;
    while (p != NULL)
    {
        if (strcmp(user, p->uid))
        {
            break;
        }
        prev = p;
        p = p->next;
    }
    if (p == NULL)
    {
        return;
    }
    if (prev == NULL)
    {
        UDhead = p->next;
    }
    else
    {
        prev->next = p->next;
    }
    free(p);
    p = NULL;
}
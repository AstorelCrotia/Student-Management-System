#include "head.h"

void Userin(int user, struct sockaddr_in *addr, UL *ULhead) // 创建客户端链表
{
    UL *new = calloc(1, sizeof(UL));
    if (new == NULL)
    {
        Login();
        printf("内存分配失败\n");
        Logout();
        return;
    }
    new->user = user;
    new->addr = *addr;
    new->len = sizeof(new->addr);
    new->next = NULL;
    if (ULhead == NULL)
    {
        ULhead = new;
    }
    else
    {
        new->next = ULhead;
        ULhead = new;
    }
}

void UserDT(int user, struct sockaddr_in *addr, UD *UDhead) // 创建账户链表
{
    UD *new = calloc(1, sizeof(UD));
    if (new == NULL)
    {
        Login();
        printf("内存分配失败\n");
        Logout();
        return;
    }
    strcat(new->uid, "");
    strcat(new->code, "");
    new->next = NULL;
    if (UDhead == NULL)
    {
        UDhead = new;
    }
    else
    {
        new->next = UDhead;
        UDhead = new;
    }
}
#include "head.h"

void scan(Student *s1, )
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("请输入第%d位学生的姓名：", i + 1);
        scanf("%s", arr[i].name);
        printf("请输入第%d位学生的年龄：", i + 1);
        scanf("%d", &arr[i].age);
        printf("请输入第%d位学生的学号：", i + 1);
        scanf("%d", &arr[i].id);
    }
}
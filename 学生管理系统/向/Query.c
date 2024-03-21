#include "head.h"

int Query(Student s1) //查询
{
    printf("学生的id：%d，学生的姓名：%s，学生的性别：%s，学生的年龄：%d，\n",s1.id,s1.name,s1.gender,s1.age);
    printf("学生的密码：%d，学生的班级：%s，学生的成绩名次：%d，\n",s1.code,s1.class,s1.rank);
    printf("学生的数学成绩：%d，学生的语文成绩：d，学生的英语成绩：d，\n",s1.math,s1.chinese,s1.english);
}
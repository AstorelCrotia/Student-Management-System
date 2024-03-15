#include<stdio.h>
#include<string.h>

typedef struct
{
    char id[20];
    char name[20];
    char gender[10];
    int code[20];
    char class[20];
    int math;
    int chinese;
    int english;
    int age;
    int rank;
} Student;

typedef struct
{
    char username[20];
    int code[20];
} Administrator;

char Initialface();
void Validation(int username);
int Interface(int usergroup,char username);
int Input(int usergroup,char username);
int Query(Student s1);
int Modify(int usergroup,char username);
int Delete(int usergroup,char username);


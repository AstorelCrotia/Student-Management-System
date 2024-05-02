#include <windows.h>
#include <stdio.h>

// 定义学生信息结构
typedef struct Student {
    char name[50];
    int id;
    float score;
    struct Student* next;
} Student;

// 遍历学生链表并输出内容到MessageBox
void traverseStudentList(Student* head) {
    Student* current = head;
    char message[1000] = "";  // 用于存储学生信息的字符串

    while (current != NULL) {
        char temp[100];
        sprintf(temp, "姓名：%s，学号：%d，成绩：%.2f\n", current->name, current->id, current->score);
        strcat(message, temp);
        current = current->next;
    }

    MessageBox(NULL, message, "学生信息", MB_OK);  // 弹出MessageBox显示学生信息
}

int main() {
    // 创建一个简单的学生链表
    Student* head = (Student*)malloc(sizeof(Student));
    Student* student1 = (Student*)malloc(sizeof(Student));
    Student* student2 = (Student*)malloc(sizeof(Student));

    strcpy(head->name, "张三");
    head->id = 1001;
    head->score = 85.5;
    head->next = student1;

    strcpy(student1->name, "李四");
    student1->id = 1002;
    student1->score = 78.9;
    student1->next = student2;

    strcpy(student2->name, "王五");
    student2->id = 1003;
    student2->score = 92.0;
    student2->next = NULL;

    traverseStudentList(head);  // 遍历学生链表并输出到MessageBox

    // 释放学生链表内存
    free(student2);
    free(student1);
    free(head);

    return 0;
}
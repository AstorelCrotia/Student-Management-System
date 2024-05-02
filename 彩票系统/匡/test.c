#include <windows.h>
#include <stdio.h>

// ����ѧ����Ϣ�ṹ
typedef struct Student {
    char name[50];
    int id;
    float score;
    struct Student* next;
} Student;

// ����ѧ������������ݵ�MessageBox
void traverseStudentList(Student* head) {
    Student* current = head;
    char message[1000] = "";  // ���ڴ洢ѧ����Ϣ���ַ���

    while (current != NULL) {
        char temp[100];
        sprintf(temp, "������%s��ѧ�ţ�%d���ɼ���%.2f\n", current->name, current->id, current->score);
        strcat(message, temp);
        current = current->next;
    }

    MessageBox(NULL, message, "ѧ����Ϣ", MB_OK);  // ����MessageBox��ʾѧ����Ϣ
}

int main() {
    // ����һ���򵥵�ѧ������
    Student* head = (Student*)malloc(sizeof(Student));
    Student* student1 = (Student*)malloc(sizeof(Student));
    Student* student2 = (Student*)malloc(sizeof(Student));

    strcpy(head->name, "����");
    head->id = 1001;
    head->score = 85.5;
    head->next = student1;

    strcpy(student1->name, "����");
    student1->id = 1002;
    student1->score = 78.9;
    student1->next = student2;

    strcpy(student2->name, "����");
    student2->id = 1003;
    student2->score = 92.0;
    student2->next = NULL;

    traverseStudentList(head);  // ����ѧ�����������MessageBox

    // �ͷ�ѧ�������ڴ�
    free(student2);
    free(student1);
    free(head);

    return 0;
}
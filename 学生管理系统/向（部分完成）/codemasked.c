#include <stdio.h>
#include <conio.h>

int main() {
    char password[20];
    int i = 0;
    char ch;

    printf("���������룺");
    
    // ������������ʾΪ*
    while(1) {
        ch = getch(); // ��ȡ�������룬������ʾ����Ļ��
        if (ch == '\r') { // �س�����������
            password[i] = '\0'; // ���ַ�����β����Ϊ'\0'
            break;
        } else if (ch == '\b' && i > 0) { // �����˸��
            i--;
            printf("\b \b"); // ɾ��һ���ַ�
        } else {
            password[i] = ch;
            i++;
            printf("*"); // ��ʾ*
        }
    }

    printf("\n����������ǣ�%s\n", password);

    return 0;
}
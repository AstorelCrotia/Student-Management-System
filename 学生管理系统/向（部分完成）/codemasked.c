#include <stdio.h>
#include <conio.h>

int main() {
    char password[20];
    int i = 0;
    char ch;

    printf("请输入密码：");
    
    // 将输入内容显示为*
    while(1) {
        ch = getch(); // 读取键盘输入，但不显示在屏幕上
        if (ch == '\r') { // 回车键结束输入
            password[i] = '\0'; // 将字符串结尾设置为'\0'
            break;
        } else if (ch == '\b' && i > 0) { // 处理退格键
            i--;
            printf("\b \b"); // 删除一个字符
        } else {
            password[i] = ch;
            i++;
            printf("*"); // 显示*
        }
    }

    printf("\n输入的密码是：%s\n", password);

    return 0;
}
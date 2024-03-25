#include "head.h"
void gotXY(int x,int y){
	//更新光标位置
	COORD pos;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);//GetStdHandle是一个Windows API函数。
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOutput, pos);
}
int posx(){
	CONSOLE_SCREEN_BUFFER_INFO ptr;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ptr);
	return (ptr.dwCursorPosition.X);
}
 
int posy(){
	CONSOLE_SCREEN_BUFFER_INFO ptr;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ptr);
	return (ptr.dwCursorPosition.Y);
}
 
 
void GetPasscode(char* pwd){
	int i = 0;
	int x, y;
	while (1){
		pwd[i] = getch();//获取单个密码（字符）
		if (pwd[i] == VK_BACK && i >= 0)//如果输入的是回退键，VK_BACK是键盘的键值，ASCII码值为8
		{
			if (i > 0)//i>0说明有输入东西了，则回退前一格
			{
				i--;
				x = posx() - 1;//定位x并回退一格
				y = posy();//定位y
				gotXY(x, y);//定位光标
				printf(" ");//将*用空格掩盖
				x = posx() - 1;//再次回退，下次输入时光标才会显示在正确的位置
				y = posy();//定位y
				gotXY(x, y);
				continue;//然后跳过此次循环
			}
			else if (i == 0)//i==0说明没输入东西，直接跳过此次循环即可
			{
				continue;
			}
		}
		if (i >= 0 && pwd[i] != VK_RETURN && pwd[i] != VK_BACK)//输入东西了
		{
			x = posx();
			y = posy();
			gotXY(x, y);
			printf("*");
		}
		if (i == 0 && pwd[i] == VK_RETURN)//如果没输入东西直接按回车，直接跳过此次循环，避免程序把回车当密码了
		{
			continue;
		}
		if (pwd[i] == VK_RETURN||i==18)//输入回车了或者到上限了
		{
			pwd[i] = '\0';//结尾放'\0'
			break;
		}
		i++;
	}
}
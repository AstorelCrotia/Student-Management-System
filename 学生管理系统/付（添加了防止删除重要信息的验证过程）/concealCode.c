#include "head.h"
void gotXY(int x,int y){
	//���¹��λ��
	COORD pos;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);//GetStdHandle��һ��Windows API������
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
		pwd[i] = getch();//��ȡ�������루�ַ���
		if (pwd[i] == VK_BACK && i >= 0)//���������ǻ��˼���VK_BACK�Ǽ��̵ļ�ֵ��ASCII��ֵΪ8
		{
			if (i > 0)//i>0˵�������붫���ˣ������ǰһ��
			{
				i--;
				x = posx() - 1;//��λx������һ��
				y = posy();//��λy
				gotXY(x, y);//��λ���
				printf(" ");//��*�ÿո��ڸ�
				x = posx() - 1;//�ٴλ��ˣ��´�����ʱ���Ż���ʾ����ȷ��λ��
				y = posy();//��λy
				gotXY(x, y);
				continue;//Ȼ�������˴�ѭ��
			}
			else if (i == 0)//i==0˵��û���붫����ֱ�������˴�ѭ������
			{
				continue;
			}
		}
		if (i >= 0 && pwd[i] != VK_RETURN && pwd[i] != VK_BACK)//���붫����
		{
			x = posx();
			y = posy();
			gotXY(x, y);
			printf("*");
		}
		if (i == 0 && pwd[i] == VK_RETURN)//���û���붫��ֱ�Ӱ��س���ֱ�������˴�ѭ�����������ѻس���������
		{
			continue;
		}
		if (pwd[i] == VK_RETURN||i==18)//����س��˻��ߵ�������
		{
			pwd[i] = '\0';//��β��'\0'
			break;
		}
		i++;
	}
}
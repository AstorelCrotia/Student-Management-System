
/***************************************
*��  �ܣ�	�˵����
*˵  ����	���в˵�����������menu_open
****************************************/

#include"fun.h"

/*---------��ӭ�˵�------------------*/
void menu_build()
{
	char *address ="char_menu/menu_build.txt";
	menu_open(address);
}
/*---------���˵�------------------*/
void main_menu()
{
	//char *address ="char_menu/main_menu.txt";
	char *address ="char_menu/main_menu_ht.txt";
	menu_open(address);
}
/*---------����Ա��¼�Ӳ˵�----------*/
void menu1()
{
	char *address ="char_menu/menu1.txt";
	menu_open(address);
}

/*---------�����¼�Ӳ˵�------------*/
void menu2()
{
	char *address ="char_menu/menu2.txt";
	menu_open(address);
}

/*---------menu21�û���Ʊ�Ӳ˵�--------*/
void menu21()
{
	printf("\n\t\t���˵�>>�����¼>>��Ʊ\n");
	printf("\t\t----------------------------\n");
	printf("\t\t   ----> ��%d �ڲ�Ʊ <----\n",ticketdayth);
	printf("\t\t----------------------------\n");
	printf("\t\t1-> �� �� �� Ʊ\n");
	printf("\t\t2-> �� �� �� Ʊ\n");
	printf("\t\t3-> �� �� �� Ʊ\n\n");
	printf("\t\t0-> �� �� �� һ ��\n");
	printf("\t\t-------------------------------\n\n");
	printf("��ѡ��-->");
}

/*---------menu23�޸��û�������Ϣ�Ӳ˵�--------*/
void menu23()
{
	char *address ="char_menu/menu23.txt";
	menu_open(address);
}

/*---------menu1�鿴��Ϣ�Ӳ˵�----------------*/
void menu12()
{
	char *address ="char_menu/menu12.txt";
	menu_open(address);
}
/*---------menu1�޸���Ϣ�Ӳ˵�----------------*/
void menu13()
{
	char *address ="char_menu/menu13.txt";
	menu_open(address);
}

/*---------menu131�޸Ĺ���Ա��Ϣ�Ӳ˵�----------*/
void menu131()
{
	printf("\n\t\t���˵�>>����Ա��¼>>�޸���Ϣ\n");
	printf("\t\t>>�޸Ĺ���Ա��Ϣ\n");
	printf("\t\t----------------------------\n");
	printf("\t\t1-> �� �� �� ��\n");
	printf("\t\t2-> �� �� �� ��\n");
	printf("\t\t3-> �� �� �� �� �� ��\n\n");
	printf("\t\t0-> �� �� �� һ ��\n");
	printf("\t\t-------------------------------\n\n");
	printf("��ѡ��-->");
}

/*---------menu1ɾ����Ϣ�Ӳ˵�------------------*/
void menu14()
{
	char *address ="char_menu/menu14.txt";
	menu_open(address);
}

/*---------menu1������Ϣ�Ӳ˵�------------------*/
void menu15()
{
	char *address ="char_menu/menu15.txt";
	menu_open(address);
}

/*---------���������ʾ�Ӳ˵�------------------*/
void key_error()
{
	char *address ="char_menu/key_error.txt";
	menu_open(address);
}
/*---------ע��ɹ���ʾ�Ӳ˵�------------------*/
void apply_success()
{
	char *address ="char_menu/apply_success.txt";
	menu_open(address);
}

/*---------�˳���л�Ӳ˵�------------------*/
void thanks()
{
	char *address ="char_menu/thanks.txt";
	menu_open(address);
}
/*---------ϵͳҡ���Ӳ˵�------------------*/
void luck_draw()
{
	char *address ="char_menu/luck_draw.txt";
	menu_open(address);
}
/*---------�йغ�ͬ----------------------*/
void ht()
{
	char *address ="char_menu/ht.txt";
	menu_open(address);
}
/*---------�ܽ�1---�ṹ��˵��---------------*/
void summary1()
{
	char *address ="char_menu/summary1.txt";
	menu_open(address);
}

/*---------�ܽ�2--�˵����----------------*/
void summary2()
{
	char *address ="char_menu/summary2.txt";
	menu_open(address);
}

/*---------�ļ����Ӻ���------------------*/
void menu_open(char *address)
{
	FILE *fp;
	if((fp = fopen(address,"rt"))==NULL)
	{
		printf("���ļ�ʧ�ܣ�");
		exit(0);
	}
	while(!feof(fp))
	{
		printf("%c",fgetc(fp));
	}
	fclose(fp);
	printf("��ѡ��-->");
}

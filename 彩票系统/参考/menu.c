
/***************************************
*功  能：	菜单相关
*说  明：	所有菜单函数均调用menu_open
****************************************/

#include"fun.h"

/*---------欢迎菜单------------------*/
void menu_build()
{
	char *address ="char_menu/menu_build.txt";
	menu_open(address);
}
/*---------主菜单------------------*/
void main_menu()
{
	//char *address ="char_menu/main_menu.txt";
	char *address ="char_menu/main_menu_ht.txt";
	menu_open(address);
}
/*---------管理员登录子菜单----------*/
void menu1()
{
	char *address ="char_menu/menu1.txt";
	menu_open(address);
}

/*---------彩民登录子菜单------------*/
void menu2()
{
	char *address ="char_menu/menu2.txt";
	menu_open(address);
}

/*---------menu21用户购票子菜单--------*/
void menu21()
{
	printf("\n\t\t主菜单>>彩民登录>>购票\n");
	printf("\t\t----------------------------\n");
	printf("\t\t   ----> 第%d 期彩票 <----\n",ticketdayth);
	printf("\t\t----------------------------\n");
	printf("\t\t1-> 体 育 彩 票\n");
	printf("\t\t2-> 慈 善 彩 票\n");
	printf("\t\t3-> 救 灾 彩 票\n\n");
	printf("\t\t0-> 返 回 上 一 级\n");
	printf("\t\t-------------------------------\n\n");
	printf("请选择-->");
}

/*---------menu23修改用户个人信息子菜单--------*/
void menu23()
{
	char *address ="char_menu/menu23.txt";
	menu_open(address);
}

/*---------menu1查看信息子菜单----------------*/
void menu12()
{
	char *address ="char_menu/menu12.txt";
	menu_open(address);
}
/*---------menu1修改信息子菜单----------------*/
void menu13()
{
	char *address ="char_menu/menu13.txt";
	menu_open(address);
}

/*---------menu131修改管理员信息子菜单----------*/
void menu131()
{
	printf("\n\t\t主菜单>>管理员登录>>修改信息\n");
	printf("\t\t>>修改管理员信息\n");
	printf("\t\t----------------------------\n");
	printf("\t\t1-> 修 改 姓 名\n");
	printf("\t\t2-> 修 改 密 码\n");
	printf("\t\t3-> 修 改 奖 池 金 额\n\n");
	printf("\t\t0-> 返 回 上 一 级\n");
	printf("\t\t-------------------------------\n\n");
	printf("请选择-->");
}

/*---------menu1删除信息子菜单------------------*/
void menu14()
{
	char *address ="char_menu/menu14.txt";
	menu_open(address);
}

/*---------menu1排序信息子菜单------------------*/
void menu15()
{
	char *address ="char_menu/menu15.txt";
	menu_open(address);
}

/*---------密码错误提示子菜单------------------*/
void key_error()
{
	char *address ="char_menu/key_error.txt";
	menu_open(address);
}
/*---------注册成功提示子菜单------------------*/
void apply_success()
{
	char *address ="char_menu/apply_success.txt";
	menu_open(address);
}

/*---------退出感谢子菜单------------------*/
void thanks()
{
	char *address ="char_menu/thanks.txt";
	menu_open(address);
}
/*---------系统摇奖子菜单------------------*/
void luck_draw()
{
	char *address ="char_menu/luck_draw.txt";
	menu_open(address);
}
/*---------有关海同----------------------*/
void ht()
{
	char *address ="char_menu/ht.txt";
	menu_open(address);
}
/*---------总结1---结构体说明---------------*/
void summary1()
{
	char *address ="char_menu/summary1.txt";
	menu_open(address);
}

/*---------总结2--菜单框架----------------*/
void summary2()
{
	char *address ="char_menu/summary2.txt";
	menu_open(address);
}

/*---------文件打开子函数------------------*/
void menu_open(char *address)
{
	FILE *fp;
	if((fp = fopen(address,"rt"))==NULL)
	{
		printf("打开文件失败！");
		exit(0);
	}
	while(!feof(fp))
	{
		printf("%c",fgetc(fp));
	}
	fclose(fp);
	printf("请选择-->");
}

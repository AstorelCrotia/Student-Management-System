#include "head.h"
#include <time.h>

int main()
{
    len = 0;
    len_buy = 0;
    len_user = 0;

    struct Person *p = NULL, *h = NULL;
    FILE *fp;
    h = person_creat_head(h);
    if ((fp = fopen("user.txt", "rt")) == NULL)
    {
        p = h;
    }
    else
    {
        fclose(fp);
        p = r_user_file(h);
    }

    struct buy_ticket *buy_h=NULL,*buy_p=NULL;
    buy_h=buy_creat_head(buy_h);
    buy_p=buy_h;
    if((fp=fopen("buy.txt","rt"))==NULL)
    {
        buy_p=buy_h;
    }
    else
    {
        fclose(fp);
        buy_p=r_buy_file(buy_h);
    }

    int visit;
    if((fp=fopen("buy.txt","rt"))==NULL)
    {
        visit =0;
    }
    else
    {
        fclose(fp);
        visit = r_visit_file();
    }
    visit++;
    w_visit_file(visit);
    printf("*********��ӭ����һҹ���������Ʊ��*********\n");
    printf("******��ӭ���٣����ǽ����%dλ�ÿ�**********\n");
    time_t start,end;
    double dif;
    time(&start);
    while(dif<5)
    {
        time(&end);
        dif=difftime(end,start);
    }
    while(1)
	{
		ticketdayth = buy_h->ticket_dayth;	//ͷ�ڵ��dayth�����ںţ�������Թ�����ں�
		printf("1������Ա��¼\t2�������½\t3���û�ע��\t4���˳�ϵͳ\n");
		scanf("%d",&choice);
		getchar();							//��ֹ�����ַ�ʱ������ѭ��
		switch(choice)
		{
			case 0:							
					if(save_flag ==1)
					{
						printf("��Ϣ���ģ��Ƿ񱣴浽�ļ���y/n\n");
						if(getchar() == 'y')
						{
							w_user_file(h);		
						}

					}
						w_buy_file(buy_h);		
						printf("��ӭ����ף���鸣���죡\n");				
					exit(0);
				break;
			case 1:								
					admin_signin(h,buy_h);							
				break;
			case 2:								
					buy_p = signin(h,buy_p,buy_h);	
				break;
			case 3:								
					p = signup(h,p);
				break;	
			default:
				printf("ѡ����Ч����������ز˵���\n");
				getchar();
				break;
		}
		choice = 9;						//����������������û�û�����֣������default
	}
    return 0;
}
#include "head.h"
#include <time.h>

int main()
{
    len = 0;      // �û�ID
    len_buy = 0;  // ��Ʊ��Ϣ����,�û�����
    len_user = 0; // �û�����

    //----------�û�ע���ļ��Ƿ����--------
    struct person *p = NULL, *H = NULL;
    FILE *fp;
    H = person_creat_head(H);
    if ((fp = fopen("user.txt", "rt")) == NULL) // �ļ�������
    {
        p = H;
    }
    else
    {
        fclose(fp);         // ���ڶ�֮ǰ
        p = r_user_file(H); // �ļ������ȶ�ȡ����
    }

    //---------���¹����Ʊ��Ϣ�ļ��Ƿ����------
    struct buy_ticket *buy_H = NULL, *buy_p = NULL;
    buy_H = buy_creat_head(buy_H);
    buy_p = buy_H;
    if ((fp = fopen("buy.txt", "rt")) == NULL) // �ļ�������
    {
        buy_p = buy_H;
    }
    else
    {
        fclose(fp);
        buy_p = r_buy_file(buy_H); // �ļ������ȶ�ȡ����
    }
    /*----------���Ϲ����Ʊ��Ϣ----------------*/

    /*----------���´�ŷÿ͸���-----------------*/
    int visit;
    if ((fp = fopen("buy.txt", "rt")) == NULL) // �ļ�������
    {
        visit = 0;
    }
    else
    {
        fclose(fp);
        visit = r_visit_file(); // �ļ������ȶ�ȡ����
    }
    visit++; // �ÿ�������1
    w_visit_file(visit);
    /*------------���ϴ�ŷÿ͸���-------------*/

    menu_build(); // ��ӭ����
    printf("****���ǵ� %d λ�ÿͣ�****\n", visit);
    /*------��-��ʱ����-------------*/
    time_t start, end; // ����ʱ�俪ʼ�����
    double dif;
    time(&start);
    while (dif < 5) // ʱ��С��5sһֱ��ѭ��
    {
        time(&end);
        dif = difftime(end, start);
    }
    /*------��-��ʱ����-------------*/
    //	getchar();
    while (1)
    {
        ticketdayth = buy_H->ticket_dayth; // ͷ�ڵ��dayth�����ںţ�������Թ�����ں�
        main_menu();
        scanf("%d", &menu_select);
        getchar(); // ��ֹ�����ַ�ʱ������ѭ��
        switch (menu_select)
        {
        case 0: // ����ʾ����
            if (save_flag == 1)
            {
                printf("��Ϣ���ģ��Ƿ񱣴浽�ļ���y/n\n");
                if (getchar() == 'y')
                {
                    w_user_file(H); // �û���Ϣд���ļ�
                }
            }
            w_buy_file(buy_H); // ��Ʊ��Ϣд���ļ�
            thanks();          // �˳���л�Ӳ˵�
            exit(0);
            break;
        case 1: // ����Ա��¼
            admin_menu1(H, buy_H);
            break;
        case 2:                                    // �����¼
            buy_p = person_menu2(H, buy_p, buy_H); // �ѹ�Ʊ���һ���ڵ�ĵ�ַ���ص���
            break;
        case 3: // �û�ע��
            p = add_user(H, p);
            break;
        case 4:
            printf("�˳�ϵͳ...\n");
            thanks();
            break;
        default:
            printf("\n ѡ��������������ز˵���\n");
            getchar();
            break;
        }
        menu_select = 9; // ����������������û�û�����֣������default
    }
    return 0;
}

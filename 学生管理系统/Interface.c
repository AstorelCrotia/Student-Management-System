#include "head.h"

int Interface(int usergroup,char username) //����
{
    int sc = 0;
    if(usergroup == 1)
    {
        printf("��ӭ����Ա%s��¼ѧ������ϵͳ��\n",username);
        printf("��ѡ������Ҫ�Ĺ��ܣ���\n");
        printf("¼��ѧ����Ϣ���롰1��        ����ѧ����Ϣ���롰2��\n");
        printf("�޸�ѧ����Ϣ���롰3��        ɾ��ѧ����Ϣ���롰4��\n");
        printf("�˳�����ϵͳ�������������ַ�\n");
        scanf("%d",&sc);
    }
    else
    {
        printf("��ӭѧ��%s��¼ѧ������ϵͳ��\n",username);
        printf("��ѡ������Ҫ�Ĺ��ܣ���\n");
        printf("��ѯ��Ϣ���롰1��        �޸��������롰2��\n");
        printf("�˳�����ϵͳ�������������ַ�\n");
        scanf("%d",&sc);
    }
    return sc;
}
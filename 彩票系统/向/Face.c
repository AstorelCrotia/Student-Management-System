#include "head.h"

void Initialface(int *sc) //��ʼ����
{
    printf("============================\n");
    printf("|  ��ӭ��¼��Ʊϵͳ��      |\n");
    printf("|                          |\n");
    printf("|  ��ѡ������Ҫ�Ĺ��ܣ�    |\n");
    printf("|                          |\n");
    printf("|  �����˻���¼���롰1��     |\n");
    printf("|                          |\n");
    printf("|  ע���˻����롰2��         |\n");
    printf("|                          |\n");
    printf("|  �˳�ϵͳ��������        |\n");
    printf("============================\n");
    printf("������룺");
    scanf(" %d",sc);
}

void Userface(int *sc,char *id) //�û�����
{
    printf("====================================\n");
    printf("|  ��ӭ�û���%s��¼��Ʊϵͳ��      |\n",id);
    printf("|                                |\n");
    printf("|  ��ѡ������Ҫ�Ĺ��ܣ�          |\n");
    printf("|                                |\n");
    printf("|  �����Ʊ���롰1��               |\n");
    printf("|                                |\n");
    printf("|  ��ѯ��Ϣ���롰2��               |\n");
    printf("|                                |\n");
    printf("|  ��ȡ������롰3��               |\n");
    printf("|                                |\n");
    printf("|  ��ֵ������롰4��               |\n");
    printf("|                                |\n");
    printf("|  �޸��������롰5��               |\n");
    printf("|                                |\n");
    printf("|  �˳�ϵͳ��������              |\n");
    printf("====================================\n");
    printf("������룺");
    scanf("%d",sc);
}

void Adminface(int *sc,char *id) //����Ա����
{
    printf("====================================\n");
    printf("|  ��ӭ�û���%s��¼��Ʊϵͳ��      |\n",id);
    printf("|                                |\n");
    printf("|  ��ѡ������Ҫ�Ĺ��ܣ�          |\n");
    printf("|                                |\n");
    printf("|  ��Ʊ�������롰1��               |\n");
    printf("|                                |\n");
    printf("|  ��ѯ��Ϣ���롰2��               |\n");
    printf("|                                |\n");
    printf("|  �޸���Ϣ���롰3��               |\n");
    printf("|                                |\n");
    printf("|  ɾ����Ϣ���롰4��               |\n");
    printf("|                                |\n");
    printf("|  �˳�ϵͳ��������              |\n");
    printf("====================================\n");
    printf("������룺");
    scanf("%d",sc);
}

void Superface(int *sc) //���ܽ���
{
    printf("============================\n");
    printf("|  ��ӭ���ܵ�¼��Ʊϵͳ��   |\n");
    printf("|                          |\n");
    printf("|  ��ѡ������Ҫ�Ĺ��ܣ�    |\n");
    printf("|                          |\n");
    printf("|  ¼���¹������롰1��       |\n");
    printf("|                          |\n");
    printf("|  �˳�ϵͳ��������        |\n");
    printf("============================\n");
    printf("������룺");
    scanf(" %d",sc);
}
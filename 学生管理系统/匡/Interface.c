#include "head.h"

void InterfaceAdmin(int usergroup,Administratorlist *admin,StudentList *student) //����
{
    if(usergroup == 1){
        supAdminFunc(admin,student);
    }
    if(usergroup == 2)
    {
        AdminFunc(student);
    }
}
void InterfaceStudent(StudentList *student,char *name){
    studentFunc(student,name);
}
void supAdminFunc(Administratorlist *admin,StudentList *student){
    int sc=0;
    printf("��ӭ��������Ա��¼ѧ������ϵͳ��\n");
    while(1)
    {
        printf("************************************\n");
        printf("���������Ϣ���롰1��        ¼��ѧ����Ϣ���롰2��\n");
        printf("��ѯѧ����Ϣ���롰3��        �޸�ѧ����Ϣ���롰4��\n");
        printf("ɾ��ѧ����Ϣ���롰5��        �˳�����ϵͳ���롰6��\n");
        scanf("%d",&sc);
        switch (sc)
        {
        case 1:InputAdmin(admin);
            break;
        case 2:InputStu(student);
            break;
        case 3:QueryStu(student);
            break;
        case 4:ModifyStu(student);
            break;
        case 5:Delete(student);
            break;
        case 6:exit(1);
        default:
            break;
        }
    }
}
void AdminFunc(StudentList *student){
    int sc=0;
    printf("��ӭ����Ա��¼ѧ������ϵͳ��\n");
    while(1){
        printf("************************************\n");
        printf("¼��ѧ����Ϣ���롰1��        ��ѯѧ����Ϣ���롰2��\n");
        printf("�޸�ѧ����Ϣ���롰3��        ɾ��ѧ����Ϣ���롰4��\n");
        printf("�˳�����ϵͳ���롰5��\n");
        printf("��ѡ������Ҫ�Ĺ��ܣ�");
        scanf("%d",&sc);
        switch (sc)
        {
        case 1:InputStu(student);
            break;
        case 2:QueryStu(student);
            break;
        case 3:ModifyStu(student);
            break;
        case 4:Delete(student);
            break;
        case 5:exit(1);
        default:
            break;
        }
    }
}
void studentFunc(StudentList *student,char *name){
    int sc=0;
    printf("��ӭѧ����¼ѧ������ϵͳ��\n");
    while(1){
        printf("************************************\n");
        printf("��ѯ��Ϣ���롰1��        �޸��������롰2��\n");
        printf("�˳�����ϵͳ���롰3��\n");
        printf("��ѡ������Ҫ�Ĺ��ܣ�");
        scanf("%d",&sc);
        switch (sc)
        {
        case 1:QueryStu(student);
            break;
        case 2:;

            break;
        case 3:exit(1);
        default:
            break;
        }
    }
}
#include "head.h"

int Query(Student s1) //��ѯ
{
    printf("ѧ����id��%d��ѧ����������%s��ѧ�����Ա�%s��ѧ�������䣺%d��\n",s1.id,s1.name,s1.gender,s1.age);
    printf("ѧ�������룺%d��ѧ���İ༶��%s��ѧ���ĳɼ����Σ�%d��\n",s1.code,s1.class,s1.rank);
    printf("ѧ������ѧ�ɼ���%d��ѧ�������ĳɼ���d��ѧ����Ӣ��ɼ���d��\n",s1.math,s1.chinese,s1.english);
}
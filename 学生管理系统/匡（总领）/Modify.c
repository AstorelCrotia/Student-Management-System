#include "head.h"

void ModifyStu(StudentList *student) //�޸�ѧ����Ϣ
{
    char id[20]="0";
    QueryStu(student);
    printf("��ѡ����Ҫ�����޸ĵ�ѧ����ѧ�ţ�");
    scanf("%s",id);
    StudentList *p=student->next;
    while(p!=NULL){
        if(!strcmp(p->id,id)){
            printf("�������޸ĺ��ѧ����������");
            scanf("%s",p->name);
            printf("�������޸ĺ��ѧ�����Ա�");
            scanf("%s",p->gender);
            printf("�������޸ĺ��ѧ���İ༶��");
            scanf("%s",p->class);
            printf("�������޸ĺ��ѧ�������䣺");
            scanf("%d",&p->age);
            printf("�������޸ĺ��ѧ�������ĳɼ���");
            scanf("%d",&p->chinese);
            printf("�������޸ĺ��ѧ������ѧ�ɼ���");
            scanf("%d",&p->math);
            printf("�������޸ĺ��ѧ����Ӣ��ɼ���");
            scanf("%d",&p->english);
            printf("�޸ĳɹ���");
            break;
        }else{
            p=p->next;
        }
    }
    getSumScore(p);
    QueryStuByRankDown(student);
    inPutStuTxt(student->next);
}
void ModifyStuCode(StudentList *student,char *id){
    StudentList *p=student->next;
    char code[20]="0";
    char code1[20]="0";
    char code2[20]="0";
    int flag=2;
    printf("%s\n",id);
    while(p!=NULL){
        if(!strcmp(p->id,id)){
            break;
        }
        p=p->next;
    }
    while(1){
        printf("������ԭ���룺");
        GetPasscode(code);
        if(!strcmp(p->code,code)){
            while (1){
                printf("\n�������޸ĺ�����룺");
                GetPasscode(code1);
                printf("\n���ٴ������޸ĺ�����룺");
                GetPasscode(code2);
                if(!strcmp(code1,code2)){
                    char *encode=encrypt(code1);
                    strcpy(p->code,encode);
                    printf("\n�޸ĳɹ�!");
                    inPutStuTxt(student->next);
                    return;
                }else{
                    printf("�������벻һ�£����������룡\n");
                    }
                }
        }else{
            if(flag==0){
                printf("\nԭ�����������������࣬������ڽ����޸ģ�\n");
                return;
            }
            else{
                printf("\nԭ��������㻹��%d�λ��ᣬ���������룡\n",flag);
                flag--;
            }
        }
    }
}
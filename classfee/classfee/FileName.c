#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define M  1000
#define M_NUMBER 10
#define M_SIT    20
#define M_NAME   20
#define M_RESON  20
#define M_NOTE   10
#define M_TIME   20


struct classfee {
	char number[M_NUMBER];      //��ѱ��
	char sit[M_SIT];   // ���뻹��֧��
	char name[M_NAME];        //������
	char reson[M_RESON];       //ԭ��
	int  money;           //���
	int  sum;            //����
	char note[M_NOTE];        //��ע
	char time[M_TIME];        //ʱ��
};

struct  feeInfo {
	struct classfee cfe[M];
	int size;
};

void Input(struct feeInfo* ps);
void Scan(struct feeInfo* ps);
void Inquire(struct feeInfo* ps);
void Alter(struct feeInfo* ps);
void Delete(struct feeInfo* ps);
int Outlook();

void InitfeeInfo(struct feeInfo* ps) {
	memset(ps->cfe, 0, sizeof(ps->cfe));
	ps->size = 0;
}

void menu() {
	printf("           �����֧����ϵͳ          \n");
	printf("************����ѡ��ҳ��*************\n");
	printf("*         1.¼������Ϣ            *\n");
	printf("*         2.������а����Ϣ        *\n");
	printf("*         3.��ѯ�����Ϣ            *\n");
	printf("*         4.�޸İ����Ϣ            *\n");
	printf("*         5.ɾ����Ѱ����Ϣ        *\n");
	printf("*************************************\n");
}

int main() {
	int chose = 0;
	struct feeInfo con;
	InitfeeInfo(&con);
	do {
		menu();
		printf("����������Ҫ��������ţ�\n");
		scanf("%d", &chose);
		switch (chose) {
		case 1:
			Input(&con);       //¼������Ϣ
			break;
		case 2:
			//	Scan();         //��������Ϣ
			break;
		case 3:
			//	Inquire();      //��ѯ�����Ϣ
			break;
		case 4:
			//	Alter();        //�޸İ����Ϣ
			break;
		case 5:
			//detele();        //ɾ�������Ϣ
			break;


		}
	} while (chose);
	
}

void Input(struct feeInfo* ps) {

	if (ps->size == M) {
		printf("�洢��Ϣ�������޷�����\n");

	}
	else {
		printf("����������֧��ţ�\n");
		scanf("%s", ps->cfe[ps->size].number);
		printf("��������뻹��֧����\n");
		scanf("%s", ps->cfe[ps->size].sit);
		printf("�����뾭���ˣ�\n");
		scanf("%s", ps->cfe[ps->size].name);
		printf("������ԭ��\n");
		scanf("%s", ps->cfe[ps->size].reson);
		printf("�������\n");
		scanf("%d", ps->cfe[ps->size].money);
		printf("������༶������\n");
		scanf("%d", ps->cfe[ps->size].sum);
		printf("�����뱸ע��\n");
		scanf("%s", ps->cfe[ps->size].note);
		printf("������ʱ�䣺\n");
		scanf("%s", ps->cfe[ps->size].time);

		ps->size++;
		printf("��ӳɹ�\n");
	}
}

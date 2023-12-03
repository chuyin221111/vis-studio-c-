
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M  1000

#define M_NUMBER 10
#define M_SIT    10
#define M_NAME   10
#define M_RESON  10
#define M_NOTE   10
#define M_TIME   12
//#define M_MONEY  6
//#define M_SUM    6
//#define M_TATOL  10


struct classfee {
	char number[M_NUMBER];      //��ѱ��
	char sit[M_SIT];   // ���뻹��֧��
	char name[M_NAME];        //������
	char reson[M_RESON];       //ԭ��
	int *money;           //���
	int *tatol;
	int *sum;            //����
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
//int atoi();

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
	printf("          6.�˳�ϵͳ                 \n");
	printf("*************************************\n");
}

int main() {
	int chose = 0;
	//int z;
	struct feeInfo con;
	InitfeeInfo(&con);
	do {
		menu();
		printf("����������Ҫ��������ţ�\n");
		scanf_s("%d", &chose);
		switch (chose) {
		case 1:
			Input(&con);       //¼������Ϣ
			break;
		case 2:
			Scan(&con);         //��������Ϣ
			break;
			/*	case 3:
					Inquire();      //��ѯ�����Ϣ
					break;
				case 4:
					Alter();        //�޸İ����Ϣ
					break;
				case 5:
					detele();        //ɾ�������Ϣ
					break;
				case 6:
					printf("�˳�ϵͳ\n");
					break;
				default:
					printf("ѡ�����\n");
					break;*/


		}
	} while (chose);
	return 0;
}

void Input(struct feeInfo* ps) {
	//int z;
	if (ps->size == M) {
		printf("�洢��Ϣ�������޷�����\n");

	}
	else {
		printf("����������֧��ţ�\n");
		getchar();
		scanf_s("%s", ps->cfe[ps->size].number);
		printf("��������뻹��֧����\n");
//		getchar();
		scanf_s("%s", ps->cfe[ps->size].sit);
		printf("�����뾭���ˣ�\n");
		getchar();
		scanf_s("%s", ps->cfe[ps->size].name);
		printf("������ԭ��\n");
		getchar();
		scanf_s("%s", ps->cfe[ps->size].reson);
		printf("�������\n");
		getchar();
		scanf_s("%d", ps->cfe[ps->size].money);
		printf("������༶������\n");
		getchar();
		scanf_s("%d", ps->cfe[ps->size].sum);
		printf("�����뱸ע��\n");
		getchar();
		scanf_s("%s", ps->cfe[ps->size].note);
		printf("������ʱ�䣺\n");
		getchar();
		scanf_s("%s", ps->cfe[ps->size].time);
		if (strcmp(ps->cfe[ps->size].sit, "֧��") == 0) {
			printf("���Ϊ��\n");
			ps->cfe[ps->size].tatol =( ps->cfe[ps->size].money )* (ps->cfe[ps->size].sum) * -1;

		}
		if (strcmp(ps->cfe[ps->size].sit, "����") == 0) {
			printf("���Ϊ��\n");
			ps->cfe[ps->size].tatol = (ps->cfe[ps->size].money )* (ps->cfe[ps->size].sum);

		}
		ps->size++;
		printf("��ӳɹ�\n");
		printf("�����İ����Ϣ���£�\n");
		printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-5s\t%-4s%-10s\n", "��ѱ���", "���뻹��֧��", "������" "ԭ��",
			"��ÿλͬѧ)", "����", "��ע", "ʱ��", "���","һ��");
		printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10d\t%-10d\t%-5s\t%-4s%-10d\n",
			ps->cfe[ps->size].number,
			ps->cfe[ps->size].sit,
			ps->cfe[ps->size].name,
			ps->cfe[ps->size].reson,
			ps->cfe[ps->size].money,
			ps->cfe[ps->size].sum,
			ps->cfe[ps->size].note,
			ps->cfe[ps->size].time,
			ps->cfe[ps->size].tatol);

	}
}

void Scan(struct feeInfo* ps) {
	printf("�ѽ���\n");
	if (ps->size == 0) {
		printf("û��¼����Ϣ");
	}
	else {
		int i = 0;
		printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-5s\t%-4s%-10s\n", "��ѱ���", "���뻹��֧��", "������", "ԭ��",
			"��ÿλͬѧ)", "����", "��ע", "ʱ��", "���");
		for (i = 0; i < ps->size; i++) {
			printf("%-10s\t%-10s\t%-20s\t%-10s\t%-10s\t%-10s\t%-5s\t%-4s%-10s\n",
				ps->cfe[i].number,
				ps->cfe[i].sit,
				ps->cfe[i].reson,
				ps->cfe[i].name,
				ps->cfe[i].money,
				ps->cfe[i].sum,
				ps->cfe[i].note,
				ps->cfe[i].time,
				ps->cfe[i].tatol);

		}

	}
}
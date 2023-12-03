
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
	char number[M_NUMBER];      //班费编号
	char sit[M_SIT];   // 收入还是支出
	char name[M_NAME];        //经办人
	char reson[M_RESON];       //原因
	int *money;           //金额
	int *tatol;
	int *sum;            //人数
	char note[M_NOTE];        //备注
	char time[M_TIME];        //时间
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
	printf("           班费收支管理系统          \n");
	printf("************功能选择页面*************\n");
	printf("*         1.录入班费信息            *\n");
	printf("*         2.浏览所有班费信息        *\n");
	printf("*         3.查询班费信息            *\n");
	printf("*         4.修改班费信息            *\n");
	printf("*         5.删除班费班费信息        *\n");
	printf("          6.退出系统                 \n");
	printf("*************************************\n");
}

int main() {
	int chose = 0;
	//int z;
	struct feeInfo con;
	InitfeeInfo(&con);
	do {
		menu();
		printf("请输入你所要操作的序号：\n");
		scanf_s("%d", &chose);
		switch (chose) {
		case 1:
			Input(&con);       //录入班费信息
			break;
		case 2:
			Scan(&con);         //浏览班费信息
			break;
			/*	case 3:
					Inquire();      //查询班费信息
					break;
				case 4:
					Alter();        //修改班费信息
					break;
				case 5:
					detele();        //删除班费信息
					break;
				case 6:
					printf("退出系统\n");
					break;
				default:
					printf("选择错误\n");
					break;*/


		}
	} while (chose);
	return 0;
}

void Input(struct feeInfo* ps) {
	//int z;
	if (ps->size == M) {
		printf("存储信息已满，无法增加\n");

	}
	else {
		printf("请输入班费收支编号：\n");
		getchar();
		scanf_s("%s", ps->cfe[ps->size].number);
		printf("请输出收入还是支出：\n");
//		getchar();
		scanf_s("%s", ps->cfe[ps->size].sit);
		printf("请输入经办人：\n");
		getchar();
		scanf_s("%s", ps->cfe[ps->size].name);
		printf("请输入原因：\n");
		getchar();
		scanf_s("%s", ps->cfe[ps->size].reson);
		printf("请输入金额：\n");
		getchar();
		scanf_s("%d", ps->cfe[ps->size].money);
		printf("请输入班级人数：\n");
		getchar();
		scanf_s("%d", ps->cfe[ps->size].sum);
		printf("请输入备注：\n");
		getchar();
		scanf_s("%s", ps->cfe[ps->size].note);
		printf("请输入时间：\n");
		getchar();
		scanf_s("%s", ps->cfe[ps->size].time);
		if (strcmp(ps->cfe[ps->size].sit, "支出") == 0) {
			printf("余额为：\n");
			ps->cfe[ps->size].tatol =( ps->cfe[ps->size].money )* (ps->cfe[ps->size].sum) * -1;

		}
		if (strcmp(ps->cfe[ps->size].sit, "收入") == 0) {
			printf("余额为：\n");
			ps->cfe[ps->size].tatol = (ps->cfe[ps->size].money )* (ps->cfe[ps->size].sum);

		}
		ps->size++;
		printf("添加成功\n");
		printf("新增的班费信息如下：\n");
		printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-5s\t%-4s%-10s\n", "班费编码", "收入还是支出", "经办人" "原因",
			"金额（每位同学)", "人数", "备注", "时间", "余额","一切");
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
	printf("已进入\n");
	if (ps->size == 0) {
		printf("没有录入信息");
	}
	else {
		int i = 0;
		printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-5s\t%-4s%-10s\n", "班费编码", "收入还是支出", "经办人", "原因",
			"金额（每位同学)", "人数", "备注", "时间", "余额");
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
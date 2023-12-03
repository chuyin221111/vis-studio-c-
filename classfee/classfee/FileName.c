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
	char number[M_NUMBER];      //班费编号
	char sit[M_SIT];   // 收入还是支出
	char name[M_NAME];        //经办人
	char reson[M_RESON];       //原因
	int  money;           //金额
	int  sum;            //人数
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
	printf("*************************************\n");
}

int main() {
	int chose = 0;
	struct feeInfo con;
	InitfeeInfo(&con);
	do {
		menu();
		printf("请输入你所要操作的序号：\n");
		scanf("%d", &chose);
		switch (chose) {
		case 1:
			Input(&con);       //录入班费信息
			break;
		case 2:
			//	Scan();         //浏览班费信息
			break;
		case 3:
			//	Inquire();      //查询班费信息
			break;
		case 4:
			//	Alter();        //修改班费信息
			break;
		case 5:
			//detele();        //删除班费信息
			break;


		}
	} while (chose);
	
}

void Input(struct feeInfo* ps) {

	if (ps->size == M) {
		printf("存储信息已满，无法增加\n");

	}
	else {
		printf("请输入班费收支编号：\n");
		scanf("%s", ps->cfe[ps->size].number);
		printf("请输出收入还是支出：\n");
		scanf("%s", ps->cfe[ps->size].sit);
		printf("请输入经办人：\n");
		scanf("%s", ps->cfe[ps->size].name);
		printf("请输入原因：\n");
		scanf("%s", ps->cfe[ps->size].reson);
		printf("请输入金额：\n");
		scanf("%d", ps->cfe[ps->size].money);
		printf("请输入班级人数：\n");
		scanf("%d", ps->cfe[ps->size].sum);
		printf("请输入备注：\n");
		scanf("%s", ps->cfe[ps->size].note);
		printf("请输入时间：\n");
		scanf("%s", ps->cfe[ps->size].time);

		ps->size++;
		printf("添加成功\n");
	}
}

#include <iostream>
using namespace std;
const int maxsize = 10;
typedef struct {
	char ch[maxsize];
	int n;
}sqstring;
void scat(sqstring *A,sqstring *B,sqstring *C)//连接A，B
{
	C->n = 0;
	for (int i = 0; i < A->n; i++)  //把串A的值赋给C
	{
		C->ch[i] = A->ch[i];
		C->n++;
	}

	for (int j = 0; j < B->n; j++)//在A的基础上，再把串B的赋给C
	{
		C->ch[C->n] = B->ch[j];
		C->n++;
	}
	for (int i = 0; i < C->n; i++)
	{
		cout << C->ch[i];
	}
}
void store(sqstring *A,sqstring *B)//存储串A，串B
{
	cout << "输入你要存储的串A个数" << endl;
	cin >> A->n;
	cout << "输入你要存储的字符" << endl;
	for (int i = 0; i < A->n; i++)
	{
		cin >> A->ch[i];
	}
	cout << "输入你要存储的串B的个数" << endl;
	cin >> B->n;
	cout << "输入你要存储的字符" << endl;
	for (int j = 0; j < B->n; j++)
	{
		cin >> B->ch[j];
	}
}
int main()
{
	sqstring *A,*B,*C;//创建C来存储A，B的连接后的串
	A = new sqstring();//初始化A
	B = new sqstring();//初始化B
	C = new sqstring();//初始化C，
	store(A,B);
	cout << "新的串C如下：" << endl;
	scat(A, B,C);
	return 0;
}
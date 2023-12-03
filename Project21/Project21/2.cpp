/**��д�㷨���ж�ĳ���ַ����Ƿ������ĶԳƹ�ϵ���ֳƻ��ģ���
����xyzzyx��xyzyx�������ĶԳƵ��ַ�����
��ʾ����ջ��æ�����ַ�����ǰ�벿��������ջ��
������Ƚ�ʣ���ַ���ջ��Ԫ���Ƿ�һ�£���ȷƥ��һ�����ջһ����
ֻҪ��1����ƥ�����ǻ��ģ����ʣ���ַ�˳��ƥ�����ջΪ�գ�
���ǻ��ġ�
ע���ַ�������Ϊ������ż���Ĳ����ǲ�ͬ�ġ�*/
#include <iostream>
#include <math.h>
using namespace std;
typedef char datatype;
const int maxsize = 100;
typedef  struct {
	datatype data[maxsize];
	int top;
}sqstack;
int empty(sqstack* sq)
{
	if (sq->top == -1)
		return 1;
	else return 0;
}
//��ջ
int push(sqstack* sq, datatype x)
{
	if (sq->top == maxsize - 1)
	{
		cout << "ջ�������ܽ�ջ\n"; return 0;
	}
	sq->data[++sq->top] = x;
	return 1;
}
//��ջ
int pop(sqstack* sq, datatype* x)
{
	if (sq->top == -1)
	{
		cout << "������ջ����Ϊ��ջ\n";
		return 0;
	}
	*x = sq->data[sq->top--];
	return 1;
}
//ȡջ��
char gettop(sqstack* sq, datatype* x)
{
	if (sq->top == -1)
	{
		cout << "ջ�գ�����ȡջ\n";
		return 0;
	}
	*x = sq->data[sq->top];
	return *x;
}

int  main()
{
	sqstack* sq = new sqstack();
	char h;
	sq->top = -1;
	int n;
	cout << "������Ҫ������ַ�������\n";
	cin >> n;
	char ch [100];
	cout << "����������ַ���" << endl;
	cin >> ch;
	int len = strlen(ch);
	//�ж��ַ����Ƿ�Ϊż��
	//�ַ�����ż��
	if (n % 2 == 0)
	{
		for (int i = 0; i < n / 2; i++)
		{
			push(sq, ch[i]);
		}
		for (int k = n / 2; k < n; k++)
		{
			char d = gettop(sq,&h);
			if (d == ch[k])
			{
				pop(sq,&h);
			}
			
		}
	}
	//�ַ�������ż��
	else {
		for (int j = 0; j < floor(n / 2); j++)
		{
			push(sq, ch[j]);
		}
		for (int f = floor(n / 2) + 1; f < n; f++)
		{
			int y = gettop(sq,&h);
			if (y == ch[f])
			{
				pop(sq,&h);
			}
			
		}
	}
	if (empty(sq) == 1)
	{
		cout << "�ǻ���\n";
	}
	else {
		cout << "���ǻ���";
	}
	return 0;
}
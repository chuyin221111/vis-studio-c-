//����㷨������ջ���ж�һ���������ʽ�е�Բ�����Ƿ���ȷ��ԡ�
//	��ʾ��ÿ��ɨ�赽��(�����ͽ����ջ��ÿ��ɨ�赽��)�����ͽ���ǰջ����
//��(����ջ�������ʱջ����Ԫ�ؿɳ������������Բ���ȷ���������ȫɨ�����ջΪ�գ��������ȷ��ԣ���֮���ջ�л���Ԫ�أ�
//	��ƥ�䲻�ɹ���
#include <iostream>
using namespace  std;
typedef char datatype;
const int maxsize = 100;
typedef struct {
	datatype data[maxsize];
	int top;
}sqstack;
//��ʼ��
void init(sqstack *sq)
{
	sq->top = -1;
}
//��ջ��
int empty(sqstack* sq)
{
	if (sq->top == -1)
		return 1;
	else return 0;
}
//��ջ
int push(sqstack* sq,datatype x)
{
	if (sq->top == maxsize - 1)
	{
		cout << "ջ�������ܽ�ջ��\n";
		return 0;
	}
	sq->data[++sq->top] = x;
	return 1;		
}
//��ջ
int pop(sqstack* sq,datatype *x)
{
	if (sq->top == -1)
	{
		cout << "ջ�գ�������ջ!\n";
		return 0;
	 }
	*x = sq->data[sq->top--];
	return 1;
}
//ȡջ��
int gettop(sqstack* sq,datatype *x)
{
	
	if (sq->top == -1)
	{
		cout << "��Բ��ɹ�\n";
		return 0;
	}
	*x = sq->data[sq->top];
	sq->top--;
	return 1;
}
int main()
{
	sqstack* sq = new sqstack();
	sq->top = -1;
	char x[] = {'(', 'a', '+', 'b', ')', '=','c'};
	int len = sizeof(x) / sizeof(x[0]);
	for (int i = 0;i <len;i++)
	{
		if (x[i] == '(')
		{
			push(sq, x[i]);
		}
		else if (x[i] == ')')
		{
			int k = gettop(sq,&x[i]);

			
		}
	
	}
	int g = empty(sq);
	if (g == 1)
	{
		cout << "��ȷ���";
	}
	else
	{
		cout << "ƥ�䲻�ɹ�";
	}
	return 0;
}
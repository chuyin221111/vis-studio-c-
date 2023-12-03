/**编写算法，判断某个字符串是否有中心对称关系（又称回文），
例如xyzzyx、xyzyx都是中心对称的字符串。
提示：用栈帮忙。将字符串的前半部分依次入栈，
再逐个比较剩余字符和栈顶元素是否一致，正确匹配一个则出栈一个，
只要有1个不匹配则不是回文；如果剩余字符顺利匹配完后，栈为空，
则是回文。
注意字符串长度为奇数或偶数的操作是不同的。*/
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
//进栈
int push(sqstack* sq,datatype x)
{
	if (sq->top == maxsize - 1)
		cout << "栈满，不能进栈\n"; return 0;
	sq->data[++sq->top] = x;
	return 1;
}
//退栈
int pop(sqstack* sq, datatype* x)
{
	if (sq->top == -1)
		cout << "不能退栈，此为空栈\n";
	return 0;
	*x = sq->data[sq->top--];
	return 1;
}
//取栈顶
char gettop(sqstack* sq,datatype *x)
{   
	if (sq->top == -1)
	{
		cout << "栈空，不能取栈\n";
		return 0;
	}
	*x = sq->data[sq->top--];
	return *x;
}
void cte(char *ch,int n)
{
	cout << "请输入你的字符串" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> ch[i];
	}
}
int  main()
{
	sqstack* sq = new sqstack();
	sq->top = -1;
	int n;
	cout << "输入你要输入的字符串个数\n";
	cin >> n;
	char *ch = new char[n];
	cte(ch, n);
	//判断字符串是否为偶数
	//字符串是偶数
	if (n % 2 == 0)
	{
		for (int i = 0; i < n / 2; i++)
		{
			push(sq, ch[i]);
		}
		for (int k = n / 2; k < n; k++)
		{
			int x=gettop(sq, NULL);
			if (x == ch[k])
			{
				pop(sq, NULL);
			}
			else {
				cout << "不匹配，不是回文\n";
			}
		}
	}
	//字符串不是偶数
	else {
		for (int j = 0; j < floor(n / 2); j++)
		{
			push(sq, ch[j]);
		 }
		for (int f = floor(n / 2) + 1; f < n; f++)
		{
			int y = gettop(sq, NULL);
				if (y== ch[f])
				{
					pop(sq, NULL);
				}
				else
				{
					cout << "不匹配，不是回文\n";
				}
		}
	}
	if (empty(sq) == 1)
	{
		cout << "是回文\n";
	}
	else {
		cout << "不是回文";
	}
	return 0;
}
//设计算法，利用栈来判断一个算术表达式中的圆括号是否正确配对。
//	提示：每次扫描到“(”，就将其进栈，每次扫描到“)”，就将当前栈顶的
//“(”出栈（如果此时栈中无元素可出，则输出“配对不正确”）；如果全扫描完后，栈为空，则表明正确配对，反之如果栈中还有元素，
//	则匹配不成功。
#include <iostream>
using namespace  std;
typedef char datatype;
const int maxsize = 100;
typedef struct {
	datatype data[maxsize];
	int top;
}sqstack;
//初始化
void init(sqstack *sq)
{
	sq->top = -1;
}
//判栈空
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
	{
		cout << "栈满，不能进栈！\n";
		return 0;
	}
	sq->data[++sq->top] = x;
	return 1;		
}
//退栈
int pop(sqstack* sq,datatype *x)
{
	if (sq->top == -1)
	{
		cout << "栈空，不能退栈!\n";
		return 0;
	 }
	*x = sq->data[sq->top--];
	return 1;
}
//取栈顶
int gettop(sqstack* sq,datatype *x)
{
	
	if (sq->top == -1)
	{
		cout << "配对不成功\n";
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
		cout << "正确配对";
	}
	else
	{
		cout << "匹配不成功";
	}
	return 0;
}
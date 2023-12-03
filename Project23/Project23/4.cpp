/*设S、T是两个串，编写算法，找出S
中第一个不在T中出现的字符。
例如，S=“abcdef”，
T=“achhbhj”，则S中第一个不在T中出现的字符为‘d’。
S串和T串的内容由用户输入。 
*/
#include <iostream>
using namespace std;
const int maxsize = 100;
typedef struct {
	char ch[maxsize];
	int n;
}sqstring;
void creat(sqstring* s)
{
	cout << "请输入你要创建串的个数\n";
	cin >> s->n;
	cout << "请输入字符串\n";
	for (int i = 0; i < s->n; i++)
	{
		cin >> s->ch[i];
	}
}
void find(sqstring* S, sqstring* T)
{
	
	for (int i = 0; i < S->n; i++)
	{
		int sum = 0;
		for (int j = 0; j < T->n; j++)
		{
			if (T->ch[j] == S->ch[i])
			{
				sum++;
				break;
			}
			
		}
		if (sum == 0)
		{
			cout << "S中的第一个不在T出现的字符为" << S->ch[i] << endl;
			break;
		}
		
	}
}
int main()
{
	sqstring* S = new sqstring();
	sqstring* T = new sqstring();
	cout << "创建串S\n";
	creat(S);
	cout << "创建串T\n";
	creat(T);
	find(S, T);


}
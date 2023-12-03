/*用顺序存储结构存储串S，
编写算法删除S中第 i个字符开始的连续j个字符，
不要使用系统函数。提示：用字符数组实现。
例如，串S=“abcdef”，i=2，j=3，则删除之后，S=“aef”。
串S的内容由用户输入。
*/
#include <iostream>
using namespace std;
const int maxsize = 100;
typedef struct {
	char ch[maxsize];
	int n;
}sqstring;
void creat(sqstring* s,int l)
{
	cout << "输入你要存储的字符" << endl;
	for (int k = 0; k < l; k++)
	{
		cin >> s->ch[k];
		s->n++;
	}
}
void del(sqstring* s, int i, int j)
{
	s->n=s->n - j;
	int b = j;
	for (int h = i; h <=s->n ; h++)
	{
		s->ch[h - 1] = s->ch[b+1];
		b = b + 1;
	}
}
void print(sqstring *s)
{
	cout << "字符串如下";
	for (int g = 0; g < s->n; g++)
	{
		cout << s->ch[g];
     }
}
int main()
{    
	sqstring* s = new sqstring();
	int l;
	cout << "输入你要创建的字符个数" << endl;
	cin >> l;
	creat(s, l);
	int i, j;
	cout << "请输入你要删除的开始字符个数\n" ;
	cin >> i;
	cout << "请输入你删除的连续字符\n";
	cin >> j;
	del(s, i, j);
	print(s);
	return 0;
	
}
/*��S��T������������д�㷨���ҳ�S
�е�һ������T�г��ֵ��ַ���
���磬S=��abcdef����
T=��achhbhj������S�е�һ������T�г��ֵ��ַ�Ϊ��d����
S����T�����������û����롣 
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
	cout << "��������Ҫ�������ĸ���\n";
	cin >> s->n;
	cout << "�������ַ���\n";
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
			cout << "S�еĵ�һ������T���ֵ��ַ�Ϊ" << S->ch[i] << endl;
			break;
		}
		
	}
}
int main()
{
	sqstring* S = new sqstring();
	sqstring* T = new sqstring();
	cout << "������S\n";
	creat(S);
	cout << "������T\n";
	creat(T);
	find(S, T);


}
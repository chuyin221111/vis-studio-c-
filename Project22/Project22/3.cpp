/*��˳��洢�ṹ�洢��S��
��д�㷨ɾ��S�е� i���ַ���ʼ������j���ַ���
��Ҫʹ��ϵͳ��������ʾ�����ַ�����ʵ�֡�
���磬��S=��abcdef����i=2��j=3����ɾ��֮��S=��aef����
��S���������û����롣
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
	cout << "������Ҫ�洢���ַ�" << endl;
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
	cout << "�ַ�������";
	for (int g = 0; g < s->n; g++)
	{
		cout << s->ch[g];
     }
}
int main()
{    
	sqstring* s = new sqstring();
	int l;
	cout << "������Ҫ�������ַ�����" << endl;
	cin >> l;
	creat(s, l);
	int i, j;
	cout << "��������Ҫɾ���Ŀ�ʼ�ַ�����\n" ;
	cin >> i;
	cout << "��������ɾ���������ַ�\n";
	cin >> j;
	del(s, i, j);
	print(s);
	return 0;
	
}
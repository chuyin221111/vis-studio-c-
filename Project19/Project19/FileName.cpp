#include <iostream>
using namespace std;
const int maxsize = 10;
typedef struct {
	char ch[maxsize];
	int n;
}sqstring;
void scat(sqstring *A,sqstring *B,sqstring *C)//����A��B
{
	C->n = 0;
	for (int i = 0; i < A->n; i++)  //�Ѵ�A��ֵ����C
	{
		C->ch[i] = A->ch[i];
		C->n++;
	}

	for (int j = 0; j < B->n; j++)//��A�Ļ����ϣ��ٰѴ�B�ĸ���C
	{
		C->ch[C->n] = B->ch[j];
		C->n++;
	}
	for (int i = 0; i < C->n; i++)
	{
		cout << C->ch[i];
	}
}
void store(sqstring *A,sqstring *B)//�洢��A����B
{
	cout << "������Ҫ�洢�Ĵ�A����" << endl;
	cin >> A->n;
	cout << "������Ҫ�洢���ַ�" << endl;
	for (int i = 0; i < A->n; i++)
	{
		cin >> A->ch[i];
	}
	cout << "������Ҫ�洢�Ĵ�B�ĸ���" << endl;
	cin >> B->n;
	cout << "������Ҫ�洢���ַ�" << endl;
	for (int j = 0; j < B->n; j++)
	{
		cin >> B->ch[j];
	}
}
int main()
{
	sqstring *A,*B,*C;//����C���洢A��B�����Ӻ�Ĵ�
	A = new sqstring();//��ʼ��A
	B = new sqstring();//��ʼ��B
	C = new sqstring();//��ʼ��C��
	store(A,B);
	cout << "�µĴ�C���£�" << endl;
	scat(A, B,C);
	return 0;
}
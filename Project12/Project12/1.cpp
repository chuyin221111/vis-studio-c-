//һ��˳����д���ַ���ֻ�������ַ���Ӣ���ַ������û��Ӽ��������룩����д�㷨ɾ�����е������ַ���
#include <iostream>
using namespace std;
typedef char datatyper;
const int maxsize = 10;
typedef struct {
	datatyper data[maxsize];
	int n;
}sqlist;
void  create(sqlist *L)
{   
	char k;
	L->n = 0;
	for (int i = 0; i < maxsize; i++)
	{
		cin >> k;
		L->data[i] = k;
		L->n++;
	}
}
int dete(sqlist* L)
{  
	int sum = 0;
	if (L->n == 0)
	{
		cout << "��գ�����ɾ����\n";
		return -1;
	}
	else if (L->n > 0)
	{
		for (int i = 0; i < L->n; i++)
		{
			if (L->data[i] >='0' && L->data[i] <= '9')
			{
				sum++;
			}
			else if (sum > 0)
			{

				L->data[i - sum] = L->data[i];
			}
		}
		L->n = L->n - sum;
	}
	return 1;
}
int main()
{
	 sqlist *L =new sqlist();
	 int p;
	 cout << "��������Ҫ��ŵ��ַ�(��10���ַ�)"<<endl;
	 create(L);
	 p=dete(L);
	 if (p == 1)
		 cout << "ɾ���ɹ�" << endl;
	 else 
		 cout << "ɾ��ʧ��" << endl;
	 cout << "˳�������" << endl;
	 for (int j = 0; j <L->n; j++)
	 {
		 cout << L->data[j] <<" ";
	 }
	

}

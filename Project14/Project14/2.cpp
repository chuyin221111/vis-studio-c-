#include <iostream>
using namespace std;
typedef int datatyper;
const int maxsize = 10;
 typedef struct {
	datatyper data[maxsize];
	int n;
}sqlist;
 void create(sqlist* L)
 {   
	 cout << "����˳�������������" << endl;
	 L->n= 0;
	 int k;
	 for (int i = 0; i < maxsize; i++)
	 {  
		 cin >> k;
		 L->data[i] = k;
		 L->n++;
	 }
 }
 void sort(sqlist* L)//���򣬵��������ظ�Ԫ��
 {  
	 int k;
	 for (int i = 0; i < L->n; i++)
	 {
		 for (int j = i+1;j<L->n; j++)
		 {
			 if (L->data[i] > L->data[j])
			 {
				 k = L->data[i];
				 L->data[i] = L->data[j ];
				 L->data[j] = k;
			 }
		  }

     }
 }
 void find(sqlist* L)//Ѱ���ظ�Ԫ��
 { 
	 int k=0;
	 for (int i = 0; i < L->n; i++)
	 {
		 if (L->data[i] == L->data[i + 1])
		 {
			 k++;

		 }
		 else if (k > 0)
		 {
			 L->data[i + 1 - k] = L->data[i + 1];
		 }
		
     }
	 L->n = L->n + 1 - k;
	
 }
int main()
{
	sqlist* L;
	L = new sqlist();
	create(L);
	sort(L);//����
	find(L);//�ų��ظ�����
	sort(L);
	cout << "˳�������" << endl;
	for (int i = 0; i < L->n; i++)
	{
		cout << L->data[i]<<" ";
	}
	return 0;
}
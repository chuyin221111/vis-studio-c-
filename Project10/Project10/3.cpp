#include <iostream>
using namespace std;
typedef int datapype;
const  int maxsize = 6;
typedef struct
{
	datapype data[maxsize];
	int length;
}list;
void createA(list* A)
{
	A->length = 0;
	int k;
  for (int i=0;i<maxsize; i++)
  {
	  cin >> k;
	A->data[i]=k;
	A->length++;

}
}
void createB(list* B)
{
	B->length = 0;
	int k;
	for (int i=0; i < maxsize; i++)
	{
		cin >> k;
		B->data[i]=k;
		B->length++;

	}
}
datapype find(list* B, datapype b)
{
	for (int i = 0; i < maxsize; i++)
	{
		if (b == B->data[i])
		{
			return b;
		}
	}
	return -1;

}
void detele(list* A,list*B)
{
	datapype c=0;
	int i, s;
	s = 0;
	for (i = 0; i < A->length; i++)
	{
		    c=A->data[i];
			if (A->data[i]!=find(B,c)&&c!=-1)
			{
				s++;
			}
			else if (s > 0)
			A->data[i-s ] = A->data[i];

	}
	A->length = A->length - s;
}

int main()
{
	list* A = new list(); 
	list* B = new list();
	cout << "建立集合A" << endl;
	createA(A);
	cout << "建立集合B" << endl;
	createB(B);
	cout << "创建集合A、B完成" << endl;
	detele(A,B);
	for (int i = 0; i < A->length; i++)
	{
		cout << A->data[i] <<" ";
	}
	return 0;
}
//一个顺序表中存放字符（只有数字字符和英文字符，由用户从键盘上输入），编写算法删除所有的数字字符。
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
		cout << "表空，不能删除！\n";
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
	 cout << "请输入你要存放的字符(仅10个字符)"<<endl;
	 create(L);
	 p=dete(L);
	 if (p == 1)
		 cout << "删除成功" << endl;
	 else 
		 cout << "删除失败" << endl;
	 cout << "顺序表如下" << endl;
	 for (int j = 0; j <L->n; j++)
	 {
		 cout << L->data[j] <<" ";
	 }
	

}

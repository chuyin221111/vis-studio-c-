
#include <cstring>
#include <iostream>
using namespace std;
typedef int datatype;
const int  maxsize = 10;

struct sqlist{
	datatype data[maxsize];
	int n;

};

void  order(sqlist&L);
void create(sqlist&L, int k)
{
	L.n = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> L.data[i];
		L.n++;
	}
 }

void order(sqlist&L) {
	datatype x;
	int i, j;
	i = 0;
	j = L.n - 1;
	while (i < j) {
		x = L.data[i];
		L.data[i] = L.data[j];
		L.data[j] = x;
		i++;
		j--;
	}
}

int main() {
	sqlist L;
	int i,k;
	cout << "输入data数组所需空间" << endl;
	cin >> k;
	create(L, k);
	order(L);

	cout << "逆转后" << endl;
	for ( i = 0; i < L.n; i++) {
		cout << L.data[i]<<" ";
	}
	return 0;
}
/*小哼的学校要建立一个图书角，老师派小哼去找一些同学做调查，看看同学们都喜欢读哪些书。
小哼让每个同学写出一个自己最想读的书的ISBN号（你知道吗？每本书都有唯一的ISBN号，不信
话你去找本书翻到背面看看）。当然有一些好书会有很多同学都喜欢，这样就会收集到很多重复的ISBN号。
小哼需要去掉其中重复的ISBN号，即每个ISBN号只保留一个，也就说同样的书只买一本（学校真是够抠门的）。
然后再把这些ISBN号从小到大排序，小哼将按照排序好的ISBN号去书店去买书。
请你协助小哼完成“去重”与“排序”的工作。排序算法可以采用
直接插入排序、冒泡排序、快速排序、简单选择排序、堆排序、二路归并排序中的任一种。
 
输入格式：	
输入有2行，第1行为一个正整数，表示有n个同学参与调查（n<=100）；第2行有n个用空格隔开的正整数，
为每本图书的ISBN号（假设图书的ISBN号在1~1000之间）。

输出格式：	
输出也是2行，第1行为一个正整数k，表示需要买多少本书；第2行为k个用空格隔开的正整数，为从小到大已排好序的
需要购买的图书ISBN号。
*/
#include <iostream>
using namespace std;
const int maxsize = 100;	//排序表容量，假设为100
typedef int datatype;	//假设关键字为int
typedef int othertype;
typedef struct {
	datatype key;		//关键字域
	//othertype other;		//其它域
} rectype;				//记录类型
typedef rectype list[maxsize + 1];
//排序表类型，0号单元不用（或作它用，如“监视哨”）
int Partition(list R, int p, int q) {
	//对无序区R[p]到R[q]划分，返回划分后基准的位置
	int i, j;
	i = p;  j = q;   R[0] = R[i];
	//R[0]作辅助量，存基准(无序区第一个记录)
	while (i < j) {
		while (R[j].key >= R[0].key && i < j) j--;
		//从右向左扫描
		if (i < j) { R[i] = R[j]; i++; }	//交换R[i]和R[j]
		while (R[i].key <=R[0].key && i < j) i++;
		//从左向右扫描
		if (i < j) { R[j] = R[i]; j--; }	//交换R[i]和R[j]
	}
	R[i] = R[0];			//将基准移到最后位置
	return i;
}
void QuickSort(list R, int s, int t) {
	//对R[s]到R[t]快速排序
	int i;
	if (s >= t) return;	//只有一个记录或无记录无需排序
	i = Partition(R, s, t);	//对R[s]到R[t]做划分
	QuickSort(R, s, i-1);	//递归处理左区间
	QuickSort(R, i + 1, t);	//递归处理右区间
}
void print(list R, int n)
{
	int g = n;
	for (int y = 1; y <= n; y++)
	{
		if (R[y].key == R[y + 1].key)
		{
			g--;
		}
	}
	cout << g<<endl;
	for (int h = 1; h <= n; h++)
	{
		if (R[h].key == R[h + 1].key)
		{
			h++;
			cout << R[h].key<<" ";
		}
		else
		{
			cout << R[h].key<<" ";
		}
	}

}
int main()
{
	int n;
	cin >> n;
	list R;
	int k;
	for ( k = 1; k <= n; k++)
	{
		cin >>R[k].key;
	}
	QuickSort(R, 1, n);
	print(R, n);
	
}
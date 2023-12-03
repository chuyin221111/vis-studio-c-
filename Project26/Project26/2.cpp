/*构造哈夫曼树，要求：
1)用户输入结点数n
2)用户输入这n个结点的权重
3)用这n个结点构造出一颗哈夫曼树
4)最终输出这棵哈夫曼树每个结点的信息（按weight、parent、lchild、rchild的顺序输出）
5)算出这棵哈夫曼树的带权路径长度
例如：若输入n=4，且这4个结点的权重分别为6,3,4,8，则输出这棵哈夫曼树每个结点的信息应为：
6 5 -1 -1
3 4 -1 -1
4 4 -1 -1
8 6 -1 -1
7 5 1 2
13 6 0 4
21 -1 3 5
该哈夫曼树的带权路径长度为：8×1+6×2+3×3+4×3=41*/
#include <iostream>
//#include <int.h>
using namespace std;
const int maxsize = 100;
typedef int datatype;
//typedef struct node* notetype;
typedef struct {
	datatype weight;
	datatype parent;
	datatype lchild;
	datatype rchild;
}note;
typedef struct{
	 datatype n;
	 note data[maxsize];
}bitree;
void CreatHash(bitree* t)
{
	int m = 2 * t->n - 1,r=t->n;
	int min1, min2;
	int p1, p2;
	for (int i = r; i < m; i++)
	{
		p1 = p2 = -1;
		min1 = min2 = INT_MAX;
		for (int j = 0; j < i; j++)
		{
			if (t->data[j].parent != -1) continue;
			if (t->data[j].weight < min1)
			{
				min2 = min1;
				min1 = t->data[j].weight;
				p2 = p1;
				p1 = j;
			}
			else  if (t->data[j].weight < min2)
			{
				min2 = t->data[j].weight;
				p2 = j;
			}
		}
		t->data[p1].parent = t->data[p2].parent = i;
		t->data[i].parent = -1;
		t->data[i].lchild = p1;
		t->data[i].rchild = p2;
		t->data[i].weight = min1 + min2;
		r++;
	}
}
void print(bitree* t)
{
	for (int g = 0; g < 2 * t->n - 1; g++)
	{
		cout << t->data[g].weight << " " << t->data[g].parent << " " << t->data[g].lchild << " " << t->data[g].rchild << endl;
	}
}
void find(int r)
{

}
void road(bitree* t)
{
	int sum = 0,mun=0;
	int tem=0;
	for (int j= 0; j <2*t->n-1; j++)
	{   
		int i = j;
		sum = 0;
		mun++;
		if (mun <=t->n) {
			do
			{
				sum++;
				i = t->data[i].parent;
			} while (t->data[i].parent != -1);
			tem = tem + sum * t->data[j].weight;
		}	
	}
	cout << tem << endl;
}
int main()
{
	bitree *t=new bitree();
	cout << "用户输入结点数";
	cin >> t->n;
	for (int i = 0; i < t->n; i++)
	{
			t->data[i].parent = -1;
			t->data[i].lchild = -1;
			t->data[i].rchild = -1;
	}
	cout << "输入权值\n";
	for (int i = 0; i < t->n; i++)
	{
		cin >> t->data[i].weight;
	}
	cout << "哈夫曼树为：";
	CreatHash(t);
	print(t);
	road(t);
}
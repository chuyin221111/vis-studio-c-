#include <iostream>
using namespace std;
typedef char datatyper;
typedef  struct node* pointer;
struct node {
	datatyper data;
	pointer   next;
};
typedef   pointer lklist;
lklist creat()//尾插法
{
	pointer head, rear, s;
	char ch;
	head = new node;
	rear = head;
	cout << "请输入字符" << endl;
	while (cin >> ch, ch != '$')
	{
		s = new node;
		s->data = ch;
		rear->next = s;
		rear = s;
	}
	rear->next = NULL;
	pointer p;
	p = head->next;
	cout << "原链表如下：" << endl;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return head;
}
void printlklist(lklist head)
{
	pointer p, q;
	p = head->next;
	head->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		q->next = head->next;
		head->next = q;
	}
	lklist L = head->next;
	cout << "逆置后按正序输出" << endl;
	while (L != NULL)
	{
		cout << L->data << " ";
		L = L->next;
	}
}
int main()
{
	lklist head = NULL;
	head = creat();
	printlklist(head);
	return 0;
}
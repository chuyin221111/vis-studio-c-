
#include <iostream>
using namespace  std;
typedef char datatyper;
typedef struct node* pointer;
struct node{
	datatyper data;
	pointer next;
};
typedef pointer lklist;

lklist  destroy(lklist head)
{
	pointer p, q;
	p= head;
	while (p !=NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}
	return NULL;
}

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
	return head;
}
void printlklist(lklist head)//打印链表
{     
	lklist p = head->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}	
}
int main()
{
	lklist head=NULL;
	head=creat();
	printlklist(head);
	 lklist y=destroy(head);
	if (y==NULL)
	{
		cout << "销毁成功" << endl;
	}
	else
	{
		cout << "销毁失败" << endl;
	}
	return 0;
}

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

lklist creat()//β�巨
{    
	pointer head, rear, s;
	char ch;
	head = new node;
	rear = head;
	cout << "�������ַ�" << endl;
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
void printlklist(lklist head)//��ӡ����
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
		cout << "���ٳɹ�" << endl;
	}
	else
	{
		cout << "����ʧ��" << endl;
	}
	return 0;
}
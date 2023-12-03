/*��1�� ���û�����Ľ������һ����ȫ��������
���������ղ���������ɶ����������У��û�����@��ʾ���㣬
#��ʾ�����������Ҫ��
1)�ֱ����ȸ����и��ͺ���ķ�������ö�������
2)����ö�������Ҷ�ӽ��ĸ�����
3)�жϸö������Ƿ����н���ŵĶ��������ַ���
4)���ö����������������������������������и����������
���磺���û�����abcd@efg����������������ģ�
��
1)�ȸ�����Ϊ��abdgcef���и�����Ϊ��gdbaecf��
�������Ϊ��gdbefca
2)�ö�����Ҷ�ӽڵ����Ϊ3
3)�ö������д��ڷ������ַ�
4)���������������и���������Ϊ��fceabdg*/
#include <iostream>
using namespace std;
typedef  struct node* pointer;
const int maxsize = 100;
typedef char datatype;
struct node {
    datatype data;   //�Լ���ֵ
    pointer lchild, rchild;//lchild --����  rchild--�Һ���
};
typedef pointer bitree;
//����ʵ�����ɶ���
bitree level_creat() {	//�ɲ���������ɣ����ظ�ָ��
    char ch; int front, rear; pointer root, s;
    pointer Q[maxsize + 1];	//��ѭ�����У���Ч�±��1��maxsize
    root = NULL;		//�ÿն�����
    front = rear = 0;		//�ÿն���
    while (cin >> ch, ch != '#') { //�����ַ��������ǽ�������ѭ��
        if (ch != '@') {		//�����㣬�����½��
            s = new node;
            s-> data = ch;
            s-> lchild = s-> rchild = NULL;
        }
        else s = NULL;
        rear++; Q[rear] = s; 	//���ܽ���Ƿ�Ϊ�飬��Ҫ���
        if (rear == 1) { root = s; front = 1; } //��һ�����Ǹ�����������
        else {
            if (s && Q[front])	//���Ӻ�˫�׶��������㣬����֮
                if (rear % 2 == 0) Q[front]->lchild = s;//rear��ż��������
                else     Q[front]-> rchild = s; //rear���������Һ���
            if (rear % 2 == 1) front++; //��������Һ�����Ӻ�˫�׳���
        }
    }
    return root;
}
//����
void preordor(bitree t)
{
    if (t == NULL) return;
    cout << t->data ;
    preordor(t->lchild);
    preordor(t->rchild);
}
//����
void inorder(bitree t)
{
    if (t == NULL)return;
    inorder(t->lchild);
    cout << t->data ;
    inorder(t->rchild);
}
//����
void postoder(bitree t)
{
    if (t == NULL)return;
    postoder(t->lchild);
    postoder(t->rchild);
    cout << t->data;
}
//Ҷ�ӽ��
int  leaf(bitree t)
{
    int L, R;
    if (t == NULL) return 0;
    if (t->lchild == NULL && t->rchild == NULL)
        return 1;
    L=leaf(t->lchild);
    R=leaf(t->rchild);
    return L + R; 
}
//�ж��Ƿ�Ϊ�����ַ� �жϸö������Ƿ����н���ŵĶ��������ַ���
int detect(bitree t)
{   
    int x;
    if (t == NULL) return 1;  //����
    //���ʸ������������ַ������ü������
    if (t->data < '0' || t->data> '9')  return 0;
     //��������������Ϊ�٣����ü��������
    x = detect(t->lchild);
    if (x == 0)return 0;
    //����������
    x = detect(t->rchild);
    //�����������������
    return x;
}
//������������
void exchange(bitree t)
{
    pointer p;
    if (t == NULL) return;
    p = t->lchild;
    t->lchild = t->rchild;
    t->rchild = p;
    exchange(t->lchild);
    cout << t->data;
    exchange(t->rchild);
}
int main()
{
    cout << "���û����룺";
    bitree t = level_creat();
    cout << "�ȸ����У�";
    preordor(t);
    cout << "�и����У�";
    inorder(t);
    cout << "������У�";
    postoder(t);
    int sum=leaf(t);
    cout << "Ҷ�ӽ�����Ϊ" << sum << endl;
    if (!detect(t)) cout << "���������ڷ������ַ�" << endl;
    else cout << "���������н���ŵĶ�������" << endl;
    cout << "���������������и�������";
    exchange(t);
}
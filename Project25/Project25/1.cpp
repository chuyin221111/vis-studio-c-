/*（1） 将用户输入的结点存放在一棵完全二叉树上
（即：按照层次序列生成二叉树，其中，用户输入@表示虚结点，
#表示输入结束），要求：
1)分别用先根、中根和后根的方法输出该二叉树；
2)计算该二叉树的叶子结点的个数；
3)判断该二叉树是否所有结点存放的都是数字字符；
4)将该二叉树各结点的左右子树交换，交换后按照中根序列输出。
例如：若用户输入abcd@efg，则这棵树是这样的：
则：
1)先根序列为：abdgcef、中根序列为：gdbaecf、
后根序列为：gdbefca
2)该二叉树叶子节点个数为3
3)该二叉树中存在非数字字符
4)交换左右子树后，中根遍历序列为：fceabdg*/
#include <iostream>
using namespace std;
typedef  struct node* pointer;
const int maxsize = 100;
typedef char datatype;
struct node {
    datatype data;   //自己的值
    pointer lchild, rchild;//lchild --左孩子  rchild--右孩子
};
typedef pointer bitree;
//树的实现是由队列
bitree level_creat() {	//由层次序列生成，返回根指针
    char ch; int front, rear; pointer root, s;
    pointer Q[maxsize + 1];	//非循环队列，有效下标从1到maxsize
    root = NULL;		//置空二叉树
    front = rear = 0;		//置空队列
    while (cin >> ch, ch != '#') { //输入字符，若不是结束符则循环
        if (ch != '@') {		//非虚结点，建立新结点
            s = new node;
            s-> data = ch;
            s-> lchild = s-> rchild = NULL;
        }
        else s = NULL;
        rear++; Q[rear] = s; 	//不管结点是否为虚，都要入队
        if (rear == 1) { root = s; front = 1; } //第一个点是根，单独处理
        else {
            if (s && Q[front])	//孩子和双亲都不是虚结点，链接之
                if (rear % 2 == 0) Q[front]->lchild = s;//rear是偶数，左孩子
                else     Q[front]-> rchild = s; //rear是奇数，右孩子
            if (rear % 2 == 1) front++; //不论虚否，右孩子入队后，双亲出队
        }
    }
    return root;
}
//先序
void preordor(bitree t)
{
    if (t == NULL) return;
    cout << t->data ;
    preordor(t->lchild);
    preordor(t->rchild);
}
//中序
void inorder(bitree t)
{
    if (t == NULL)return;
    inorder(t->lchild);
    cout << t->data ;
    inorder(t->rchild);
}
//后序
void postoder(bitree t)
{
    if (t == NULL)return;
    postoder(t->lchild);
    postoder(t->rchild);
    cout << t->data;
}
//叶子结点
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
//判断是否为数字字符 判断该二叉树是否所有结点存放的都是数字字符；
int detect(bitree t)
{   
    int x;
    if (t == NULL) return 1;  //空树
    //访问根：若非数字字符，则不用检查子树
    if (t->data < '0' || t->data> '9')  return 0;
     //遍历左子树，若为假，则不用检查右子树
    x = detect(t->lchild);
    if (x == 0)return 0;
    //遍历右子树
    x = detect(t->rchild);
    //最后结果由右子树决定
    return x;
}
//交换左右子树
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
    cout << "请用户输入：";
    bitree t = level_creat();
    cout << "先根序列：";
    preordor(t);
    cout << "中根序列：";
    inorder(t);
    cout << "后根序列：";
    postoder(t);
    int sum=leaf(t);
    cout << "叶子结点个数为" << sum << endl;
    if (!detect(t)) cout << "该子树存在非数字字符" << endl;
    else cout << "该子树所有结点存放的都是数字" << endl;
    cout << "交换左右子树，中根遍历：";
    exchange(t);
}
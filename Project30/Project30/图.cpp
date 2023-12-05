/* �����⣨1����
�����û��Ӽ������������Ϣ����һ��ͼ�����ڽӾ����ʾ��
�û��������У�
1)�ܶ������n
2)ÿ����������֣�����A, B��
3)�ߵĶ˵��i��j��Ȩw
4)i��j��1��ʼ�����û������i=0ʱ����ʾ�������
����ͼ�����������Ϣ��
1)ͼ���ڽӾ���
2)ͼ�ı���
3)��ȱ���ͼ�����У��ö������������
4)��ȱ���ͼ�����У��ö������������
���磬���û����룺
1)�ܶ������n=5
2)ÿ���������ֱַ�ΪA B C D E
3)�ߵĶ˵��i��j��ȨwΪ��
      1 2 1
      1 3 2
      1 4 3
      3 5 4
      4 5 5
      0 0 0�����б�ʾ�ߵ����������
��ɵõ�ͼ��
�����Ϊ��
1)ͼ���ڽӾ���
         0 1 2 3 0
         1 0 0 0 0
         2 0 0 0 4
         3 0 0 0 5
         0 0 4 5 0
2)ͼ�ı�����e=5
3)��ȱ���ͼ�����У��ö��������������ABCED
4)��ȱ���ͼ�����У��ö��������������ABCDE*/
#include <iostream>
using namespace std;
const int nmax = 100; 		//���������ֵ������Ϊ100
typedef struct {
    char data[nmax + 1];	//������Ϣ��0�ŵ�Ԫ����
    int adjmat[nmax + 1][nmax + 1];
    //�ڽӾ���0��0�в���
    int n, e;			//�������ͱ���
} mat_graph;
int visited[nmax + 1] = {0};
typedef int datatype; //����Ԫ�����ͣ�����Ϊ����
const int maxsize = 100; //��������
typedef struct {
    datatype data[maxsize];
    int front, rear;
} sqqueue;
//��ʼ������
void init_sqqueue(sqqueue* sq) {
    sq-> front = sq->rear = 0; //����Ϊ-1��0~maxsize-1
}
//�жϿն�
int empty_sqqueue(sqqueue* sq) {
    if (sq-> rear == sq-> front) return 1;
    else return 0;
}
//���
int en_sqqueue(sqqueue* sq, datatype x) {
    if ((sq->rear + 1) % maxsize == sq->front) {
        cout << "�������������"; return 0;
    } //����
    else {
        sq->rear = (sq->rear + 1) % maxsize;
        sq->data[sq->rear] = x;
        return 1;
    }
}
//����
int de_sqqueue(sqqueue* sq, datatype* x) {
    if (sq->rear == sq->front) {
        cout << "�ӿգ����ܳ��ӣ�\n"; return 0;
    }	//����
    else {
        sq-> front = (sq->front + 1) % maxsize;
        *x = sq->data[sq->front];
        return 1;
    }
}
int gethead_sqqueue(sqqueue* sq, datatype* x) {
    if (sq-> rear == sq->front) {
        cout << "�ӿգ��޶�ͷ��ȡ��\n"; return 0;
    }
    else {    //ͷָ�����һ��λ�ò��Ƕ�ͷ
        *x = sq->data[(sq->front + 1) % maxsize];
        return 1;
    }
}

void creatgraph(mat_graph* ga) {  //��������������ڽӾ���
    int i, j, n, e, w;
    cin >> n;       //���붥����
    ga->n = n;
    //���붥����Ϣ�����������
    cout << "���붥��";
    for (i = 1; i <= n; i++) cin >> ga->data[i];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            ga->adjmat[i][j] = 0;   //�ڽӾ����ʼ��
    e = 0;
    cout << "����ߵĶ˺ŵ�i��j��w"<<endl;
    while (cin >> i >> j >> w, i > 0) {//����ߵĶ˵��i��j��Ȩw
        //�����ڽӾ���
        e++;     //�ۼƱ���
        ga->adjmat[i][j] = w;
        ga->adjmat[j][i] = w;
    }
    ga->e = e;
    cout << "ͼ���ڽӾ���" << endl;
    for (int k = 1; k <= n; k++)
    {
        for (int kk = 1; kk <= n; kk++)
        {
            cout << ga->adjmat[k][kk]<<" ";
            if (kk % n == 0)
            {
                cout << "\n";
            }
          
        }
    }
    cout << "ͼ�ı�����" << ga->e<<endl;
}
//���
void dfs(mat_graph* g, int v) {	//�ڽӾ�����DFS����
    int j;
    cout << g->data[v]; visited[v] = 1;	//���ʳ�����
    for (j = 1; j <= g->n; j++)		//�����ڵ㣬δ������ݹ�
        if (g->adjmat[v][j] != 0 && !visited[j])
            dfs(g, j);
        
}
//���
void bfs(mat_graph* g, int v) {	//�ڽӾ�����BFS����
    int j, n;
    int visited[nmax + 1] = { 0 };
    sqqueue Q;				//�������˳�����
    n = g-> n;
    init_sqqueue(&Q);
    cout << g->data[v];//��ʼ��
   visited[v] = 1;	//���ʳ�����
    en_sqqueue(&Q, v);  //���
    while (!empty_sqqueue(&Q)) {
        de_sqqueue(&Q, &v);
        for (j = 1; j <= n; j++) {
            if (g->adjmat[v][j] != 0 && !visited[j]) 
            {
                cout << g->data[j];
                visited[j] = 1;
                en_sqqueue(&Q, j);
               
            }
        }
       

    }
}
int main()
{
    mat_graph* ga = new mat_graph();
    creatgraph(ga);
    dfs(ga, 1);
    cout << endl;
    cout << "ͼ�Ĺ�����У�" << endl;
    bfs(ga, 1);

}
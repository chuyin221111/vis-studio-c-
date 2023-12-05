/* 必做题（1）：
根据用户从键盘上输入的信息生成一个图，用邻接矩阵表示。
用户的输入有：
1)总顶点个数n
2)每个顶点的名字，例如A, B等
3)边的端点号i、j和权w
4)i和j从1开始，当用户输入的i=0时，表示输入结束
生成图后，输出以下信息：
1)图的邻接矩阵
2)图的边数
3)深度遍历图的序列（用顶点名字输出）
4)广度遍历图的序列（用顶点名字输出）
例如，若用户输入：
1)总顶点个数n=5
2)每个顶点名字分别为A B C D E
3)边的端点号i、j和权w为：
      1 2 1
      1 3 2
      1 4 3
      3 5 4
      4 5 5
      0 0 0（此行表示边的输入结束）
则可得到图：
则输出为：
1)图的邻接矩阵
         0 1 2 3 0
         1 0 0 0 0
         2 0 0 0 4
         3 0 0 0 5
         0 0 4 5 0
2)图的边数：e=5
3)深度遍历图的序列（用顶点名字输出）：ABCED
4)广度遍历图的序列（用顶点名字输出）：ABCDE*/
#include <iostream>
using namespace std;
const int nmax = 100; 		//顶点数最大值，假设为100
typedef struct {
    char data[nmax + 1];	//顶点信息表，0号单元不用
    int adjmat[nmax + 1][nmax + 1];
    //邻接矩阵，0行0列不用
    int n, e;			//顶点数和边数
} mat_graph;
int visited[nmax + 1] = {0};
typedef int datatype; //队列元素类型，假设为整型
const int maxsize = 100; //队列容量
typedef struct {
    datatype data[maxsize];
    int front, rear;
} sqqueue;
//初始化队伍
void init_sqqueue(sqqueue* sq) {
    sq-> front = sq->rear = 0; //不能为-1，0~maxsize-1
}
//判断空队
int empty_sqqueue(sqqueue* sq) {
    if (sq-> rear == sq-> front) return 1;
    else return 0;
}
//入队
int en_sqqueue(sqqueue* sq, datatype x) {
    if ((sq->rear + 1) % maxsize == sq->front) {
        cout << "队满，不能入队"; return 0;
    } //上溢
    else {
        sq->rear = (sq->rear + 1) % maxsize;
        sq->data[sq->rear] = x;
        return 1;
    }
}
//出队
int de_sqqueue(sqqueue* sq, datatype* x) {
    if (sq->rear == sq->front) {
        cout << "队空，不能出队！\n"; return 0;
    }	//下溢
    else {
        sq-> front = (sq->front + 1) % maxsize;
        *x = sq->data[sq->front];
        return 1;
    }
}
int gethead_sqqueue(sqqueue* sq, datatype* x) {
    if (sq-> rear == sq->front) {
        cout << "队空，无队头可取！\n"; return 0;
    }
    else {    //头指针的下一个位置才是队头
        *x = sq->data[(sq->front + 1) % maxsize];
        return 1;
    }
}

void creatgraph(mat_graph* ga) {  //建立无向网络的邻接矩阵
    int i, j, n, e, w;
    cin >> n;       //读入顶点数
    ga->n = n;
    //读入顶点信息，建立顶点表
    cout << "输入顶点";
    for (i = 1; i <= n; i++) cin >> ga->data[i];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            ga->adjmat[i][j] = 0;   //邻接矩阵初始化
    e = 0;
    cout << "输入边的端号点i、j、w"<<endl;
    while (cin >> i >> j >> w, i > 0) {//读入边的端点号i、j和权w
        //建立邻接矩阵
        e++;     //累计边数
        ga->adjmat[i][j] = w;
        ga->adjmat[j][i] = w;
    }
    ga->e = e;
    cout << "图的邻接矩阵：" << endl;
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
    cout << "图的边数：" << ga->e<<endl;
}
//深度
void dfs(mat_graph* g, int v) {	//邻接矩阵上DFS遍历
    int j;
    cout << g->data[v]; visited[v] = 1;	//访问出发点
    for (j = 1; j <= g->n; j++)		//搜索邻点，未访问则递归
        if (g->adjmat[v][j] != 0 && !visited[j])
            dfs(g, j);
        
}
//广度
void bfs(mat_graph* g, int v) {	//邻接矩阵上BFS遍历
    int j, n;
    int visited[nmax + 1] = { 0 };
    sqqueue Q;				//假设采用顺序队列
    n = g-> n;
    init_sqqueue(&Q);
    cout << g->data[v];//初始化
   visited[v] = 1;	//访问出发点
    en_sqqueue(&Q, v);  //入队
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
    cout << "图的广度序列：" << endl;
    bfs(ga, 1);

}
/*��дһ���㷨����ϡ�����ת������Ԫ����������
���磬ϡ�����
����Ӧ����Ԫ���Ϊ��
m	n	t
1	1	1
1	3	3
2	2	5
3	4	9
4	3	9
��ˣ�������
1 0 3 0
0 5 0 0
0 0 0 9
0 0 9 0
��Ӧ���
1 1 1
1 3 3
2 2 5
3 4 9
4 3 9
*/
#include <iostream>
using namespace std;
typedef int datatype;
const int maxsize = 100;
int arr[maxsize][maxsize];
typedef struct {
	int i, j;
	datatype val;
}nodetype;
typedef struct {
	int m, n;
	int t;
	nodetype data[maxsize];
}spmatrix;
int main()
{
	spmatrix* s = new spmatrix();
	cout << "������ϡ����������\n";
	cin >> s->m;
	cout << "�����ϡ����������\n";
	cin >> s->n;
	cout << "������ľ���\n";
	for (int i = 0; i < s->m; i++)
	{
		for (int j = 0; j < s->n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] != 0)
			{
				 s->t++;
				 s->data[s->t].val=arr[i][j];
				 s->data[s->t].i = i+1;
				 s->data[s->t].j = j+1;
			}
		}
    }
	cout << "��Ԫ��Ϊ��\n";
	for (int k = 1; k <= s->t; k++)
	{
		cout << s->data[k].i <<" " << s->data[k].j <<" " << s->data[k].val << endl;
		
	}
    return 0;

}

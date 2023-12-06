/*С�ߵ�ѧУҪ����һ��ͼ��ǣ���ʦ��С��ȥ��һЩͬѧ�����飬����ͬѧ�Ƕ�ϲ������Щ�顣
С����ÿ��ͬѧд��һ���Լ�����������ISBN�ţ���֪����ÿ���鶼��Ψһ��ISBN�ţ�����
����ȥ�ұ��鷭�����濴��������Ȼ��һЩ������кܶ�ͬѧ��ϲ���������ͻ��ռ����ܶ��ظ���ISBN�š�
С����Ҫȥ�������ظ���ISBN�ţ���ÿ��ISBN��ֻ����һ����Ҳ��˵ͬ������ֻ��һ����ѧУ���ǹ����ŵģ���
Ȼ���ٰ���ЩISBN�Ŵ�С��������С�߽���������õ�ISBN��ȥ���ȥ���顣
����Э��С����ɡ�ȥ�ء��롰���򡱵Ĺ����������㷨���Բ���
ֱ�Ӳ�������ð�����򡢿������򡢼�ѡ�����򡢶����򡢶�·�鲢�����е���һ�֡�
 
�����ʽ��	
������2�У���1��Ϊһ������������ʾ��n��ͬѧ������飨n<=100������2����n���ÿո��������������
Ϊÿ��ͼ���ISBN�ţ�����ͼ���ISBN����1~1000֮�䣩��

�����ʽ��	
���Ҳ��2�У���1��Ϊһ��������k����ʾ��Ҫ����ٱ��飻��2��Ϊk���ÿո��������������Ϊ��С�������ź����
��Ҫ�����ͼ��ISBN�š�
*/
#include <iostream>
using namespace std;
const int maxsize = 100;	//���������������Ϊ100
typedef int datatype;	//����ؼ���Ϊint
typedef int othertype;
typedef struct {
	datatype key;		//�ؼ�����
	//othertype other;		//������
} rectype;				//��¼����
typedef rectype list[maxsize + 1];
//��������ͣ�0�ŵ�Ԫ���ã��������ã��硰�����ڡ���
int Partition(list R, int p, int q) {
	//��������R[p]��R[q]���֣����ػ��ֺ��׼��λ��
	int i, j;
	i = p;  j = q;   R[0] = R[i];
	//R[0]�������������׼(��������һ����¼)
	while (i < j) {
		while (R[j].key >= R[0].key && i < j) j--;
		//��������ɨ��
		if (i < j) { R[i] = R[j]; i++; }	//����R[i]��R[j]
		while (R[i].key <=R[0].key && i < j) i++;
		//��������ɨ��
		if (i < j) { R[j] = R[i]; j--; }	//����R[i]��R[j]
	}
	R[i] = R[0];			//����׼�Ƶ����λ��
	return i;
}
void QuickSort(list R, int s, int t) {
	//��R[s]��R[t]��������
	int i;
	if (s >= t) return;	//ֻ��һ����¼���޼�¼��������
	i = Partition(R, s, t);	//��R[s]��R[t]������
	QuickSort(R, s, i-1);	//�ݹ鴦��������
	QuickSort(R, i + 1, t);	//�ݹ鴦��������
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
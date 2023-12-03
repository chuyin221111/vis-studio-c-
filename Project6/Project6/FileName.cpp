#include <stdio.h>
#define SIZE 30
int main()
{
	float b[SIZE / 5], sum;
	int a[SIZE], i, j, k;
	for (k = 2, i = 0; i < SIZE; i++)
	{
		a[i] = k;
		k += 2;

	}
	sum = 0.0;
	for (k = 0, i = 0; i < SIZE; i++)
	{
		sum += a[i];
		j = i + 1;
		if ((i + 1) % 5 == 0)
		{
			b[k] = sum / 5;
			sum = 0;
			k++;
		}
	}
	printf("the result is :\n");
	for (i = 0; i < SIZE / 5; i++)
	{
		printf("%5.2f", b[i]);
	}

	return 0;
}
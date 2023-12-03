#include <stdio.h>
int main()
{
	int i, x, y; long last = 1;
	printf("input x and y:");
	scanf_s("%d%d", &x, &y);
	for (i = 1; i <= y; i++);
	last = last * x % 1000;
	printf("the last 3 digits:%d\n", last);
	return 0;
}
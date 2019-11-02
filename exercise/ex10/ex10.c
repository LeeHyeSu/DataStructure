#include<stdio.h>
int main()
{
	int n = 0;
	int total = 0;

	while (total <= 1000 * (n*n) + 1000 ) 
	{
		total += 2 * n;
		n++;
	}

	printf("%d\n", n);
}
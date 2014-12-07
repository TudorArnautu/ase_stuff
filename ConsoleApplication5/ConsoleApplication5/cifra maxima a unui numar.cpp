#include <stdio.h>

void main()
{

	int n, max=0,a;

	printf("n="); scanf("%d", &n);
	a = n;
	while (n > 0)
	{
		if (n % 10 > max)
			max = n % 10;
		n = n / 10;
	}
	
		printf("Maximul numarului %i este %i", a, max);
}
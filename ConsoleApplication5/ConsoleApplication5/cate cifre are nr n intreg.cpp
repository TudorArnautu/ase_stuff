#include <stdio.h>

void main()
{
	int n, nr_cifre = 0, a;

	printf("n="); scanf("%d", &n);
	a = n;
	
	while (n > 0)
	{
		n = n / 10;
		nr_cifre = nr_cifre + 1;
	}
	printf("Numarul %i are %i cifre.", a, nr_cifre);
}
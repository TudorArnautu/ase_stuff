#include <stdio.h>

int main()
{
	int n, nr = 0, a;

	printf("n="); scanf("%d", &n);

	a = n;

	while (n > 0)
	{
		n = n / 10;
		nr = nr + 1;
	}
	printf("Numarul %i are %d cifre.", a, nr);

	return 0;
}
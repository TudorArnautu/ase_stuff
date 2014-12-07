#include <stdio.h>

int main()
{
	int n, suma=0, c;

	printf("n="); scanf("%d", &n);

	while (n > 0)
	{
		c = n % 10;
		if (c % 2 == 1)
			suma = suma + c;
		n = n / 10;
	}
	printf("Suma nr impare este %d", suma);

	return 0;
}
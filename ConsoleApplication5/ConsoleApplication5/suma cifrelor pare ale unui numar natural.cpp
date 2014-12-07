#include <stdio.h>

void main()
{
	int n, suma=0, c;

	printf("n="); scanf("%d", &n);

	while (n > 0)
	{
		c = n % 10;
		if (c % 2 == 0)
			suma = suma + c;
		n = n / 10;
	}
	printf("Suma cifrelor pare este %i", suma);
}
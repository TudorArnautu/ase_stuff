#include <stdio.h>

void main()
{
	int nr, max=0, c, a;

	printf("nr="); scanf("%d", &nr);
	a = nr;
	max = max % 10;
	nr = nr / 10;
	while (nr > 0)
	{
		c = nr % 10;
		if (c > max)
			max = c;
		nr = nr / 10;
	}
	printf("Cifra maxima a numarului %i este %i", a, max);
}
#include <stdio.h>

int main()
{
	int nr, max, a,c;

	printf("nr="); scanf("%d", &nr);

	a = nr;
	max = nr% 10;
	nr = nr / 10;
	while (nr > 0)
	{
	 c=nr % 10;
	 if (c > max)
		 max = c;
		 nr = nr / 10;

	}
	printf("Cifra maxima a numarului %d este %d ", a, max);

	return 0;
}
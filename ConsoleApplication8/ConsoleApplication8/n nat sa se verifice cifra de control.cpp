#include <stdio.h>

void main()
{
	int nr, suma, c, a;

	printf("nr="); scanf("%d", &nr);

	a = nr;

	while (nr >= 10)
	{
		suma = 0;
		while (nr > 0){
			c = nr % 10;
			suma = suma + c;
			nr = nr / 10;
		}
		nr = suma;
	}
	printf("Cifra de control al numarului %d este %d", a, nr);
}
#include <stdio.h>

void main()
{
	int nr, ogl, a, c;

	printf("nr="); scanf("%d", &nr);
	a = nr;
	ogl = 0;

	while (nr > 0)
	{
		c = nr % 10;
		nr = nr / 10;
		ogl = ogl * 10 + c;
	}
	printf("Oglinditul numarului %i este %i.\n", a, ogl);
}



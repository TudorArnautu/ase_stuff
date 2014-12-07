#include <stdio.h>

void main()
{
	int nr, c, ogl, a;

	printf("nr="); scanf("%d", &nr);

	a = nr;
	ogl = 0;

	while (nr > 0)
	{
		c = nr % 10;
		ogl = ogl * 10 + c;
		nr = nr / 10;
	}
	if (ogl==a)
	printf("Numarul %d este palindrom", a);
	else 
		printf("Numarul %d nu este palindrom", a);
}
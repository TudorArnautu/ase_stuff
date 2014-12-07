# include <stdio.h>

void main()
{
	int nr, ogl, c, a;

	printf("nr="); scanf("%d", &nr);
	a = nr;
	ogl = 0;
	while (nr > 0)
	{
		c = nr % 10;
		ogl = ogl * 10 + c;
		nr = nr / 10;
	}
	printf("Oglinditul numarului %i este %i", a, ogl);
}
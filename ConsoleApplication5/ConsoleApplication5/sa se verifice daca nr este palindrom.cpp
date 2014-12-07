# include <stdio.h>

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
	if (ogl == a)
		printf("Numarul %i este palindrom.", a);
	else
		printf("Numarul %i nu este palindrom.", a);
}
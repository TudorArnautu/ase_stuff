# include <stdio.h>

void main()
{
	int nr, s, c;

	printf("nr="); scanf("%d", &nr);
	
	while (nr >= 10)
	{
		s = 0;
		while (nr > 0)
		{
			s = s + (nr % 10);
			nr = nr / 10;
		}
		nr = s;
	}
	printf("Cifra de control este %i", nr);
}
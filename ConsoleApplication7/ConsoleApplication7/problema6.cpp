//Se citesc de la tastaturã patru numere, sã se afiºeze cel mai mare

#include <stdio.h>

void main()
{
	float a, b, c, d, max;

	printf("a="); scanf("%f", &a);
	printf("b="); scanf("%f", &b);
	printf("c="); scanf("%f", &c);
	printf("d="); scanf("%f", &d);

	max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	if (d > max)
		max = d;

	printf("Cel mai mare numar este %5.1f", max);
}
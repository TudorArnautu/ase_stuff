//Se citesc de la tastatur� patru numere, s� se afi�eze cel mai mare

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
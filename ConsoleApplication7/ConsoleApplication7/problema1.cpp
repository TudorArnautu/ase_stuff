//Se citesc de la tastatur� dou� numere, s� se afi�eze cel mai mare

#include <stdio.h>

void main()
{
	float a, b, max;

	printf("a="); scanf("%f", &a);
	printf("b="); scanf("%f", &b);

	max = a;
	if (b>max)
		max = b;

	printf("Cel mai mare numar este %5.1f", max);

}
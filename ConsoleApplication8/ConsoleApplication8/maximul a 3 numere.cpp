#include <stdio.h>

int main()
{
	float a, b, c, max;

	printf("a="); scanf("%f", &a);
	printf("b="); scanf("%f", &b);
	printf("c="); scanf("%f", &c);

	max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	printf("Maximul este %4.2f ", max);

	return 0;
}
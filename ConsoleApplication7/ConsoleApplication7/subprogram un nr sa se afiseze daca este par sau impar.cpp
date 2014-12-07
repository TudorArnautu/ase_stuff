#include <stdio.h>

void numar(int n)
{
	if (n % 2 == 0)
		printf("Numar par");
	else
		printf("Numar impar");
}

void main()
{
	numar(7);
}
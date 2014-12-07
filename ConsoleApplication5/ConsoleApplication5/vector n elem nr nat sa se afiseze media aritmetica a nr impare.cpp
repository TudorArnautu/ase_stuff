#include <stdio.h>
#include <conio.h>

void main()
{
	int v[100], n, i, p;
	float ma, suma;

	printf("n="); scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("v[%i]", i); scanf("%f", & v[i]);
	}

	suma = 0;
	p = 0;

	for (i = 0; i < n; i++)
	if (v[i] % 2 == 1)
	{
		suma = suma + v[i];
		p = p + 1;
	}
	ma = suma / p;
	printf("Media aritmetica a numerelor impare este %5.2f", ma);
}
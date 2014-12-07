#include <stdio.h>

void main()
{
	int v[100], nr, i, p;
	float suma, ma;

	printf("nr="); scanf("%d", &nr);

	for (i = 0; i < nr; i++)
	{
		printf("v[%i]=", i); scanf("%d", &v[i]);
	}
	suma = 0;
	p = 0;

	for (i = 0; i < nr;i++)
	if (v[i] % 2 == 1)
	{
		suma = suma + v[i];
		p = p + 1;
	}
	ma = suma / p;

	printf("Media aritmetica a nr impare este %5.2f. ", ma);
	
}
#include<stdio.h>

void main()
{
	int v[100], i, nr, produs, suma;

	printf("nr="); scanf("%d", &nr);

	for (i = 0; i < nr; i++)
	{
		printf("v[%i]=", i); scanf("%d", &v[i]);
	}
	suma = 0;
	produs = 1;

	for (i = 0; i < nr; i++)
	{
		if (v[i] % 3 == 0){
			suma = suma + v[i];
		}
		if (v[i] % 7 == 0){

			produs = produs*v[i];
		}
	}
	printf("Suma nr divizibile cu 3 este %i si produsul nr divizibile cu 7 este %i.\n", suma, produs);
}
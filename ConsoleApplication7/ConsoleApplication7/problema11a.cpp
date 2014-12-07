//ordonare crescator bubble sort

#include <stdio.h>

int main()
{
	float v[100], aux;
	int i, n, ok;

	printf("n="); scanf("%d", &n);

	for (i = 0; i < n; i++){
		printf("v[%i]=", i); scanf("%f", &v[i]);
	}
	do{
		ok = 0;
		for (i = 0; i < n - 1; i++)
		if (v[i]>v[i + 1]){
			aux = v[i + 1];
			v[i + 1] = v[i];
			v[i] = aux;
			ok = 1;
		}
	} while (ok == 1);
	for (i = 0; i < n; i++)
		printf("%5.1f ", v[i]);
	return 0;
}
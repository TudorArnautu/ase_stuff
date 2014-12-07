#include<stdio.h>
#include<malloc.h>
void main()
{
	float *x, a;
			int n, ls, ld, mij, gasit, i;
	printf("n="); scanf("%d", &n);
	x = (float*)malloc(n*sizeof(float));
		for (i = 0; i < n; i++){ printf("x[%d]=", i); scanf("%f", &x[i]); }
	printf("a="); scanf("%f", &a);
	ls = 0; ld = n - 1; gasit = 0;
	do{
		mij = (ls + ld) / 2;
		if (x[mij] == a)gasit = 1;
		else if (x[mij] < a) ls = mij + 1;
		else ld = mij - 1;
	} while (ld >= ls&&!
		gasit);
	if (gasit) printf("poziti este:%d", mij);
	else printf("valoarea nu se gaseste in vector");
	free (x);
}

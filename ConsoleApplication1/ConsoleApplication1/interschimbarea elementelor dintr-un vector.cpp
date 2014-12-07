#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void main(void)
{
	int *x, aux, n, i;
	printf("n="); scanf("%d", &n);
	x = (int*)malloc(n*sizeof(int));
	for (i = 0; i < n; i++){ printf("x[%d]=", i); scanf("%d", &x[i]); }
	for (i = 0; i < n / 2; i++){ aux = x[i]; x[i] = x[n - i - 1]; x[n - i - 1] = aux; }
	for (i = 0; i < n; ++i){ printf("\nx[%i]=%i", i, x[i]); } getch();
	free(x);
}
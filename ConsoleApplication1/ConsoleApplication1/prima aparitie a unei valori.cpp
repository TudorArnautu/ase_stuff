#include<stdio.h>
#include<malloc.h>
void main()
{
	int n, i;
	float *x, a;
	printf("n="); scanf("%d", &n);
	x = (float*)malloc(n*sizeof(float));
	for (i = 0; i < n; i++){ printf("x[%d]=", i); scanf("%f", &x[i]); }printf("a=");
	scanf("%f", &a);
	i = 0;
	while ((i < n)&&(x[i] != a))i++;
	if (i == n)printf("val cautata nu exista in vector");
	else printf("prima aparitie a nr %5.2f este pozitia %d", a, i);
	free(x);
}
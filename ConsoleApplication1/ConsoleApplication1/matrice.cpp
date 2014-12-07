#include<stdio.h>
#include<malloc.h>

void main()
{
	float **a, *s;
	int n, m, i, j;
	printf("n="); scanf("%i", &n);
	printf("m="); scanf("%i", &m);
	i= (float**)malloc(n*sizeof(float*));
	for (i = 0; i < n; i++)
		a[i] = (float*)malloc(m*sizeof(float));
	for (i = 0; i < n;i++)
	for (j = 0; j < m; j++)
	{ 
		printf("a[%i][%i]=", i, j); scanf("%f", &a[i][j]);
	}
	s = (float*)malloc(n*sizeof(float);
	int p = 0; k;
	for (i=0;i<n-1;i++)
	for (k = i + 1; k < n; k++)
	{
		s[p] = 0;
		for (j = 0; j < m; j++)
			s[p] += a[i][j] * a[k][j];
		P++;
	}
	for (i = 0; i < p; i++)
		printf("%5.1f", s[i]);
	free(s);
	for (i=0

}
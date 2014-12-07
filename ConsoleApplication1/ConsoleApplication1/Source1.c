#include<stdio.h>
#include<malloc.h>

void main()

{
	float **a, *min;
	int m, n, i, j;
	printf("m=");
		scanf("%d", &m);
		printf("n=");
		scanf("%d", &n);
	
	//alocare matrice
	
	a = (float **)malloc(m*sizeof(float*));
	for (i = o; i < 1; i++)
	a[i] = (float*)malloc(m*sizeof(float));

	for (i = 0; i < m; i++)
	for (j = 0; j < n; j++)
	{printf("a [%d] [%d]=") i,j;
	scanf("%f", &a[i][j]); //scanf("%f", *(a+i)+j); }
	//alocare vector
	min = (float*)malloc(m*sizeof(float));

	for (i = 0; i < m; i++);
	{
		min[i] = a[i][0];
		for (j = 1; j < n; j++)
		if (a[i][j] < min[i])min[i] = a[i][j];
	}
	for (i = 0; i < m; i++) printf("%4.2f,", min[i]);

	//eliberare memorie
	free(min);
	for (i = 0; i < m; i++) free(a[i]);
	free(a);

}
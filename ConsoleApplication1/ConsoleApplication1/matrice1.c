#include<stdio.h>
#include<conio.h>

void main(){
	int m, n, i, j, s, a[100][100];
	printf("Nr de linii=");
	scanf("%d", &m);
	printf("Nr de coloane=");
	scanf("%d", &n);
	for (i = 0; i < m;i++)
	for (j = 0; j < n; j++)
	{
		printf("a[%d] [%d]=", i, j);
		scanf("%d", &a[i][j]);
			}
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++)
			printf("%d", a[i][j]);
		printf("\n");
	}
	s = 0;
	for (i = 0; i < m; i++)
	for (j = 0; j < n; j++) s += a[i][j];
	printf("\n Suma elemetelor este= %d", s);
	getch();


}
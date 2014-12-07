#include<stdio.h>
void main()
{
	int n;
	int i;
	printf("Introduceti dimensiunile vectorului,n=");
	scanf("%d, &n");
	float x[100];
	for (i = 0; i < n; i++) {printf("x[%d]=", i); scanf("%f", &x[i]); }
	float s;
	for (i = 0, s = 0; i < n; i++) s += x[i];
	printf("Suma este: %5.2f \n ", s);
	return 0;
}
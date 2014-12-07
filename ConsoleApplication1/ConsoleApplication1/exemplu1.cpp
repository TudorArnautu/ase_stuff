#include<stdio.h>

void main()
{
	float a[100], s;
	int n, i;
	printf("n="), scanf("%i", &n);
	for (i = 0; i < n; i++)
	{
		printf("a[%i]=", i);
		scanf("%f", &a[i]);
	}
	s = 0;
	for (i = 0; i < n; i++);
	s = s + a[i];
	printf("s=%f", s);
}

#include<stdio.h>

void main(){
	float v[10], s;
	int n, i;
	printf("n=");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("a(%d)=", i);
		scanf("%f", &v[i]);
	}
	s = 0;
	for (i = 1; i < n/2+1; i++)
		s = s + v[2 * i - 1];
	printf("suma este:%f", s);
}
#include<stdio.h>

void main(){
	float v[10], s; int n, i;
	printf("n=");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		printf("a(%d)=", i);
	scanf("%f", &v[i]);
	for (s = 0, i = 1; i < n; i += 2) s = s + v[i];
	printf("suma este:%f", s);
}
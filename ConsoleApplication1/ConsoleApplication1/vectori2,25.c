#include<stdio.h>
void main(){
	float v[100], s; int n, i;
	printf("n="); scanf("%d", &n);
	for (i = 0; i < n; i++) { printf("a(%d)=", i); scanf("%f", &v[i]); }
	s = 0; i = 1;
	do{ s = s + v[i]; i = i + 2; } while (i < n);
	printf("suma este:%f", s);
}
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
		for (i = 0; i < n;i++)
		if ((i % 2) != 0) s = s + v[i];
		printf("suma este:%f", s);
	
}
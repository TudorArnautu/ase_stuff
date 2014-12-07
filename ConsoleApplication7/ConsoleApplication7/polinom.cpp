//valoarea unui polinom

#include <stdio.h>
int main()
{
	float a[100], s;
	int i, n, p, x;

	printf("n="); scanf("%d", &n);
	printf("x="); scanf("%d", &x);

	for (i = 0; i < n; i++){
		printf("a[%i]=", i); scanf("%f", &a[i]);
	}
	s = 0;
	p = 1;
	for (i = 0; i < n; i++){
		s = s + a[i] * p;
		p = p*x;
	}
	printf("Valoarea polinomului este %5.2f ", s);
	return 0;
}

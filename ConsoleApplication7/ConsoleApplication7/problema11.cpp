//ordonare crescator

#include <stdio.h>

int main()
{
	float a, b, c, aux;

	printf("a="); scanf("%f", &a);
	printf("b="); scanf("%f", &b);
	printf("c="); scanf("%f", &c);

	if (a > b){
		aux = b;
		b = a;
		a = aux;
	}
	if (a > c){
		aux = c;
		c = a;
		a = aux;
	}
	if (b > c){
		aux = c;
		c = b;
		b = aux;
	}
	printf("%5.1f %5.1f %5.1f", a, b, c);
	return 0;

}

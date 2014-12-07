//gradul 2

#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c, x1, x2, D;

	printf("a="); scanf("%f", &a);
	printf("b="); scanf("%f", &b);
	printf("c="); scanf("%f", &c);

	if (a == 0)
	if (b == 0)
	if (c == 0)
		printf("x1 si x2 apartin lui R");
	else
		printf("ecuatie imposibila");

	else if (c == 0)
		printf("x1=x2=0");
	else {
		x1 = x2 = -c / b;
		printf("%5.1f %5.1f", x1, x2);
	}
	else {
		D = b*b - 4 * a*c;
		if (D > 0){
			x1 = (-b + sqrt(D)) / 2 * a;
			x2 = (-b - sqrt(D)) / 2 * a;
			printf("%5.1f %5.1f", x1, x2);
		}
		else if (D == 0){
			x1 = x2 = -b / 2 * a;
			printf("%5.1f %5.1f", x1, x2);
		}
		else printf("nu are solutii reale");

	}
	return 0;
}
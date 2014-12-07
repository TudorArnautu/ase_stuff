//ecuatia de gradul 1

#include <stdio.h>

int main()

{
	float a, b, x;

	printf("a="); scanf("%f", &a);
	printf("b="); scanf("%f", &b);

	if (a == 0)
		if (b == 0)
			printf("x apartine multimii numerelor reale");
		else printf("ecuatie imposibila");

	else if (b == 0)
			printf("x=0");
	else {
		x = -b / a;
		printf("%5.1f",x);
	}
	return 0;
}
#include <stdio.h>

void main() {
	float a, b, c;               //e de pe net, nu stiu sa o fac, da eroare si nu stiu ce sa ii fac

	printf("a="); scanf("%f", &a);
	printf("b="); scanf("%f", &b);
	printf("c="); scanf("%f", &c);

	if (a < (b + c) && b < (a + c) && c < (a + b)) {
		if (a == b && b == c) {
			printf(" triunghi echilateral");
		}
		else {
			if (a == c || a == b || b == c) {
				printf(" triunghi isoscel");
			}
			else {
				if ((a*a == b*b + c*c) || (b*b == a*a + c*c) || (c*c == a*a + b*b)) {
					printf(" triunghi dreptunghic isoscel");
				}
				else {
					printf(" triunghi dreptunghic");
				}
			}
		}
		//		else {
		//			printf(" triunghi oarecare");
		//		}
	}
	else {
		printf("pct nu formeaza un triunghi");
	}
}
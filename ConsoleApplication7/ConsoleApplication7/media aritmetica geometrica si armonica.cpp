#include<stdio.h>
#include<math.h>

int main()
{
	float x, y;

	printf("x="); scanf("%f", &x);
	printf("y="); scanf("%f", &y);

	printf("Media aritmetica este=%f\n", (x + y) / 2);
	printf("Media geometrica este=%f\n", sqrt(x*y));
	printf("Media armonica este=%f\n", 2 * x*y / (x + y));
}
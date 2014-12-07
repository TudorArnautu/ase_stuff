#include<stdio.h>

int main() {
	int a = 4;
	int b = 5;
	int c;
	c = a;
	a = b;
	b = c;
	
	
		printf("%d %d %d", a, b, c);

		return  0;
}
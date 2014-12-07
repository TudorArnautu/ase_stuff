#include<stdio.h>

int main(){
	int a = 8;
	int b = 3;
	int c;

	c=a + b;
	printf("Rezultatul adunarii:%d\n", c);

	c = a - b;
	printf("Rezultatul scaderii:%d\n", c);

	c = a*b;
	printf("Rezultatul inmultirii:%d\n", c);

	c = a / b;
	printf("Catul: %d\n", c);
		
	c = a % b;
	printf("restul impartirii:%d\n", c);
	return 0; 
}
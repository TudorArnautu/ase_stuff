#include <stdio.h>

bool numar(int n)
{
	if (n > 0) return true;
	if(n<0) return false;
		
	if (n == 0)
		printf("Numarul este nul");
	

}

void main()
{
	numar(0);
}
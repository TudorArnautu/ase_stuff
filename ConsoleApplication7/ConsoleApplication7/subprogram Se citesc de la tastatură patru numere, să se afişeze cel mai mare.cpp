#include <stdio.h>

int max(int num1, int num2, int num3, int num4);

int main()
{
	int a = 64;
	int b = 65;
	int c = 8;
	int d = 6;
	int ret;

	ret = max(a, b, c, d);

	printf("Maximul este %d", ret);

	return 0;
}

int max(int num1, int num2, int num3, int num4)
{
	int result;

	result = num1;
	if (num2 > result){
		result = num2;
		}

	if (num3 > result){
		result = num3;
		}

	if (num4 > result){
		result = num4;
		}

	return result;
}
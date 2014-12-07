#include<stdio.h>

int max(int num1, int num2, int num3);

	int main()
	{
		int a = 20;
		int b = 40;
		int c = 331;
		int ret;

		ret = max(a, b, c);
		printf("Maximul este %d", ret);

		return 0;

	}

	int max(int num1, int num2, int num3)
	{
		int result;

		result = num1;
		if (num2 > result)
			result = num2;
		if (num3 > result)
			result = num3;

		return result;
	}

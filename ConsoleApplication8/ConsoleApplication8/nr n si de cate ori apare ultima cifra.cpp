#include <stdio.h>

int get_result(int);

int main()
{
	int nr, c;

	printf("nr=");
	scanf("%d", &nr);

	printf("result %d\n", get_result(nr));

	return 0;
}



int get_result(int number) {
	int c, first_digit, occurences = 1;
	bool first_step = true;

	while (number > 0){
		c = number % 10;

		if (first_step) {
			first_digit = c;

			first_step = false;
		}
		else {
			if (c == first_digit) {
				occurences++;
			}
		}

		number = number / 10;
	}

	return occurences;
}
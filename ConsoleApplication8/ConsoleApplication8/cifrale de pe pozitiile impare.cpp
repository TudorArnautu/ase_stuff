#include <stdio.h>

int get_result(int);
int get_pow(int, int);
int build_number(int, int);
int get_digits(int);


int main() {
	int nr, result;

	printf("nr= ");
	scanf("%d", &nr);

	result = get_result(nr);

	printf("\nRezultatul e %d\n", result);

	return 0;
}

int get_result(int nr) {
	int c, i = 0, result = 0;
	/*
	// citesc cifra cu cifra
	while (nr > 0) {
		// a cata cifra sunt. pozitia ei
		i++;

		c = nr % 10;

		if (i % 2) {
			result = build_number(result, c);
		}

		nr = nr / 10;
	}
	*/
	int step = 0;
	int digits = get_digits(nr);
	printf("digits %d\n", digits);
	for (i = digits - 1; i > 0; i--) {
		step++;
		int pow_i = get_pow(10, i);

		c = nr / pow_i;

		nr = nr - (c * pow_i);

		if (step % 2) {
			result = build_number(result, c);
		}
	}

	step++;

	// the last number
	if (step % 2) {
		result = build_number(result, nr);
	}

	return result;
}

int build_number(int first, int second) {
	return (first * get_pow(10, get_digits(second))) + second;
}

int get_digits(int number) {
	int i = 0;

	while (number > 0) {
		i++;

		// a cata cifra sunt. pozitia ei
		number /= 10;
	}

	return i;
}

int get_pow(int number, int power) {
	int i = 1;

	int result = number;

	for (i = 1; i < power; i++) {
		result *= number;
	}

	return result;
}

/*

1. despart numarul initial in cifre
2. pentru fiecare cifra din pozitiile impare, creez alt numar din cifrele alea

- o functie care sa determine cate cifre are un numar
- o functie care din 2 nr sa rezulte un numar prin alaturarea cifrelor
-
*/
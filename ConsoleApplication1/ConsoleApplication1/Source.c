#include <stdio.h>

int maind() {
	int elem[] = { 1, 2, 3, 4, 5, 6 };
	char a = 'a';
	unsigned int uint = 3;
	int n = 6;
	int k = 3;
	int i = 0;
	/*
	for (i = 0; i < 6; i++) {
		if (elem[i] == k) {
			printf("%d\n", i);
		}
	}
	*/

	while (i < n && elem[i] != k) {
		i++; // i += 1; i = i + 1;
	}

	if (i >= n) {
		printf("nu\n");
	}
	else {
		printf("%d\n", i);
	}

	return 0;
}
#include<stdio.h>

int suma(int y[10], int m) {
	int i, suma = 0;

	for (i = 0; i < m; i++) {
		suma += y[i];
	}

	return suma;
}

int mainlf() {
		int w, n, i, x[10];

		printf("Culege marimea masivului n<10\n");
		scanf("%d", &n);
		printf("Culege masivul x[%d]\n", n);

		for (i = 0; i < n; i++) {
			printf("Culege elementul x[%d]\n", i);
			scanf("%d", &x[i]);
		}

		w = suma(x, n);
		printf("suma = %d\n", w);

		return 0;
}

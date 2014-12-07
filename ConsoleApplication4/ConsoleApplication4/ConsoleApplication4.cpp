#include <stdio.h>

int main() {
	int a[30][30];
	int i, j, m, n;

	printf("Numarul de studenti este= "); scanf("%i", &m);
	printf("Numarul de discipline= "); scanf("%i", &n);

	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			printf("a[%i][%i]=", i, j);
			scanf("%d", &a[i][j]);
		}
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (a[i][j] < 5) {
				printf("Studentul %d e restant la %d\n", i, j);
			}
		}
	}

	return 0;
}
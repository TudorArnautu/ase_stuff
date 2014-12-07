#include <stdio.h>

void printezaRestantierii(int **a, int m, int n) {
	int i; int j;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (a[i][j] < 5) {
				printf("Studentul %i e restant la %i", i, j);
			}
		}
	}
}

int main() {
	float a[30][30];
	int i, j, m, n;

	printf("Numarul de studenti este= "); scanf("%i", &m);
	printf("Numarul de discipline= "); scanf("%i", &n);

	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			printf("a[%i][%i]=", i, j); scanf("%i", a[i][j]);
		}
	}

	printeazaRestantierii(a, i, j);

	return 0;
}
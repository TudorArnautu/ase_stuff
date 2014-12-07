#include <stdio.h>

bool search_bin(int search, int arr[], int i, int j) {
	if (j - i <= 1) {
		return false;
	}
	printf("%d %d\n", i, j);
	int middle = (i + j) / 2;

	if (arr[middle] == search) {
		return true;
	}

	bool found = search_bin(search, arr, i, middle);
	if (!found) {
		found = search_bin(search, arr, middle, j);
	}

	return found;
}

int main() {
	int arr[10];
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;

	bool found = search_bin(10, arr, 0, 4);

	if (found) {
		printf("da waa!");
	}

	printf("nu waaa");

	return 0;
}
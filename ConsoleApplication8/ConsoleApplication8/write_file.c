#include <stdio.h>

void printToFile(const char*);
void printFromFile(const char*);

int main() {
	char *filename = "mine_file.txt\0";

	printToFile(filename);
	printFromFile(filename);

	return 0;
}

void printToFile(const char *filename) {
	int i;
	FILE* out = fopen(filename, "w");

	if (out == NULL) {
		return;
	}

	for (i = 0; i < 100; i++) {
		fprintf(out, "%d\n", i);
	}

	fclose(out);
}


void printFromFile(const char *filename) {
	int nr;
	FILE* in = fopen(filename, "r");

	if (in == NULL) {
		return;
	}

	while (!feof(in)) {
		fscanf(in, "%d", &nr);
		printf("Am gasit %d\n", nr);
	}

	fclose(in);
}
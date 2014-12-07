#include <stdio.h>

void printToFile(const char*, int);

int main() {
	char *filename = "mine_file.txt\0";
	int nr;
	printf("nr="); 
	scanf("%d", &nr);

	printToFile(filename, nr);

	return 0;
}
void printToFile(const char *filename, int nr) {
	int c;
	FILE* out = fopen(filename, "w");
	fprintf(out, "%d\n", nr);
	while (nr > 0){
		c = nr % 10;
		nr = nr / 10;
		if (c % 2) {
			fprintf(out, "%d\timpar\n", c);
		}
		else {
			fprintf(out, "%d\tpar\n", c);
		}									
	}

	fclose(out);
}
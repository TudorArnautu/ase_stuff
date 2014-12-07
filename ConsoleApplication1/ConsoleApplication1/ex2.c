#include <stdio.h>
#include"Header.h"


int main(){
	int numbers[10];
	int size = 0;
	int search;
	
	printf("Numarul de elemente este: ");
	scanf("%d", &size);
	
	int i = 0;
	for (i = 0; i < size; i++) {
		printf("Valoarea lui numbers[%d} e: ", i);
		scanf("%d", &numbers[i]);
	}
	printf("Numarul cautat e:");
	scanf("%d", &search);

	int j = 0;

	for (i = 0; i < size; i++){
		if (numbers[i] == search){
			for (j = i; j < size; j++){
				numbers[j] = numbers[j + 1];
			}
			size -= 1;
		}
	}
	printNumbers(numbers, size);

	return 0;
}
void printNumbers(int numbers[], int size){
	int i;
	for (i = 0; i < size; i++){
		printf("%d ", numbers[i]);
	}
		
}
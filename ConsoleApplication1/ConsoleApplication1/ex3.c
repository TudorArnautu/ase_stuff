#include <stdio.h>

int main() {
	int numbers[20];
	unsigned int size = 0; 
	int numbers2[30];
	unsigned int size2 = 0;
	int results[10];
	int k = 0;

	printf("Numarul de elemente este: ");
	scanf("%d", &size);

	unsigned int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("Valoarea lui numbers[%d] e: ", i);
		scanf("%d", &numbers[i]);
	}
	
	
	printf("Numarul de elemente este: ");
	scanf("%d", &size2);

	unsigned int j = 0;
	for (j = 0;j  < size2; j++)
	{
		printf("Valoarea lui numbers2[%d] e: ", j);
		scanf("%d", &numbers2[j]);
	}
	
	i = 0;
	j = 0;

	while (i < size && j < size2)
	{
		if (numbers[i] < numbers2[j]){
				results[k] = numbers[i];
				i++; k++;
		}
		else{
			results[k] = numbers2[j];
			j++; k++;
		}
	}

	while (i < size) {
		results[k] = numbers[i];
		i++; k++;
	}

	while (j < size2){
		results[k] = numbers2[j];
		j++; k++;
	}
	printf("rezultate: %d \n", k);
	for (i = 0; i < k; i++){
		printf("%d ", results[i]);
	}

	return 0;
}
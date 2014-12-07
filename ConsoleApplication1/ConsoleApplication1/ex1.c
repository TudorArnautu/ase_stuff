#include <stdio.h>
int main()
{
	int numbers[] = { 1, 2, 3, 4, 5 };
	int size = 5;
		int search = 4;
		int search2 = 2;
		
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			if (numbers[i] == search){
				printf("Am gasit numarul %d la pozitia %d\n", search, i);
				
			}

			if (numbers[i] == search2){
				printf("Am gasit numarul %d la pozitia %d\n", search2, i);
				
			}

}
		//printf("Nu am gasit numarul %d\n", search);
		return 0;
}
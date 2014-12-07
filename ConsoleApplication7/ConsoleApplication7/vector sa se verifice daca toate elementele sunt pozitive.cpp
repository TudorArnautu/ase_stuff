#include <stdio.h>

int main()
{
	float v[100];
	int n, i, ok;

	printf("n="); scanf("%d", &n);

	for (i = 0; i < n; i++){
		printf("v[%i]=", i); scanf("%f", &v[i]);
	}
	ok = 1;
	
		for (i = 0; i < n && ok == 1; i++){
			if (v[i] < 0)
			ok = 0;
		}
		
	if (ok == 1)
			printf("Toate elementele vectorului sunt pozitive");
		
		else{
				printf("Elementele vectorului nu sunt toate pozitive");
			}
		
	return 0;
}
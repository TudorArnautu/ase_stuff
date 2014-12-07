#include <stdio.h>

int main()
{
	int v[100],n, i, ok;

	printf("n="); scanf("%d", &n);

	for (i = 0; i < n; i++){
		printf("v[%i]=", i); scanf("%d", &v[i]);
	}

	ok = 0;

	for (i = 0; i < n && ok == 0; i++){
		if (v[i] % 3 == 0)
			ok = 1;
	}

	if (ok==1)
		printf("Am gasit elemente divizibile cu 3");

	else 
		printf("Nu am gasitelemente divizibile cu 3");
	
	return 0;
}
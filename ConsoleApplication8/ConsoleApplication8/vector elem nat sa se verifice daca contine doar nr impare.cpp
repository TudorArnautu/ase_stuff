#include <stdio.h>

void main()
{
	int v[100], n, i, ok;

	printf("n="); scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("v[%i]=", i); scanf("%d", &v[i]);
	}

	ok = 1;
	for (i = 0; i < n && ok == 1; i++)
	if (v[i] % 2 == 0)
		ok = 0;
	if (ok == 1)
		printf("Toate numerele sunt impare", n);
	else printf("Nu toate numerele sunt impare", n);
}	
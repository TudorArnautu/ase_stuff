#include <stdio.h> 




	int main()
	{
		int x, *p;

		scanf("%d", &x);
		p = &x;
		printf("Adresa variabilei x este %p", p);
		return 0;
	}

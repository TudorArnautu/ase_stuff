//Se cite�te de la tastatur� un num�r, s� se afi�eze dac� este par sau impar

#include <stdio.h>

void main()
{
	int nr;

	printf("nr="); scanf("%d", &nr);

		if (nr % 2 == 0)
			printf("Numarul este par");
		else
			printf("Numarul este impar");
	
}
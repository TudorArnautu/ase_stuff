//Se cite�te de la tastatur� un num�r, s� se afi�eze dac� este pozitiv, negativ sau nul

#include <stdio.h>

void main()
{
	int nr;

	printf("nr="); scanf("%d", &nr);

	if (nr == 0)
		printf("Numarul este nul");
	else if (nr > 0)
		printf("Numarul este pozitiv");
	else
		printf("Numarul este negativ");
}
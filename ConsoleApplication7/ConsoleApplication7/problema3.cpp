//Se cite�te de la tastatur� un num�r, s� se afi�eze dac� este pozitiv sau negativ

#include <stdio.h>

void main()
{
	float nr;

	printf("nr="); scanf("%d", &nr);

	if (nr > 0)
		printf("Numarul este pozitiv");
	else
		printf("Numarul este negativ");
}
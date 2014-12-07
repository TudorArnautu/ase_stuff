//Se citeºte de la tastaturã un numãr, sã se afiºeze dacã este pozitiv sau negativ

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
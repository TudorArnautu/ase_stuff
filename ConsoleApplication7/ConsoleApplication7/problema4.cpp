//Se citeºte de la tastaturã un numãr, sã se afiºeze dacã este pozitiv, negativ sau nul

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
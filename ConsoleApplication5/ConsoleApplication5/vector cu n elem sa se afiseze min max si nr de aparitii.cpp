#include <stdio.h>

void main()
{
	float v[100], max, min;
	int nr_min, nr_max, nr, i;

	printf("nr="); scanf("%d", &nr);

	for (i = 0; i < nr; i++)
	{
		printf("v[%i]", i); scanf("%f", &v[i]);
	}
	max = min = v[0];
	nr_max = nr_min = 1;
	for (i = 1; i < nr;i++)
	if (v[i]>max)
	{
		max = v[i];
		nr_max = 1;
	}
	else if (v[i] == max)
		nr_max = nr_max + 1;
	else if (v[i] < min)
	{
		min = v[i];
		nr_min = 1;
	}
	else if (v[i] == min)
		nr_min = nr_min + 1;

	printf("Maximul este %5.1f si apare de %i ori, iar minimul este %5.1f si apare de %i ori.", max, nr_max, min, nr_min);
}
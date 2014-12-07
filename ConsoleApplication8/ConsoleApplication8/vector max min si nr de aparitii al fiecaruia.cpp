#include <stdio.h>

void main()
{
	float v[100], min, max;
	int nr_min, nr_max, nr, i;

	printf("nr="); scanf("%d", &nr);

	for (i = 0; i < nr; i++)
	{
		printf("v[%i]=", i); scanf("%f", &v[i]);
	}
	max = min = v[0];
	nr_min = nr_max = 0;
	for (i = 0; i < nr; i++){
		if (v[i]>max){
			max = v[i];
			nr_max = 1;
		}
		else if (v[i] == max)
			nr_max++;
		
		else if (v[i] < min)
		{
			min = v[i];
			nr_min = 1;
		}

		else if (v[i] == min)
			nr_min++;

		

	}
	printf("Maximul este %f si apare de %i ori iar minimul este %f si apare de %i ori\n", max, nr_max, min, nr_min);
}

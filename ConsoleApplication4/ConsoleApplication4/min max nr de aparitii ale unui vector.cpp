# include<stdio.h>

void main()
{
	float v[100], min, max;
	int nr_max, nr_min, i, n;

	printf("n="); scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("v[%i]=", i); scanf("%f", &v[i]);
	}
	max = min = v[0];
	nr_max = nr_min = 1;
	for (i = 1; i < n;i++)
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
	printf("Maximul este %5.1f, iar nr sau de aparitii este %i.\n Minimul este %5.1f iar numarul sau de aparitii este %i", max, nr_max, min, nr_min);


}
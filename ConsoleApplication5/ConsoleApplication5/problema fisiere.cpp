#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

float *preluare_vector(char *nume, int n)
{
	float *x, v;
	FILE *f;

	v = NULL;
	f = fopen(nume, "r");

	if (f)
	{
		*n = 0;
		fscanf_s(f, "%f", &x);
		while (!feof(f))
		{
			*n++;
			fscanf_s(f, "%f", &x);
		}
		if (*n > 0)
		{
			v = (float*)malloc(*n*sizeof(float));
			rewind(f);
			*n=0;
			fscanf(f, "%f", &x);
			while (!feof(f));
			{
				v[*n++] = x;
				fscanf_s(f, "%f", &x);
			}
		}
		fclose(f);
	}
	return v;
}

void main()

{
	int i, m;
	float a;
	FILE *f;
	a = preluare_vector("Fis1.txt", &n);
	if (!a) printf("Nu exista elemente in fisier");
	else
	{
		printf("Vectorul are %i elemente, iar acestea sunt: \n", n);
		for (i = 0; i <= n; i++)
			printf("%5.2f", a[i]);
		free(a);

	}
}
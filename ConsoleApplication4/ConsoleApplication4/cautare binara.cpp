#include<stdio.h>

int binary(float v[], int n, int s, int d, int x)
{
	int m;
	if (s > d) return -1;
	m = (s + d) / 2;
	if (x < v[m])return binary(v, n,s, m - 1, x);
	else if (x>v[m])return binary(v, n, m + 1, d,x);
	else return m;

}

void main()
{
	float v[100], x;
	int i, j, n, poz;

	printf("Dimensiunea vectorului este ="); scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("v[%i]=",i); scanf("%f", &v[i]);
	}
	printf("Doriti sa cutati elementul x="); scanf("%f", &x);
	poz = binary(v, n, 0, n, x);
	if (poz == -1) printf("Elementul nu a fost gasit");
	else printf("Elementula fost gasit pe pozitia %i", poz);
}
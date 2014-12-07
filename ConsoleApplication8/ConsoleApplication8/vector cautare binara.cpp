#include<stdio.h>



int cautbin(int v[100], int p, int u, int k)
{
	int m;
	if (p > u) return -1;
	else
	{
		m = (p + u) / 2;
		if (k < v[m]) return cautbin(v, p, m - 1, k);
		else if (k>v[m]) return cautbin(v, m + 1, u, k);
		else return m;
	}
}
void main()
{
	


	printf("k=", k); scanf("%d", &k);
	
	cautbin();

	_getch();

	 return 0;



}
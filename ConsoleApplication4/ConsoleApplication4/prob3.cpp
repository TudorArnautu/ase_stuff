# include <stdio.h>
int n, v[100];

void interclasare(int p,int m, int u)
{
	int i,j,t, c[100],k=0;
	i = p;
	j = m + 1;
	while (i<=m&&j<=u)
		if (v[i] < v[j])
			c[k++] = v[i++];
		else c[k++] = v[j++];
	while (i<=m)
		c[k++] = v[i++];
	while (j <=u)
		c[k++] = v[j++];
	t=p;
	for (i= 0; i <= u-p+1; i++)
		v[t++] = c[i];
}

void DEI(int i, int j)
{
	int m;
	if (i < j)
	{
		m = (i + j) / 2;
		DEI(i, m);
		DEI(m + 1, j);
		interclasare(i, m, j);
	}
}


void main()
{
	int v[100], n,i;
	printf("dimensuine vectorului este = "); scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("v[%i]=",i); scanf("%d", &v[i]);
	}
	DEI(1,n);
	for (i = 1; i < =n; i++)
		printf("%i ", v[i]);
}
#include <cstdio>
const int maxn = 10010;
int rank[maxn], pnt[maxn];
void makeset(int x)
{
	rank[pnt[x] = x] = 0;
}
int find(int x)
{
	int px = x, i;
	while (px != pnt[px])
		px = pnt[px];
	while (x != px)
	{
		i = pnt[x];
		pnt[x] = px;
		x = i;
	}
	return px;
}
void merge(int x, int y)
{
	if (rank[x = find(x)] > rank[y = find(y)])
		pnt[y] = x;
	else
	{
		pnt[x] = y;
		rank[y] += (rank[x] == rank[y]);
	}
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int z, x, y;
	for (int i = 0; i <= n; i++)
	{
		pnt[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &z, &x, &y);
		if (z == 1)
			merge(x, y);
		else
		{
			if (find(x) == find(y))
				printf("Y\n");
			else
				printf("N\n");
		}
	}
	return 0;
}
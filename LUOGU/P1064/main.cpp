#include <cstdio>
#include <cstring>
int dp[32010];
int dpa[61][32010];
int att[61][2];
struct item {
	int cost;
	int val;
	int q;
} a[61];
int V;
int max(int a, int b) { return a > b ? a : b; }
int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	V = n;
	memset(att, -1, sizeof(att));
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &a[i].cost, &a[i].val, &a[i].q);
		if (a[i].q)
		{
			int j = 0;
			while (att[a[i].q][j] != -1)
				j++;
			att[a[i].q][j] = i;
		}
	}
	int value, cost;
	for (i = 1; i <= m; i++)//对每个主件i的附件集做一次01背包
	{
		if (a[i].q == 0)
		{
			int j = 0;
			while (att[i][j] != -1)
			{
				value = a[att[i][j]].val;
				cost = a[att[i][j]].cost;
				for (int v = V - a[i].cost; v >= cost; v--)
				{
					dpa[i][v] = max(dpa[i][v], dpa[i][v - cost] + value * cost);
				}
				j++;
			}
		}
	}
	for (i = 1; i <= m; i++)//分组背包
	{
		for (int v = V; v >= 0; v--)
		{
			for (int u = 0; u <= V - a[i].cost; u++)
			{
				if (v-u-a[i].cost>=0)
					dp[v]=max(dp[v],dp[v-u-a[i].cost]+(dpa[i][u]+a[i].val)*(u+a[i].cost));
			}
		}
	}
	printf("%d", dp[V]);
	return 0;
}
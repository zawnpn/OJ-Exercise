#include <cstdio>
const int maxn = 30;
int dp[30010];
struct item {
	int cost;
	int val;
} a[maxn];
int V;
int max(int a, int b) { return a > b ? a : b; }
void ZeroOnePack(int cost, int value) {
	for (int v = V; v >= cost; v--) {
		dp[v] = max(dp[v], dp[v - cost] + value*cost);
	}
	return;
}
int main()
{
	int m, i;
	scanf("%d%d", &V, &m);
	for (i = 1; i <= m; i++)
		scanf("%d%d", &a[i].cost, &a[i].val);
	for (int v = 0; v <= V; v++)
		dp[v] = 0;
	for (i = 0; i <= m; i++)
	{
		ZeroOnePack(a[i].cost, a[i].val);
	}
	printf("%d", dp[V]);
	return 0;
}
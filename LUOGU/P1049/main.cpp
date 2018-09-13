#include <cstdio>
const int maxn = 20010;
int dp[maxn];
int box[50];
int V;
int max(int a, int b) { return a > b ? a : b; }
void ZeroOnePack(int cost, int value) {
	for (int v = V; v >= cost; v--) {
		dp[v] = max(dp[v], dp[v - cost] + value);
	}
}
int main()
{
	int n;
	scanf("%d%d", &V, &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &box[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		ZeroOnePack(box[i], box[i]);
	}
	printf("%d", V - dp[V]);
	return 0;
}
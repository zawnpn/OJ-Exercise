#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int dp[maxn];
int co[10010], val[10010];
int V;
void CompletePack(int cost, int value) {
	for (int v = cost; v <= V; v++) {
		dp[v] = max(dp[v], dp[v - cost] + value);
	}
}
int main()
{
	int T, M;
	scanf("%d%d", &T, &M);
	V = T;
	for (int i = 1; i <= M; i++)
	{
		scanf("%d%d", &co[i], &val[i]);
	}
	for (int i = 1; i <= M; i++)
	{
		CompletePack(co[i], val[i]);
	}
	printf("%d\n", dp[V]);
	return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int dp[maxn];
int co[110],val[110];
int V;
void ZeroOnePack(int cost, int value) {
	for (int v = V; v >= cost; v--) {
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
		ZeroOnePack(co[i], val[i]);
	}
	printf("%d\n", dp[V]);
	return 0;
}
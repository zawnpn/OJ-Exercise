#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f, maxn = 210;
int n, dis[maxn][maxn];
void floyd() {          //dis[i][i]=0;  inf
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}
int main()
{
	int a, b, k, to, first;
	scanf("%d%d%d", &n, &a, &b);
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &k);
		if (k)
		{
			scanf("%d", &first);
			dis[i][first] = 0;
			k--;
			while (k--)
			{
				scanf("%d", &to);
				dis[i][to] = 1;
			}
		}
		
	}
	floyd();
	if (dis[a][b] > 100000)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", dis[a][b]);
	}
	return 0;
}
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 110, maxm = 5010;
int n, m, fa[maxn];
int findroot(int u) {
	if (u != fa[u]) {
		fa[u] = findroot(fa[u]);
	}
	return fa[u];
}
void Union(int u, int v) {
	u = findroot(u); v = findroot(v);
	fa[u] = v;
}
struct edge {
	int u, v, w;
	bool operator<(const edge& b) const { return w < b.w; }
	edge():u(),v(),w(){}
	edge(int u, int v, int w):
		u(u),v(v),w(w){}
} edges[maxm];
int kruskal() {
	for (int i = 0; i <= n; i++)
		fa[i] = i;
	sort(edges, edges + m);
	int res = 0;
	for (int i = 0; i < m; ++i) {
		edge eg = edges[i];
		int u = eg.u, v = eg.v;
		if (findroot(u) == findroot(v)) continue;
		res += eg.w;
		Union(u, v);
	}
	return res;
}
int main()
{
	scanf("%d", &n);
	int w;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &w);
			if (j > i)
			{
				edges[m++] = edge(i, j, w);
			}
		}
	}
	printf("%d", kruskal());
	return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010, maxm = 100010;
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
	edge() :u(), v(), w() {}
	edge(int u, int v, int w) :
		u(u), v(v), w(w) {}
} edges[maxm];
int kruskal() {
	for (int i = 1; i <= n; i++) fa[i] = i;
	sort(edges, edges + m);
	int res = 0;
	for (int i = 0; i < m; ++i) {
		edge eg = edges[i];
		int u = eg.u, v = eg.v;
		if (findroot(u) != findroot(v)) {
			res = eg.w;
			Union(u, v);
		}
	}
	return res;
}
int main()
{
	scanf("%d%d", &n, &m);
	int x, y, t;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &x, &y, &t);
		edges[i] = edge(x, y, t);
	}
	int res = kruskal();
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (fa[i] == i) cnt++;
	}
	if (cnt == 1)
		printf("%d", res);
	else
		printf("-1");
	return 0;
}
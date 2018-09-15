#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 310, maxm = 50010;
int n, m, k, fa[maxn];
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
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	sort(edges, edges + m);
	int res = 0;
	for (int i = 0; i < m; ++i) {
		edge eg = edges[i];
		int u = eg.u, v = eg.v;
		if (findroot(u) != findroot(v)) {
			res = eg.w;
			Union(u, v);
			k++;
		}
		if (k == n - 1)break;
	}
	return res;
}
int main()
{
	scanf("%d%d", &n,&m);
	int u,v,c;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &c);
		edges[i] = edge(u, v, c);
	}
	printf("%d %d", n-1, kruskal());
	return 0;
}
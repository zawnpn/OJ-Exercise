#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct edge {
	int to, w;
	bool operator<(const edge&b)const { return w > b.w; }
	edge() { to = w = 0; }
	edge(int to, int w) { this->to = to; this->w = w; }
};
const int maxn = 100010, inf = 0x3f3f3f3f;
vector<edge> edges[maxn];
int n, dis[maxn];
priority_queue<edge> que;
void dijkstra(int s) {
	while (que.size()) que.pop();
	fill(dis, dis + n + 1, inf);
	que.push(edge(s, 0)); dis[s] = 0;
	while (que.size()) {
		edge eg = que.top(); que.pop();
		int u = eg.to;
		if (eg.w != dis[u]) continue;
		for (int i = 0; i < (int)edges[u].size(); ++i) {
			int v = edges[u][i].to;
			if (dis[v] > dis[u] + edges[u][i].w) {
				dis[v] = dis[u] + edges[u][i].w;
				que.push(edge(v, dis[v]));
			}
		}
	}
}
int main()
{
	int m, i, s, f, g, w;
	scanf("%d%d%d", &n, &m, &s);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &f, &g, &w);
		edges[f].push_back(edge(g, w));
	}
	dijkstra(s);
	for (i = 1; i <= n; i++)
	{
		if (dis[i] < inf)
			printf("%d ", dis[i]);
		else
			printf("%d ", 0x7fffffff);
	}
	return 0;
}
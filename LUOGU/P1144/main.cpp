#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct edge {
	int to, w;
	bool operator<(const edge&b)const { return w > b.w; }
	edge() { to = w = 0; }
	edge(int to, int w) { this->to = to; this->w = w; }
};
const int maxn = 1000010, inf = 0x3f3f3f3f;
const int mod = 100003;
vector<edge> edges[maxn];
int n, dis[maxn], cnt[maxn];
priority_queue<edge> que;
void dijkstra(int s) {
	while (que.size()) que.pop();
	fill(dis+1, dis + n + 2, inf);
	que.push(edge(s, 0)); dis[s] = 0;
	while (que.size()) {
		edge eg = que.top(); que.pop();
		int u = eg.to;
		if (eg.w != dis[u]) continue;
		for (size_t i = 0; i < edges[u].size(); ++i) {
			int v = edges[u][i].to;
			if (dis[v] > dis[u] + edges[u][i].w) {
				dis[v] = dis[u] + edges[u][i].w;
				cnt[v] = cnt[u];
				que.push(edge(v, dis[v]));
			}
			else if (dis[v] == dis[u] + edges[u][i].w)
			{
				cnt[v] += cnt[u];
				cnt[v] %= mod;
			}
		}
	}
}
int main()
{
	int m, x, y;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		edges[x].push_back(edge(y, 1));
		edges[y].push_back(edge(x, 1));
	}
	dis[1] = 0;
	cnt[1] = 1;
	dijkstra(1);
	for (int i = 1; i <= n; i++)
		printf("%d\n", cnt[i]);
}
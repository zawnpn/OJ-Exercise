#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
struct node {
	int x;int y;int step;
	node(int x, int y, int step) :
		x(x), y(y), step(step){}
};
queue<node> que;
const int maxn = 405;
const int dx[8] = {1,1,2,2,-1,-1,-2,-2};
const int dy[8] = {2,-2,1,-1,2,-2,1,-1};
int ans[maxn][maxn];
int n, m;
void bfs()
{
	while (!que.empty())
	{
		node cur = que.front();
		que.pop();
		for (int i = 0; i < 8; i++)
		{
			node nx(cur.x + dx[i], cur.y + dy[i], cur.step + 1);
			if (nx.x >= 1 && nx.y >= 1 && nx.x <= n&&nx.y <= m&&ans[nx.x][nx.y]==-1)
			{
				que.push(nx);
				ans[nx.x][nx.y] = nx.step;
			}
		}
	}
}
int main()
{
	int hx, hy;
	scanf("%d%d%d%d", &n, &m, &hx, &hy);
	memset(ans, -1, sizeof(ans));
	ans[hx][hy] = 0;
	que.push(node(hx, hy, 0));
	bfs();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			printf("%-5d", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
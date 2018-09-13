#include <cstdio>
const int maxn = 10;
int s[maxn][maxn];
int n, m, t, ans=0;
int sx, sy, fx, fy;
int i, j;
const int dx[4] = { -1,0,0,1 };
const int dy[4] = { 0,-1,1,0 };
void dfs(int x, int y)
{
	int x1, y1;
	if (x == fx && y == fy)
	{
		ans++;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		x1 = x + dx[i];
		y1 = y + dy[i];
		if (s[x1][y1]==0 && x1>=1&&y1>=1&&x1<=n&&y1<=m)
		{
			s[x][y] = 1;
			dfs(x1, y1);
			s[x][y] = 0;
		}
	}
}
int main()
{
	scanf("%d%d%d%d%d%d%d", &n, &m, &t, &sx, &sy, &fx, &fy);
	while (t--)
	{
		scanf("%d%d", &i, &j);
		s[i][j] = 1;
	}
	dfs(sx, sy);
	printf("%d", ans);
	return 0;
}
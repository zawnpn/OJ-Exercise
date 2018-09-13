#include<iostream>
#include<queue>
using namespace std;
const int maxn = 35, maxm = 1000;
const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,1,-1 };
int n, a[maxn][maxn], color[maxn][maxn];
struct node {
	int x, y;
	node() :x(), y() {}
	node(const int x, const int y) :
		x(x), y(y) {}
}; node q[maxm];
queue<node> que;
void bfs(int xx, int yy)
{
	if (a[xx][yy] == 1) return;
	que.push(node(xx, yy));
	color[xx][yy] = 0;
	while (que.size())
	{
		node b = que.front(); que.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = b.x + dx[i], y = b.y + dy[i];
			if (x >= 0 && x < n&&y >= 0 && y < n&&a[x][y] != 1 && color[x][y] == 2) {
				que.push(node(x, y));
				color[x][y] = 0;
			}
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) color[i][j] = 1;
			else color[i][j] = 2;
		}
	for (int i = 0; i < n; i++) {
		bfs(i, 0);
		bfs(i, n - 1);
		bfs(0, i);
		bfs(n - 1, i);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << color[i][j] << " ";
		cout << endl;
	}
	return 0;
}
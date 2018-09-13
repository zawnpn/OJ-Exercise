#include <iostream>
using namespace std;
const int maxn = 105;
char a[maxn][maxn], b[maxn][maxn];
const int d[8][2] = {{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
const char word[8] = "yizhong";
int n, i, j;
bool dfs(int r, int c, int idx, int dir)
{
	if (idx == 6)
	{
		b[r][c] = word[idx];
		return 1;
	}
	int r1 = r + d[dir][0];
	int c1 = c + d[dir][1];
	if (r1 >= 0 && c1 >= 0 && r1 < n && c1 < n && a[r1][c1] == word[idx+1])
	{
		if (dfs(r1, c1, idx + 1, dir))
		{
			b[r][c] = a[r][c];
			return 1;
		}
	}
	return 0;
}
int main()
{
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> a[i][j];
			b[i][j] = '*';
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == word[0])
			{
				for (int dir = 0; dir < 8; dir++)
				{
					if (dfs(i, j, 0, dir))
						b[i][j] = word[0];
				}
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout<<b[i][j];
		}
		cout << endl;
	}
	return 0;
}
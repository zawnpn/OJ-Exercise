#include <cstdio>
const int maxn = 100005;
int n, m, ans, fa[maxn * 3];
int find(int u)
{
	if (u != fa[u])
	{
		fa[u] = find(fa[u]);
	}
	return fa[u];
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= 3 * n; i++) { fa[i] = i; }
	for (; m; m--)
	{
		int opt, u, v;
		scanf("%d%d%d", &opt, &u, &v);
		if (u > n || v > n) { ans++; continue; }
		if (opt == 1)//同类关系
		{
			if (find(u + n) == find(v) || find(u) == find(v + n))
				ans++;
			else
			{
				fa[find(u)] = find(v);
				fa[find(u + n)] = find(v + n);
				fa[find(u + n + n)] = find(v + n + n);
			}
		}
		else//捕食关系
		{
			if (find(u) == find(v) || find(u) == find(v + n))
				ans++;
			else
			{
				fa[find(u + n)] = find(v);
				fa[find(u + n + n)] = find(v + n);
				fa[find(u)] = find(v + n + n);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 5010;
struct stick {
	int l;
	int w;
} s[maxn];
bool vis[maxn];
bool cmp(stick x, stick y)
{
	if (x.l == y.l) return x.w > y.w;
	else return x.l > y.l;
}
int main()
{
	int n, i, j, tmp, ans=0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &s[i].l, &s[i].w);;
	}
	sort(s + 1, s + 1 + n, cmp);
	for (i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		vis[i] = 1;
		tmp = s[i].w;
		for (j = i + 1; j <= n; j++)
		{
			if (vis[j]) continue;
			if (s[j].w <= tmp)
			{
				vis[j] = 1;
				tmp = s[j].w;
			}
		}
		ans++;
	}
	printf("%d", ans);
	return 0;
}
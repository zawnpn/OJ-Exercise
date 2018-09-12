#include <cstdio>
const int maxn = 110;
int card[maxn];
int n, i, avg = 0, ans = 0;
int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &card[i]);
		avg += card[i];
	}
	avg /= n;
	for (i = 1; i <= n; i++)
	{
		card[i] -= avg;
	}
	for (i = 1; i <= n; i++)
	{
		if (card[i] == 0) continue;
		card[i + 1] += card[i];
		ans++;
	}
	printf("%d", ans);
	return 0;
}
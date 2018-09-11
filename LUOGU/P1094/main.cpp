#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 300010;
int p[maxn];
int main()
{
	int w, n, cnt = 0;
	int i, j;
	scanf("%d%d", &w, &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
	}
	sort(p + 1, p + 1 + n);
	i = 1;
	j = n;
	while (i <= j)
	{
		if (p[i] + p[j] <= w)
		{
			i++;
			j--;
			cnt++;
		}
		else
		{
			j--;
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
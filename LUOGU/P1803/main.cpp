#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1000010;
struct exam {
	int begin;
	int end;
} e[maxn];
bool cmp(exam x, exam y)
{
	return x.end < y.end;
}
int main()
{
	int n, i, cur = 1, ans = 1;
	bool escape = true;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &e[i].begin, &e[i].end);
	}
	sort(e + 1, e + 1 + n, cmp);
	while (cur < n && escape)
	{
		for (i = cur + 1; i <= n; i++)
		{
			if (e[i].begin >= e[cur].end)
			{
				ans++;
				cur = i;
				break;
			}
			if (i == n)
			{
				escape = false;
				break;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
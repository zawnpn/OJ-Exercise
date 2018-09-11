#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 5010;
struct milk {
	int p;
	int c;
} a[maxn];
bool cmp(milk x, milk y)
{
	return x.p > y.p;
}
int main()
{
	int n, m, i, sum = 0, count = 0, tmp;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &a[i].p, &a[i].c);
	}
	sort(a + 1, a + 1 + m, cmp);
	while (sum < n)
	{
		tmp = (n - sum) > a[m].c ? a[m].c : (n - sum);
		sum += tmp;
		count += a[m].p*tmp;
		m--;
	}
	printf("%d\n", count);
	return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int a[maxn], n;
void f(int k)
{
	int l = k;
	for (int i = l + 1; i <= n; i++)
	{
		if (a[i] < a[l])
		{
			l = i;
		}
	}
	if (k != l)
	{
		swap(a[k], a[l]);
	}
}
int main()
{
	int ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	f(1); f(2);
	for (int i = 1; i <= n - 1; i++)
	{
		a[i + 1] += a[i];
		ans += a[i + 1];
		f(i + 1);
		f(i + 2);
	}
	printf("%d\n", ans);
	return 0;
}
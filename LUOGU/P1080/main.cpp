#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int n, len = 1;
int l[maxn], r[maxn], s[maxn], hp[1000010];
void hp_mul(int x)
{
	for (int i = 1; i <= len; i++)
		hp[i] *= l[x];
	for (int i = 1; i <= len; i++)
	{
		hp[i + 1] += (hp[i] / 10);
		hp[i] %= 10;
	}
	len++;
	while (hp[len] > 9)
	{
		hp[len + 1] += (hp[len] / 10);
		hp[len] %= 10;
		len++;
	}
	if (hp[len] == 0)
		len--;
}
void hp_div()
{
	for (int i = len; i >= 1; i--)
	{
		hp[i - 1] += ((hp[i] % r[n]) * 10);
		hp[i] /= r[n];
	}
	while (hp[len] == 0)
		len--;
	if (len == 0)
		printf("1\n");
}
void qsort(int a, int b)
{
	int i = a, j = b, mid = s[(a + b) / 2];
	while (i <= j)
	{
		while (s[i] < mid)
			i++;
		while (s[j] > mid)
			j--;
		if (i <= j)
		{
			swap(s[i], s[j]);
			swap(l[i], l[j]);
			swap(r[i], r[j]);
			i++;
			j--;
		}
	}
	if (a < j)
		qsort(a, j);
	if (b > i)
		qsort(i, b);
}
int main()
{
	scanf("%d", &n);
	scanf("%d%d", &l[0], &r[0]);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		s[i] = l[i] * r[i];
	}
	qsort(1, n);
	hp[1] = l[0];
	for (int i = 1; i < n; i++)
		hp_mul(i);
	hp_div();
	for (int i = len; i >= 1; i--)
		printf("%d", hp[i]);
	return 0;
}
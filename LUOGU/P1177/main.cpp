#include <cstdio>
#include <algorithm>
using namespace std;
int num[100000];
void qsort(int a, int b)
{
	int i = a, j = b, mid = num[(a + b) / 2];
	while (i <= j)
	{
		while (num[i] < mid)
			i++;
		while (num[j] > mid)
			j--;
		if (i <= j)
		{
			swap(num[i], num[j]);
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
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &num[i]);
	qsort(0, n - 1);
	for (int i = 0; i < n; ++i)
		printf("%d ", num[i]);
	return 0;
}
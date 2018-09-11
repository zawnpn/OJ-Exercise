#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1010;
struct people {
	double t;
	int o;
} q[maxn];
bool cmp(people x, people y)
{
	return x.t < y.t;
}
int main()
{
	int n, i;
	double total = 0.0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%lf", &q[i].t);
		q[i].o = i;
	}
	sort(q + 1, q + 1 + n, cmp);
	for (i = 1; i <= n; i++)
	{
		total += q[i].t * (n - i);
		printf("%d ", q[i].o);
	}
	printf("\n%.2lf", total / (n + 0.0));
	return 0;
}
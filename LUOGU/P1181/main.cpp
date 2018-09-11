#include <cstdio>
int n, m, ans = 1;
int main() 
{
	scanf("%d %d", &n, &m);
	int k = 0;
	while (n--) 
	{
		int a;
		scanf("%d", &a);
		if (k + a <= m) 
		{
			k += a;
		}
		else 
		{
			ans++;
			k = a;
		}
	}
	printf("%d\n", ans);
	return 0;
}
#include <cstdio>
int dp[10010];
int a[110];
int V;
void ZeroOnePack(int cost) 
{
	for (int v = V; v >= cost; v--)
		dp[v] += dp[v - cost];//�Բ��Զ���һ�ַ���
	return;
}
int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	V = m;
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	dp[0] = 1;//�պ�����Ǯ��+1
	for (i = 1; i <= n; i++)
		ZeroOnePack(a[i]);
	printf("%d", dp[V]);
	return 0;
}
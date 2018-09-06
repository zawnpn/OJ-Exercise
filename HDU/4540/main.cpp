#include<cstdio>
#include<cstring>
#include<cmath>
int a[21][11];
int dp[21][11];
int n, k, i, j, m, tmp, best;
int main()
{
    while(scanf("%d%d",&n,&k)==2)
    {
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= k; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        for (i = n - 1; i >= 1; i--)
        {
            for (j = 1; j <= k; j++)
            {
                best = abs(a[i][j] - a[i + 1][1]) + dp[i + 1][1];
                for (m = 2; m <= k; m++)
                {
                    tmp = abs(a[i][j] - a[i + 1][m]) + dp[i + 1][m];
                    if (tmp < best)
                        best = tmp;
                }
                dp[i][j] = best;
            }
        }
        best = dp[1][1];
        for (j = 2; j <= k; j++)
        {
            tmp = dp[1][j];
            if (tmp < best)
                best = tmp;
        }
        printf("%d\n", best);
    }
    return 0;
}
#include <cstdio>
#include <cstring>
const int maxn = 1010;
int num[maxn],dp[maxn];
int main()
{
    int i, j, n, ans;
    while(scanf("%d",&n)==1 && n)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
        }
        for (i = 0; i < n; i++)
        {
            dp[i] = num[i];
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < i; j++)
            {
                if(num[i]>num[j] && dp[j]+num[i]>dp[i])
                {
                    dp[i] = dp[j] + num[i];
                }
            }
        }
        ans = dp[0];
        for (i = 1; i < n; i++)
        {
            if (dp[i] > ans)
            {
                ans = dp[i];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
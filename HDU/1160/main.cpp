#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1010;
struct mice{
    int weight;
    int speed;
    int no;
} m[maxn];
bool cmp(mice a, mice b)
{
    if (a.weight == b.weight)
        return a.speed < b.speed;
    else
        return a.weight < b.weight;
}
int dp[maxn],pre[maxn],ans[maxn];
int main()
{
    int cnt = 1, i, j;
    while(scanf("%d%d" ,&m[cnt].weight, &m[cnt].speed) == 2)
    {
        m[cnt].no = cnt;
        cnt++;
    }
    sort(m + 1, m + cnt, cmp);
    for (i = 1; i < cnt; i++)//init
    {
        dp[i] = 1;
        pre[i] = 0;
    }
    for (i = 1; i < cnt; i++)
    {
        for (j = 1; j < i; j++)
        {
            if(m[i].weight>m[j].weight&&m[i].speed<m[j].speed&&dp[i]<dp[j]+1)
            {
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
        }
    }
    int end = 1, len = dp[1];
    for (i = 2; i < cnt; i++)
    {
        if (len < dp[i])
        {
            len = dp[i];
            end = i;
        }
    }
    printf("%d\n", len);
    for (i = 1; i < cnt; i++)
    {
        ans[i] = end;
        end = pre[end];
    }
    for (i = len; i >= 1; i--)
    {
        printf("%d\n", m[ans[i]].no);
    }
    return 0;
}
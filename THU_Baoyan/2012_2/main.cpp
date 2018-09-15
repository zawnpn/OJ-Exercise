#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int x[maxn];
int main()
{
    int n,avg=0,ans=0;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &x[i]);
        avg += x[i];
    }
    avg /= n;
    for (int i = 1; i < n;i++)
    {
        int tmp = x[i] - avg;
        if (tmp!=0)
        {
            x[i+1] += tmp;
            ans+=abs(tmp);
        }
    }
    printf("%d", ans);
    return 0;
}
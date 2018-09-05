#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 101;
int a[maxn][maxn];
int d[maxn][maxn];
int c, n, i, j;
int main()
{
    scanf("%d", &c);
    while(c--)
    {
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= i; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        for (j = 1; j <= n; j++)
            d[n][j] = a[n][j];
        for (i = n - 1; i >= 1; i--)
        {
            for (j = 1; j <= i; j++)
            {
                d[i][j] = a[i][j] + max(d[i + 1][j], d[i + 1][j + 1]);
            }
        }
        printf("%d\n", d[1][1]);
    }
    return 0;
}
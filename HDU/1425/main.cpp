#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000000];
bool cmp(int x, int y) { return x > y; }
int main()
{
    int n, m, i;
    while(scanf("%d%d",&n,&m)==2)
    {
        for (i = 0; i < n;i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n, cmp);
        for (i = 0; i < m - 1; i++)
        {
            printf("%d ", a[i]);
        }
        printf("%d\n", a[i]);
    }
    return 0;
}
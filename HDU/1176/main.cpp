#include <cstdio>
#include <cstring>
const int maxn = 100010;
int s[maxn][13];
int max(int a, int b, int c)
{
    if (a < b) { a = b; }
    if (a < c) { a = c; }
    return a;
}
int main()
{
    int i, j, n, x, t, tmp;
    while(scanf("%d", &n) == 1 && n)
    {
        memset(s, 0, sizeof(s));
        tmp = 0;
        while(n--)
        {
            scanf("%d%d", &x, &t);
            if(t > tmp)
                tmp = t;
            s[t][x + 1]++;
        }
        for (i = tmp - 1; i > 0; i--)
        {
            for (j = 1; j <= 11; j++)
            {
                s[i][j] += max(s[i + 1][j - 1], s[i + 1][j], s[i + 1][j + 1]);
            }
        }
        printf("%d\n", max(s[1][5],s[1][6],s[1][7]));
    }
    return 0;
}
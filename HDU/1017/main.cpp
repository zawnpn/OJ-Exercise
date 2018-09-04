#include<cstdio>
int main()
{
    int N;
    scanf("%d", &N);
    while(N--)
    {
        int n, m, n_case=1;
        while(scanf("%d%d", &n, &m) && (m != 0 || n != 0))
        {
            int a, b, cnt=0;
            for (b = 2; b < n; b++)
            {
                for (a = 1; a < b; a++)
                {
                    if ((a * a + b * b + m) % (a*b) == 0)
                        cnt++;
                }
            }
            printf("Case %d: %d\n", n_case++, cnt);
        }
        if(N)
            putchar('\n');
    }
    return 0;
}
#include<cstdio>
int main()
{
    int n;
    while(scanf("%d", &n) != EOF && n != 0)
    {
        int cur = 0, next, t = n * 5;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &next);
            if (next > cur)
                t += 6 * (next - cur);
            else
                t += 4 * (cur - next);
            cur = next;
        }
        printf("%d\n", t);
    }
    return 0;
}
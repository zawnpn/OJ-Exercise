#include<cstdio>
#include<cstring>
const int maxn = 500001;
const int tmp = 250000;
int fs[maxn] = {0, 0};
int main()
{
    int i, j;
    for (i = 2; i < maxn; i++)
        fs[i] = 1;
    for (i = 2; i <= tmp; i++)
    {
        for (j = 2 * i; j < maxn; j += i)
        {
            fs[j] += i;
        }
    }
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%d\n", fs[n]);
    }
    return 0;
}
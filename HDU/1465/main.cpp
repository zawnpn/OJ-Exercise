#include<cstdio>
long long int a[21] = {0, 0, 1};
int n;
int main()
{
    for (int i = 3; i <= 20; i++)
        a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
    while(scanf("%d", &n) != EOF)
    {
        printf("%lld\n", a[n]);
    }
    return 0;
}
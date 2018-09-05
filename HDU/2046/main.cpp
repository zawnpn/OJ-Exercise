#include<cstdio>
typedef long long ll;
int main()
{
    ll s[51] = {0, 1, 2};
    for (int i = 3; i <= 50; i++)
        s[i] = s[i - 1] + s[i - 2];
    int n;
    while(scanf("%d", &n) != EOF)
    {
        printf("%lld\n", s[n]);
    }
    return 0;
}
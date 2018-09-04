#include<cstdio>
typedef long long ll;
int pow_mod(ll a, ll p, ll n)
{
    if (a == 0)
        return 0;
    if (p==0)
        return 1;
    ll tmp = pow_mod(a, p / 2, n);
    tmp = tmp * tmp % n;
    if(p%2)
        tmp = tmp * a % n;
    return (int)tmp;
}
int main()
{
    int n, N;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &N);
        printf("%d\n", pow_mod(N, N, 10));
    }
    return 0;
}
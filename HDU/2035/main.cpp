#include<cstdio>
int pow_mod(int a, int p, int n)
{
    if (a == 0) return 0;
    if (p == 0) return 1;
    int tmp = pow_mod(a, p / 2, n);
    tmp = tmp * tmp % n;
    if(p%2) tmp = tmp * a % n;
    return (int)tmp;
}
int main()
{
    int a, b;
    while(~scanf("%d%d", &a, &b) && (a || b))
        printf("%d\n", pow_mod(a, b, 1000));
    return 0;
}
#include<cstdio>
int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
int main()
{
    int x, y;
    while(scanf("%d%d", &x, &y) != EOF)
    {
        printf("%d\n", lcm(x, y));
    }
    return 0;
}
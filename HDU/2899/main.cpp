#include<cstdio>
#include<cmath>
const double eps = 1e-6;
double y;
double F(double x)
{
    return 6 * pow(x, 7) + 8 * pow(x, 6) + 7 * pow(x, 3) + 5 * pow(x, 2) - y * x;
}
double f(double x)
{
    return 42 * pow(x, 6) + 48 * pow(x, 5) + 21 * pow(x, 2) + 10 * x - y;
}
int main()
{
    int t;
    double l, m, r, ans;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf", &y);
        if(f(100)<=0)
        {
            printf("%.4lf\n", F(100));
        }
        else
        {
            l = 0;
            r = 100;
            while(r-l>eps)
            {
                m = (l + r) / 2;
                ans = f(m);
                if(ans>0)
                {
                    r = m;
                }
                else
                {
                    l = m;
                }
            }
            printf("%.4lf\n", F((l + r) / 2));
        }
    }
    return 0;
}
#include<cstdio>
#include<cmath>
double f(double x)
{
    return 8 * pow(x, 4) + 7 * pow(x, 3) + 2 * pow(x, 2) + 3 * x + 6;
}
const double eps = 1e-6;
int main()
{
    int t;
    double y, l, r, m, ans;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf", &y);
        if(f(0)<y && f(100)>y)
        {
            l = 0;
            r = 100;
            while(r-l>eps)
            {
                m = (l + r) / 2;
                ans = f(m);
                if(ans>y)
                {
                    r = m - 1e-7;
                }
                else
                {
                    l = m + 1e-7;
                }
            }
            printf("%.4lf\n", m);
        }
        else
        {
            printf("No solution!\n");
        }
    }
    return 0;
}
#include <cstdio>
int main()
{
    int n, h;
    scanf("%d%d", &n, &h);
    for (int i = n; i < 2013;i++)
    {
        if ((i%100!=0&&i%4==0)||i%400==0)
            h += 366;
        else
            h += 365;
    }
    printf("%d", h);
    return 0;
}
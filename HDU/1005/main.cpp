#include<cstdio>
int tmp[49];
int main()
{
    int a, b, n;
    while(~scanf("%d%d%d", &a, &b, &n) && (a||b||n))
    {
        int minn = n < 49 ? n : 49;
        tmp[0] = 1;
        tmp[1] = 1;
        for (int i = 2; i <= minn; i++)
        {
            tmp[i] = (a * tmp[i - 1] + b * tmp[i - 2]) % 7;
        }
        printf("%d\n", tmp[n % 49 - 1]);
    }
    return 0;
}
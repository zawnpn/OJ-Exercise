#include<cstdio>
#include<cmath>
int main()
{
    int n, num;
    double tmp;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &num);
        tmp = 0;
        for (int i = 2; i <= num; i++)
        {
            tmp += log10(i);
        }
        printf("%d\n",int(tmp) + 1);
    }
    return 0;
}
#include<cstdio>
int main()
{
    int C, n;
    scanf("%d", &C);
    while(C--)
    {
        scanf("%d", &n);
        printf("%d\n", 2 * n * n - n + 1);
    }
    return 0;
}
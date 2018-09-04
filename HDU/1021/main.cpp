#include<cstdio>
int main()
{
    long n;
    while(scanf("%ld", &n) != EOF)
    {
        if (n % 8 == 2 || n % 8 == 6)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
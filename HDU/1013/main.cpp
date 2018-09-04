#include<cstdio>
#include<cstring>
int calc_root(int n)
{
    int tmp = 0;
    while(n)
    {
        tmp += (n % 10);
        n /= 10;
    }
    return tmp;
}
int main()
{
    char num[1010];
    while(scanf("%s", num) && num[0] != '0')
    {
        int n = 0;
        int size = strlen(num);
        for (int i = 0; i < size; i++)
            n += num[i] - '0';
        while(n>=10)
            n = calc_root(n);
        printf("%d\n", n);
    }
    return 0;
}
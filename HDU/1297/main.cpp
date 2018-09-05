#include<cstdio>
const int mod = 100000000;
const int maxn = 32;
int a[1001][maxn];
int i, j;
//使用10^4进制，32位:2^32>10000^2，足以用乘法
//使用10^8进制，32位:2^32>10^8，足以用加法
void add(int n)
{
    int k = 0;
    for(j = 1; j < maxn; j++)
    {
        k += a[n - 1][j] + a[n - 2][j] + a[n - 4][j];
        a[n][j] = k % mod;
        k /= mod;
    }
    while(k)
    {
        a[n][j++] = k % mod;
        k /= mod;
    }
}
int main()
{
    int n;
    a[1][1] = 1;
    a[2][1] = 2;
    a[3][1] = 4;
    a[4][1] = 7;
    for(i = 5; i < 1001; i++)
        add(i);
    while(scanf("%d", &n) != EOF)
    {
        for(i=maxn-1; i > 0; i--)
            if(a[n][i] != 0) break;
        printf("%d", a[n][i]);
        for(i = i - 1; i > 0; i--)
            printf("%08d", a[n][i]);
        printf("\n");
    }
    return 0;
}
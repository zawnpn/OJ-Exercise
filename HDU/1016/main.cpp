#include <cstdio>
#include <cstring>

const int maxn = 40;
int vis[maxn];
int prime[maxn];
int save[maxn];
int num;
int n;

void dfs(int x)
{
    if(num == n-1 && prime[x+1] == 0)
    {
        printf("1");
        for (int i = 0; i < n-1; i++)
            printf(" %d", save[i]);
        putchar('\n');
        return;
    }

    for (int j = 2; j <= n; j++)
    {
        if(prime[j + x] == 0 && vis[j] == 0)
        {
            save[num++] = j;
            vis[j] = 1;
            dfs(j);
            vis[j] = 0;
            num--;
        }
    }
    return;
}

int main()
{
    int i, j;
    memset(prime, 0, sizeof(prime));
    prime[0] = 1;
    prime[1] = 1;
    for (i = 2; i < maxn; i++)
    {
        if(prime[i] != 0)
            continue;
        for (j = i + i; j < maxn; j+= i)
            prime[j] = 1;
    }

    int count = 0;
    while(scanf("%d", &n) != EOF)
    {
        vis[1] = 1;
        memset(vis, 0, sizeof(vis));
        count++;
        num = 0;
        printf("Case %d:\n", count);

        if(n==1)
            printf("1\n");
        else
            dfs(1);
        putchar('\n');
    }
    return 0;
}
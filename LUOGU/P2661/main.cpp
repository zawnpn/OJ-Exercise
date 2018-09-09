#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 200010;
int t[maxn];
bool vis[maxn] = {0}, novis[maxn] = {0};
int step0[maxn] = {0};
int minn = 0x7fffffff;
void dfs(int node, int step)
{
    if(novis[node])
    {
        return;
    }
    if(vis[node])
    {
        minn = min(minn, step - step0[node]);
    }
    else
    {
        vis[node] = true;
        step0[node] = step;
        dfs(t[node], step + 1);
        novis[node] = true;
    }
}
int main()
{
    int n, i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &t[i]);
    }
    for (i = 1; i <= n; i++)
    {
        dfs(i, 0);
    }
    printf("%d", minn);
    return 0;
}
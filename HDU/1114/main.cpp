#include <cstdio>
int dp[10010];
struct coin{
    int p;
    int w;
} c[510];
int min(int a, int b){
    return a < b ? a : b;
}
int main(){
    int t, e, f, n, i, v, vol;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &e, &f, &n);
        vol = f - e;
        for (i = 1; i <= n; i++){
            scanf("%d%d", &c[i].p, &c[i].w);
        }
        dp[0] = 0;
        for (v = 1; v <= vol; v++){
            dp[v] = 0xfffffff;
        }
        for (i = 1; i <= n; i++){
            for (v = c[i].w; v <= vol; v++){
                dp[v] = min(dp[v], dp[v - c[i].w] + c[i].p);
            }
        }
        if (dp[vol] == 0xfffffff){
            printf("This is impossible.\n");
        }
        else{
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[vol]);
        }
    }
    return 0;
}
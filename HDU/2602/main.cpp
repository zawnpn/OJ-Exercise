#include <cstdio>
const int maxn = 1010;
int dp[maxn];
int val[maxn], vol[maxn];
int max(int i, int j){
    if (i>=j) { return i; }
    else { return j; }
}
int main(){
    int t,n,v,i,j;
    while(scanf("%d",&t)==1){
        while(t--){
            scanf("%d%d", &n, &v);
            for (i = 1; i <= n; i++){
                scanf("%d", &val[i]);
            }
            for (i = 1; i <= n; i++){
                scanf("%d", &vol[i]);
            }
            for (j = 0; j <= v; j++){
                dp[j] = 0;
            }
            for (i = 1; i <= n; i++){
                for (j = v; j >= vol[i]; j--){
                    dp[j] = max(dp[j], dp[j - vol[i]] + val[i]);
                }
            }
            printf("%d\n", dp[v]);
        }
    }
    return 0;
}
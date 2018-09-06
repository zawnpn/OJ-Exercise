#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 2010;
int dp[maxn][maxn];
int w[maxn];
int main(){
    int n, k, i, j;
    while(scanf("%d%d", &n, &k)==2){
        for (i = 1; i <= n; i++){
            scanf("%d", &w[i]);
        }
        sort(w + 1, w + n + 1);
        for (i = 0; i <= n; i++){
            for (j = 1; j <= k; j++){
                dp[i][j] = 0xfffffff;
            }

        }
        for (i = 2; i <= n; i++){
            for (j = 1; 2 * j <= i && j <= k; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + (w[i] - w[i - 1]) * (w[i] - w[i - 1]));
            }
        }
        printf("%d\n", dp[n][k]);
    }
    return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 10000;
int dp[maxn][maxn];
int main() {
    string s1, s2;
    int i, j;
    while (cin >> s1 >> s2) {
        int n1 = s1.size(), n2 = s2.size();
        for (i = 0; i <= n1; i++) {
            dp[i][0] = 0;
        }
        for (j = 0; j <= n2; j++) {
            dp[0][j] = 0;
        }
        for (i = 1; i <= n1; i++) {
            for (j = 1; j <= n2; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[n1][n2] << endl;
    }
    return 0;
}
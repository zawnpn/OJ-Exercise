//田忌以最小代价赢齐王 最小代价输齐王
//齐王以最大代价赢田忌 最大代价输田忌
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int i, int j) { return i > j; }
int t[1010], k[1010];
int main()
{
    int n, t0, t1, k0, k1, score;
    while(scanf("%d", &n)!=EOF && n)
    {
        t0 = k0 = 0;
        t1 = k1 = n - 1;
        score = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", &t[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &k[i]);
        sort(t, t + n, cmp);
        sort(k, k + n, cmp);
        while(t0 <= t1)
        {
            if(t[t1] > k[k1])
            {
                t1--;
                k1--;
                score += 200;
            }
            else if(t[t1] < k[k1])
            {
                t1--;
                k0++;
                score -= 200;
            }
            else
            {
                if(t[t0] > k[k0])
                {
                    t0++;
                    k0++;
                    score += 200;
                }
                else if (t[t1--] < k[k0++])
                    score -= 200;
            }
        }
        printf("%d\n", score);
    }
    return 0;
}
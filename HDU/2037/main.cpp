#include<cstdio>
#include<algorithm>
using namespace std;
struct tv{
    int start;
    int end;
} pro[110];
int cmp(struct tv a, struct tv b)
{
    return a.end < b.end;
    return a.start < b.start;
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF && n)
    {
        int k = 0, sum = 1;
        for (int i = 0; i < n; i++)
            scanf("%d%d", &pro[i].start, &pro[i].end);
        sort(pro, pro + n, cmp);
        for (int i = 1; i < n; i++)
        {
            if(pro[i].start>=pro[k].end)
            {
                sum++;
                k = i;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
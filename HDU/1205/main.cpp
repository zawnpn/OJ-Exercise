#include<cstdio>
typedef long long ll;
ll num;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int N;
        ll sum = 0, max = 0;
        scanf("%d", &N);
        while(N--)
        {
            scanf("%lld", &num);
            sum += num;
            max = num > max ? num : max;
        }
        if(sum - max + 1 >= max)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
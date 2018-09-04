#include<cstdio>
int main()
{
    int T, N , s, t, max, tmp;
    scanf("%d", &T);
    while(T--)
    {
        max = 0;
        int pass[210] = {0};
        scanf("%d", &N);
        while(N--)
        {
            scanf("%d%d", &s, &t);
            s = (s - 1) / 2;
            t = (t - 1) / 2;
            if(s > t)
            {
                tmp = s;
                s = t;
                t = tmp;
            }
            for (int k = s; k <= t; k++)
            {
                pass[k]++;
            }
        }
        for (int i = 0; i < 200; i++)
        {
            if (pass[i] > max)
                max = pass[i];
        }
        printf("%d\n", max*10);
    }
    return 0;
}
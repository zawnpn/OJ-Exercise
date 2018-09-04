#include<cstdio>
int main()
{
    int N, n, tmp, out;
    scanf("%d", &N);
    out = 0;
    while(N--)
    {
        scanf("%d", &n);
        out = 0;
        while(n--)
        {
            scanf("%d", &tmp);
            out += tmp;
        }
        if(N>0)
            printf("%d\n\n", out);
        else
            printf("%d\n", out);
    }
	return 0;
}
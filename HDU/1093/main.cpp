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
        printf("%d\n", out);
    }
	return 0;
}
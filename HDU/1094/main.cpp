#include<cstdio>
int main()
{
    int n, tmp, out;
    while(scanf("%d",&n)!=EOF)
    {
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
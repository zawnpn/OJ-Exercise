#include<cstdio>
int main()
{
	int n, tmp, out;
	while (scanf("%d", &n) && n != 0)
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
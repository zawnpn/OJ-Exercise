//N-»Êºó
#include <cstdio>
int ans[14], check[3][28], sum = 0, n;
void dfs(int line)
{
	if (line > n)
	{
		sum++;
		if (sum > 3) return;
		else
		{
			for (int i = 1; i <= n; i++)
				printf("%d ", ans[i]);
			putchar('\n');
			return;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!check[0][i] && !check[1][line + i] && !check[2][line - i + n])
		{
			ans[line] = i;
			check[0][i] = 1;
			check[1][line + i] = 1;
			check[2][line + n - i] = 1;
			dfs(line + 1);
			check[0][i] = 0;
			check[1][line + i] = 0;
			check[2][line + n - i] = 0;
		}
	}
}
int main()
{
	scanf("%d", &n);
	dfs(1);
	printf("%d", sum);
	return 0;
}
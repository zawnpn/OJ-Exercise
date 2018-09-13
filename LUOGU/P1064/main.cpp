#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 32010;
pair<int, int> primary[100];
vector<pair<int, int> > groups[100];
int dp[maxn];
int main()
{
	int n, m, v, p, q;
	int i, j, k;
	int len, cost, value;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		pair<int, int> tmp(0, 0);//预先添加一个空物品(primary)
		groups[i].push_back(tmp);
	}
	for (i = 1; i <= m; i++)//构造附件集
	{
		scanf("%d%d%d", &v, &p, &q);
		if (q == 0)
		{
			primary[i].first = v;
			primary[i].second = p * v;
		}
		else
		{
			len = groups[q].size();
			for (j = 0; j < len; j++)
			{
				cost = groups[q][j].first + v;
				value = groups[q][j].second + p * v;
				pair<int, int> tmp(cost, value);
				groups[q].push_back(tmp);
			}
		}
	}
	for (i = 1; i <= m; i++)//加入主件
	{
		len = groups[i].size();
		for (j = 0; j < len&&primary[i].first; j++)
		{
			groups[i][j].first += primary[i].first;
			groups[i][j].second += primary[i].second;
		}
	}
	for (i = 1; i <= m; i++)//分组背包
	{
		len = groups[i].size();
		for (k = n; k >= 0 && len; k--)
		{
			for (j = 0; j < len; j++)
			{
				if (k >= groups[i][j].first)
				{
					dp[k] = max(dp[k], dp[k - groups[i][j].first] + groups[i][j].second);
				}
			}
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}
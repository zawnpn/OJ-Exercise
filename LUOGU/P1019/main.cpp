#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int maxn = 25;
string w[maxn];
int vis[maxn];
int n, i, j;
unsigned int ans = 0, maxlen = 0;
int kmp(string t, string p) {
	int n = t.size(), m = p.size();
	int *next = new int[m];
	next[0] = -1;
	for (int i = 1, k = -1; i < m; ++i) {
		while (k >= 0 && p[k + 1] != p[i]) k = next[k];
		if (p[k + 1] == p[i]) ++k;
		next[i] = k;        //k保存的是p[0,1...i]的最长的同时是前缀和后缀的，那个前缀的最后一个字符的下标
	}
	for (int i = 0, k = -1; i < n; ++i) {
		while (k >= 0 && p[k + 1] != t[i]) k = next[k];
		if (p[k + 1] == t[i]) ++k; //k保存的是p中已经匹配的最后一个字符的下标
		if (k == m - 1) return i - m + 1;
	}
	return -1;  //不匹配
}
void dfs(string s)
{
	maxlen = max(maxlen, ans);
	int l = s.size(), mp;
	string tmp;
	for (i = 1; i <= n; i++)
	{
		if (vis[i]>=2||s==w[i]) continue;
		for (j = l-1; j >= 1; j--)
		{
			tmp = s.substr(j);
			mp = kmp(w[i], tmp);
			if (mp == 0)
			{
				ans = l + (w[i].size() - j);
				vis[i]++;
				dfs(s + w[i].substr(j));
				vis[i]--;
				ans = l;
				break;
			}
		}
	}
	return;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	string begin;
	cin >> begin;
	dfs(begin);
	cout << maxlen;
	return 0;
}
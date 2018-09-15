#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct node {
	int x, y, val;
};
struct cmp
{
	bool operator()(const node& a, const node& b)
	{
		return a.val < b.val;
	}
};
priority_queue<node, vector<node>, cmp> gx;//大根堆，优先隔开较大值
int fa[100010];
int find(int nod)
{
	if (fa[nod] != nod) return fa[nod] = find(fa[nod]);
	return nod;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int p1, p2, val;
	for (int i = 1; i <= 2 * n; i++) fa[i] = i;
	for (; m; m--)
	{
		scanf("%d%d%d", &p1, &p2, &val);
		gx.push(node{ p1, p2, val });
	}
	while (!gx.empty())
	{
		//只要一旦出现某两个人一定要在同一监狱时，则无需继续判断
		//因为它们之间肯定是影响力最大的了
		if (find(gx.top().x) == find(gx.top().y))
		{
			printf("%d", gx.top().val);
			return 0;
		}
		//把他们隔开.x~y+n,y~x+n->x~x+2n;说明间隔2n为同类,间隔n对立
		fa[fa[gx.top().x]] = fa[find(gx.top().y + n)];
		fa[fa[gx.top().y]] = fa[find(gx.top().x + n)];
		gx.pop();
	}
	printf("%d", 0);
	return 0;
}
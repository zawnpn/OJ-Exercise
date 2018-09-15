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
priority_queue<node, vector<node>, cmp> gx;//����ѣ����ȸ����ϴ�ֵ
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
		//ֻҪһ������ĳ������һ��Ҫ��ͬһ����ʱ������������ж�
		//��Ϊ����֮��϶���Ӱ����������
		if (find(gx.top().x) == find(gx.top().y))
		{
			printf("%d", gx.top().val);
			return 0;
		}
		//�����Ǹ���.x~y+n,y~x+n->x~x+2n;˵�����2nΪͬ��,���n����
		fa[fa[gx.top().x]] = fa[find(gx.top().y + n)];
		fa[fa[gx.top().y]] = fa[find(gx.top().x + n)];
		gx.pop();
	}
	printf("%d", 0);
	return 0;
}
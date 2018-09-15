#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;
const int maxn = 10;
string key[1005];
string word[1005];
string A, B;
int N, step = 0;
struct node {
	string str;
	int step;
	node() :str(), step() {}
	node(const string str, const int step) :
		str(str), step(step) {}
};
queue<node> que;
void bfs()
{
	while (!que.empty())
	{
		node x = que.front();
		if (x.str == B || x.step > 10) return;
		que.pop();
		for (int i = 0; i < N; i++)
		{
			size_t pos = x.str.find(key[i]);
			if (pos != string::npos)
			{
				string tmp;
				tmp = x.str.substr(0, pos) + word[i] + x.str.substr(pos + (key[i]).size());
				que.push(node(tmp, x.step + 1));
			}
		}
	}
}
int main()
{
	string ai, bi;
	cin >> A >> B;
	while (cin >> key[N] >> word[N])
	{
		N++;
	}
	que.push(node(A, 0));
	bfs();
	int step = que.front().step;
	if (step <= 10)
		cout << step << endl;
	else
		cout << "NO ANSWER!" << endl;
	return 0;

}
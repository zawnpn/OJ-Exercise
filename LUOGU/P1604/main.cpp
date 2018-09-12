#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int DIGITS = 2010;
int M;
struct BigNum
{
	int n[DIGITS], l, Y;//最大DIGITS位
	BigNum() { l = 1, memset(n, 0, sizeof(n)); }
	void init()
	{
		string s;
		cin >> s;
		int now = 0;
		for (int i = s.length() - 1; i >= 0; i--)
		{

			if (s[i] >= 'A' && s[i] <= M - 10 + 'A')
				n[now] += (s[i] - 'A' + 10);
			else
				n[now] += (s[i] - '0');
			if (i != 0) { now++; }
		}
		l = now + 1;
	}
	void print()
	{
		if (n[l - 1] == 0) { printf("0"); exit(0); }//对0特殊处理
		for (int i = l - 1; i >= 0; i--)
		{
			if (n[i] >= 10)
				printf("%c", n[i] - 10 + 'A');
			else
				printf("%d", n[i]);
		}
		printf("\n");
	}
	BigNum operator +(BigNum x)const
	{
		BigNum t = *this;
		if (x.l > t.l)t.l = x.l;
		for (int i = 0; i < t.l; i++)
		{
			t.n[i] += x.n[i];
			if (t.n[i] >= M) { t.n[i + 1] += t.n[i] / M; t.n[i] %= M; }
		}
		while (t.n[t.l])
		{
			t.n[t.l + 1] += t.n[t.l] / M;
			t.n[t.l++] %= M;
		}
		return t;
	}
} a, b, c;

int main()
{
	cin >> M;
	a.init();
	b.init();
	c = a + b;
	c.print();
	return 0;
}
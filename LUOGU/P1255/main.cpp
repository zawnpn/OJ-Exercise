#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int M = 100000000, P = 8, DIGITS = 150;// M=10^P 压位
const int maxn = 5010;
struct BigNum
{
	int n[DIGITS], l, Y;//最大DIGITS位
	BigNum() { l = 1, memset(n, 0, sizeof(n)); }
	void init(string s)
	{
		int now = 0, ct = 0, c1 = 1;
		for (int i = s.length() - 1; i >= 0; i--)
		{
			n[now] += (s[i] - '0')*c1; c1 *= 10; ct++;
			if (ct == P && i != 0) { now++; c1 = 1; ct = 0; }
		}
		l = now + 1;
	}
	void print()
	{
		if (n[l - 1] == 0) { printf("0"); exit(0); }//对0特殊处理
		printf("%d", n[l - 1]);
		for (int i = l - 2; i >= 0; i--) printf("%0*d", P, n[i]);
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
} f[maxn];

int main()
{
	int N;
	BigNum a, b;
	a.init("1");
	b.init("2");
	f[1] = a;
	f[2] = b;
	scanf("%d", &N);
	for (int i = 3; i <= N; i++)
	{
		f[i] = (f[i - 1] + f[i - 2]);
	}
	f[N].print();
	return 0;
}
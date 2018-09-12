#include <iostream>
#include <string>
using namespace std;
const int maxn = 510;
string A, B;
int a[maxn], b[maxn];
int i, tmp;
int main()
{
	cin >> A >> B;
	int sz_a = A.size(), sz_b = B.size(), sz_m;
	if (sz_a > sz_b)
	{
		for (i = 0; i < (sz_a - sz_b); i++)
			B = "0" + B;
		sz_m = sz_a;
	}
	else
	{
		for (i = 0; i < (sz_b - sz_a); i++)
			A = "0" + A;
		sz_m = sz_b;
	}
	for (i = 0; i < sz_m; i++)
	{
		a[i + 1] = A[i] - '0';
		b[i + 1] = B[i] - '0';
	}
	for (i = sz_m; i >= 1; i--)
	{
		tmp = a[i] + b[i];
		a[i - 1] += (tmp / 10);
		a[i] = tmp % 10;
	}
	if (a[0])
		cout << a[0];
	for (i = 1; i <= sz_m; i++)
	{
		cout << a[i];
	}
	return 0;
}
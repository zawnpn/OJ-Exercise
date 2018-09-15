#include<cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100010;
int b[N], idx[N], n;
int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
	while ('0' <= ch && ch <= '9') { x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar(); }
	return x * f;
}
int main() {
	n = read();
	memset(b, 0x3f, sizeof(b));
	for (int i = 1; i <= n; i++)
		idx[read()] = i;
	for (int i = 1; i <= n; i++) {
		int x = idx[read()];
		*lower_bound(b + 1, b + n + 1, x) = x;
	}
	printf("%d", lower_bound(b + 1, b + n + 1, b[0]) - b - 1);
	return 0;
}

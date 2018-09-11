#include <cstdio>
#include <cmath>
const int maxn = 110;
int card[maxn];
int n, i;
int maxc = 0, maxi;
int sum, avg;
void right(int k, int in)
{
	card[k] += in;
	int rs = 0;
	for (i = k + 1; i <= n; i++)
	{
		rs += card[i];
	}
	int out = avg * (n - k) - rs;
	card[k] -= out;
	right(k + 1, out);

}
int main()
{
	

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &card[i]);
		sum += card[i];
		if (card[i] > maxc)
		{
			maxc = card[i];
			maxi = i;
		}
	}
	avg = sum / n;
	for (i = maxi + 1; i <= n; i++)
	{
		tmp += card[i];
	}
	need = avg * (n - maxi);
	card[i] -= need;


}
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int lli;
const int maxn = 100000;
lli f[maxn];
bool mid[3];
lli select(lli a, lli b, lli c)
{
    lli m;
    m = min(min(a, b), c);
    for (int i = 0; i < 3; i++)
        mid[i] = false;
    if(m == a) mid[0] = true;
    if(m == b) mid[1] = true;
    if(m == c) mid[2] = true;
    return m;
}
int main()
{
    lli a, b, c, x, y, z, n;
    while(scanf("%lld%lld%lld%lld",&x,&y,&z,&n)==4)
    {
        a = b = c = 0;
        f[0] = 1;
        for (lli i = 1; i < maxn; i++)
        {
            f[i] = select(f[a] * x, f[b] * y, f[c] * z);
            if (mid[0]) a++;
            if (mid[1]) b++;
            if (mid[2]) c++;
        }
        printf("%lld\n", f[n]);
    }
    return 0;
}
#include<cstdio>
#include<set>
using namespace std;
typedef unsigned long long ull;
set<ull> h;
set<ull>::iterator it;
int main()
{
    ull x, y, z, n;
    while(scanf("%llu%llu%llu%llu",&x,&y,&z,&n)==4)
    {
        h.clear();
        h.insert(x);h.insert(y);h.insert(z);
        it = h.begin();
        while(--n)
        {
            h.insert(*it*x);h.insert(*it*y);h.insert(*it*z);
            it++;
        }
        printf("%llu\n", *it);
    }
    return 0;
}
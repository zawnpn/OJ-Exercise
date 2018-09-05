#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int f[5843] = {0, 1};
bool mid[4];
int select(int a, int b, int c, int d)
{
    int m;
    m = min(min(a, b), min(c, d));
    for (int i = 0; i < 4; i++)
        mid[i] = false;
    if(m == a) mid[0] = true;
    if(m == b) mid[1] = true;
    if(m == c) mid[2] = true;
    if(m == d) mid[3] = true;
    return m;
}
int main()
{
    int a, b, c, d;
    a = b = c = d = 1;
    for (int i = 2; i <= 5842; i++)
    {
        f[i] = select(f[a] * 2, f[b] * 3, f[c] * 5, f[d] * 7);
        if (mid[0]) a++;
        if (mid[1]) b++;
        if (mid[2]) c++;
        if (mid[3]) d++;
    }
    int n;
    char sfx[3];
    while(scanf("%d", &n) == 1 && n)
    {
        if (n % 10 == 1 && n % 100 != 11)
            strcpy(sfx, "st");
        else if (n % 10 == 2 && n % 100 != 12)
            strcpy(sfx, "nd");
        else if (n % 10 == 3 && n % 100 != 13)
            strcpy(sfx, "rd");
        else
            strcpy(sfx, "th");
        printf("The %d%s humble number is %d.\n", n, sfx, f[n]);
    }
    return 0;
}
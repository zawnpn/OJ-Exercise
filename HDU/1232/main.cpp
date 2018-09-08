#include <cstdio>
const int maxn = 1010;
int set[maxn];
int root(int x){
    int r = x;
    while(set[r]!=r){
        r = set[r];
    }
    int i = x, tmp;
    while(i!=r){
        tmp = set[i];
        set[i] = r;
        i = tmp;
    }
    return r;
}
void merge(int a, int b){
    int ra = root(a), rb = root(b);
    if (ra!=rb){
        set[ra] = rb;
    }
    return;
}
int main(){
    int n, m, i, x, y, cnt;
    while(scanf("%d", &n)!=EOF && n){
        scanf("%d", &m);
        for (i = 1; i <= n; i++){
            set[i] = i;
        }
        while(m--){
            scanf("%d%d", &x, &y);
            merge(x, y);
        }
        for (cnt = -1, i = 1; i <= n; i++){
            if (set[i]==i){
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
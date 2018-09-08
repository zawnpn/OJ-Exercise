#include <cstdio>
#include <cstring>
const int maxn = 100010;
int fa[maxn];
int root(int x){
    int r = x;
    while(fa[r]!=r){
        r = fa[r];
    }
    return r;
}
bool merge(int a, int b){
    int ra = root(a), rb = root(b);
    if (ra==rb){
        return true;
    }
    else{
        fa[ra] = rb;
        return false;
    }
}
int main(){
    int x, y, i, cnt;
    bool flag = false, status = false;
    memset(fa, -1, sizeof(fa));
    while(scanf("%d%d",&x,&y)==2 && x+y+2){
        if (flag){
            printf("No\n");
            flag = false;
            memset(fa, -1, sizeof(fa));
            if (x+y==0){
                continue;
            }
            else{
                while(scanf("%d%d",&x,&y)==2 && x+y)
                    ;
                continue;
            }
        }
        if (x+y==0){
            for (cnt = 0, i = 1; i <= maxn; i++){
                if (fa[i] == i){
                    cnt++;
                }
                if (cnt>1){
                    status = true;
                    break;
                }
            }
            if (status){
                printf("No\n");
            }
            else{
                printf("Yes\n");
            }
            status = false;
            memset(fa, -1, sizeof(fa));
            continue;
        }
        if (fa[x]==-1){
            fa[x] = x;
        }
        if (fa[y]==-1){
            fa[y] = y;
        }
        flag = merge(x, y);
    }
    return 0;
}
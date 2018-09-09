#include <cstdio>
#include <cmath>
const int maxn = 10;
char maze[maxn][maxn];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int flag;
int n, m, T, di, dj;
void dfs(int si,int sj, int step)
{
    int i, tmp;
    if (si>n||si<1||sj>m||sj<1)
    {
        return;
    }
    if (si==di&&sj==dj&&step==T)
    {
        flag = 1;
        return;
    }
    //奇偶剪枝
    tmp = (T - step) - abs(di - si) - abs(dj - sj);
    if (tmp<0||tmp%2)
    {
        return;
    }
    //DFS
    for (i = 0; i < 4; i++)
    {
        if(maze[si+dir[i][0]][sj+dir[i][1]] != 'X')
        {
            maze[si + dir[i][0]][sj + dir[i][1]] = 'X';
            dfs(si + dir[i][0], sj + dir[i][1], step + 1);
            if(flag)
            {
                return;
            }
            maze[si + dir[i][0]][sj + dir[i][1]] = '.';
        }
    }
    return;
}
int main()
{
    int i, j, si, sj;
    while(scanf("%d%d%d",&n,&m,&T)==3 && n+m+T)
    {
        //Input maze
        int wall = 0;
        for (i = 1; i <= n; i++)
        {
            getchar();
            for (j = 1; j <= m; j++)
            {
                scanf("%c", &maze[i][j]);
                if(maze[i][j]=='S')
                {
                    si = i;
                    sj = j;
                }
                else if(maze[i][j]=='D')
                {
                    di = i;
                    dj = j;
                }
                else if(maze[i][j]=='X')
                {
                    wall++;
                }
            }
        }
        getchar();
        //Init
        if(n*m-wall<=T)
        {
            printf("NO\n");
            continue;
        }
        //DFS
        flag = 0;
        maze[si][sj] = 'X';
        dfs(si, sj, 0);
        //Output
        if(flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
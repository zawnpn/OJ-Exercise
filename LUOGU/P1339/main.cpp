#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct edge{
    int to,w;
    bool operator<(const edge&b)const {return w>b.w;}
    edge(){to=w=0;}
    edge(int to,int w){this->to=to; this->w=w;}
};
const int maxn=20000,inf=1000000;
vector<edge> edges[maxn];
int dis[maxn];
int T, C, Ts, Te;
priority_queue<edge> que;
void dijkstra(int s){
    while(que.size()) que.pop();
    fill(dis,dis+T+1,inf);
    que.push(edge(s,0)); dis[s]=0;
    while(que.size()){
        edge eg=que.top(); que.pop();
        int u=eg.to;
        if(eg.w!=dis[u]) continue;
        for(int i=0;i<edges[u].size();++i){
            int v=edges[u][i].to;
            if(dis[v]>dis[u]+edges[u][i].w){
                dis[v]=dis[u]+edges[u][i].w;
                que.push(edge(v,dis[v]));
            }
        }
    }
}
int main()
{
    int Rs, Re, Ci;
    scanf("%d%d%d%d", &T, &C, &Ts, &Te);
    for (int i = 1; i <= C; i++)
    {
        scanf("%d%d%d", &Rs, &Re, &Ci);
        edges[Rs].push_back(edge(Re, Ci));
        edges[Re].push_back(edge(Rs, Ci));
    }
    dijkstra(Ts);
    printf("%d\n", dis[Te]);
    return 0;
}
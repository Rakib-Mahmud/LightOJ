#include<bits/stdc++.h>
#define mx 100005
#define inf 1e4
using namespace std;

int res1,res2;
int dist1[5002],dist2[5002],vis[5002];
struct node
{
    int u,cost;
    node(int _u,int _cost)
    {
        u=_u;
        cost=_cost;
    }
    bool operator < (const node &p)const
    {
        return cost>p.cost;
    }
};

int dijk1(int n,vector<int>g[],vector<int>cost[])
{
    memset(dist1,inf,sizeof(dist1));
    priority_queue<node>Q;
    Q.push(node(1,0));
    dist1[1]=0;

    while(!Q.empty())
    {
        node u=Q.top();
        Q.pop();
        if(u.cost!=dist1[u.u])continue;
        for(int i=0; i<g[u.u].size(); i++)
        {
            int v=g[u.u][i];
            if(dist1[u.u]+cost[u.u][i]<dist1[v])
            {
                dist1[v]=dist1[u.u]+cost[u.u][i];
                Q.push(node(v,dist1[v]));
            }
        }
    }
return dist1[n];
}

int dijk2(int n,vector<int>g[],vector<int>cost[])
{
    int res=inf;
    memset(dist2,inf,sizeof(dist2));
    memset(vis,0,sizeof(vis));
    priority_queue<node>Q;
    Q.push(node(1,0));
    dist2[1]=0;

    while(!Q.empty())
    {
        node u=Q.top();
        Q.pop();
        vis[u.u]=0;
        int ln=g[u.u].size(),p=1;
        for(int i=0; i<ln; i++)
        {
            int v=g[u.u][i];
            if(v==1 && dist2[1]==0){ dist2[v]=inf; }
            p=0;
            int alt=dist1[u.u]+cost[u.u][i];
            int amt=dist2[u.u]+cost[u.u][i];
            if(alt>dist1[v] && alt<dist2[v]){
                dist2[v]=alt;
                if(vis[v]==0 || p==0){
                    Q.push(node(v,dist2[v]));
                    vis[v]=1;
                }
            }
            else if(alt==dist1[v]){
                if(alt==amt){
                    dist2[v]=min(dist1[u.u]+(3*cost[u.u][i]),dist2[v]);
                }
                else{
                dist2[v]=min(min((dist1[u.u]+(3*cost[u.u][i])),amt),dist2[v]);
                }
                if(vis[v]==0||p==0){
                Q.push(node(v,dist2[v]));
                vis[v]=1;
                }
            }
        }
    }
    res=dist2[n];

    return res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int no_node,no_edge,a,b,w,s,t;
    cin>>t;
    for(int cas=1;cas<=t;cas++){
    vector<int>graph[5001],cost[mx];
    cin>>no_node>>no_edge;
    for(int i=0;i<no_edge;i++){
        cin>>a>>b>>w;
        graph[a].push_back(b);
        graph[b].push_back(a);
        cost[a].push_back(w);
        cost[b].push_back(w);
    }
    res1=dijk1(no_node,graph,cost);
    res2=dijk2(no_node,graph,cost);
    cout<<"Case "<<cas<<": "<<res2<<endl;
    }
    return 0;
}

/*
5 5
1 2 2
1 3 3
2 4 5
3 4 1
4 5 2
1
*/


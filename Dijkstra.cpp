#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=1e3+5;
const int INF=1e9+7;
vector<pii> adj[N];
vector<bool> visited(N);
vector<int> cost(N,INF);
void dijkstra(int s){
    priority_queue<pii, vector<pii> , greater<pii>> pq;
    cost[s]=0;
    pq.push({cost[s],s});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        visited[u]=true;
        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            if(visited[v]) continue;
            if(cost[v]>cost[u]+w){
                cost[v]=cost[u]+w;
                pq.push({cost[v],v});
            }
        }
    }
}
int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int s,d; cin >> s>>d;
    dijkstra(s);
    cout<<"Shortest distance from node "<<s<<" to node "<<d<<" is : "<<cost[d]<<"\n";
    return 0;
}

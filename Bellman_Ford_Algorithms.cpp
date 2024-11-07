#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N = 1e5+7;
const int INF = 1e9+7;
vector<pii> adj[N];
vector<int> cost(N);

void bellman_ford(int s,int n){
    for(int i=0;i<N;i++){
        cost[i]=INF;
    }

    cost[s]=0;
    for(int i=1;i<n;i++){
        for(int u=1;u<=n;u++){
            for(auto it:adj[u]){
                int v = it.first;
                int w = it.second;
                if(cost[u] != INF && cost[v] > cost[u]+w){
                    cost[v] = cost[u]+w;
                }
            }
        }
    }
}
int main(){
    
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    bellman_ford(1,n);

    for(int i=1;i<=n;i++){
        cout<<"Cost of "<<i<<"is : "<<cost[i]<<endl;
    }
    return 0;
}

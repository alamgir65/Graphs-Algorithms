#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
using namespace std;
const int N = 1e5+7;
const int INF = 1e9+7;
int cost[N];
vector<pair<pii,int>> edges_list;
void bellmanFord(int s,int n){
    for(int i=0;i<N;i++){
        cost[i]=INF;
    }
    cost[s]=0;
    for(int i=1;i<=n;i++){
        for(auto it:edges_list){
            int u=it.first.first;
            int v=it.first.second;
            int w=it.second;

            if(cost[u]!=INF && cost[v]>cost[u]+w){
                cost[v]=cost[u]+w;
            }
        }
    }
}
int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        edges_list.push_back({{u,v},w});
    }
    bellmanFord(1,n);
    for(int i=1;i<=n;i++){
        cout<<"Cost of "<<i<<" is : "<<cost[i]<<endl;
    }
    return 0;
}

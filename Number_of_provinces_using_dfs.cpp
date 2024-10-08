#include<bits/stdc++.h>
#define ll long long
using namespace std;
void dfs(int node, vector<int> adj[],int visited[]){
    visited[node]=1;
    for(auto x:adj[node]){
        if(!visited[x]){
            dfs(x,adj,visited);
        }
    }
}
int main(){
    int n,m; cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int provinces = 0;
    int visited[n+1]={0};
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            provinces++;
            dfs(i,adj,visited);
        }
    }
    cout<<"Number of Provinces : "<<provinces<<endl;
    return 0;
}

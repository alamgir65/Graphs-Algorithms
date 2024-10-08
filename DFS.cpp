#include<bits/stdc++.h>
#define ll long long
using namespace std;
void dfs(int node,vector<int> adj[],int visited[],vector<int> &ans){
    visited[node]=1;
    ans.push_back(node);
    cout<<node<<" ";
    for(auto x:adj[node]){
        if(!visited[x]){
            visited[x]=1;
            dfs(x,adj,visited,ans);
        }
    }
}
int main(){
    int n,m; 
    cin>>n>>m;
    int visited[n+1]={0};
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans;
    dfs(1,adj,visited,ans);
    for(auto x:ans) cout<<x<<" ";
    
    return 0;
}

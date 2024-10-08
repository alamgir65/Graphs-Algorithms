#include<bits/stdc++.h>
using namespace std;
int n,m;
void bfs(int u,vector<int> adj[]){
    int visited[n+1]={0};
    queue<int> q;
    q.push(u);
    visited[u]=1;
    while(!q.empty()){
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        for(auto x:adj[node]){
                if(!visited[x]){
                    visited[x]=1;
                    q.push(x);
                }
        }
    }
}
int main()
{
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1,adj);
    return 0;
}


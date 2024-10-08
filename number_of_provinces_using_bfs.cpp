#include<bits/stdc++.h>
#define ll long long
using namespace std;
void bfs(int u,vector<int> adj[],int visited[]){
    queue<int> q;
    q.push(u);
    visited[u]=1;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(auto x:adj[v]){
            if(!visited[x]){
                visited[x]=1;
                q.push(x);
            }
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
            bfs(i,adj,visited);
        }
    }
    cout<<provinces<<"\n";

    return 0;
}

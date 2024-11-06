#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+3;
vector<int> adj[N];
vector<bool> visited(N);
int level[N];
vector<int> parent(N);
void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s]=1;
    level[s]=1;
    parent[s]=-1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:adj[u]){
            if(!visited[v]){
                visited[v]=1;
                level[v]=level[u]+1;
                parent[v]=u;
                q.push(v);
            }
        }
    }
}
int main(){
    // for(int i=0;i<=N;i++) level[i]=-1;
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    if(level[n]==0) cout<<"IMPOSSIBLE"<<endl;
    else{
        cout<<level[n]<<endl;
        vector<int> path;
        int current=n;
        while(current != -1){
            path.push_back(current);
            current=parent[current];
        }
        reverse(path.begin(),path.end());
        for(auto x:path) cout<<x<<" ";
    }
    // cout<<"HELLO\n";
    return 0;
}

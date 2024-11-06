#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
vector<int> adj[1000000];
int level[1000000];
int visited[1000000];
int parent[1000000];
void bfs(int s){
    queue<int> q;
    level[s]=0;
    parent[s]=-1;
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto x:adj[u]){
            if(!visited[x]){
                q.push(x);
                visited[x]=1;
                level[x]=level[u]+1;
                parent[x]=u;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int source,destination; cin>>source>>destination;
    bfs(source);
    cout<<"The total distance from "<<source<<" to "<<destination<<" is :"<< level[destination]<<endl;

    vector<int> path;
    int current=destination;
    while(current != -1){
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(),path.end());
    cout<<"The path from "<<source<<" to "<<destination<<" is : ";
    for(auto x:path) cout<<x<<" ";
    cout<<endl;
    return 0;
}

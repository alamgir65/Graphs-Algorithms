#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
vector<int> adj[N];
vector<bool> visited(N);
void dfs(int u){
    visited[u]=true;
    for(auto v:adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int provinces=0;
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            provinces++;
            dfs(i);
            v.push_back(i);
        }
    }
    cout<<v.size()-1<<"\n";
    // sort(v.begin(),v.end());  // sorting by first element in pair (province number)
    for(int i=0;i<v.size()-1;i++){
        cout<<v[i]<<" "<<v[i+1]<<"\n";
    }
    return 0;
}

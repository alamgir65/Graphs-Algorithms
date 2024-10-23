#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define cyes cout<<"Yes"<<endl;
#define cno cout<<"No"<<endl;
#define all(x) x.begin(), x.end()
#define nl cout<<endl;
#define endl '\n'
#define love int main()
#define vtr vector
#define pii pair<int,int>
#define out(x) cout << x << '\n';
#define out2(x,y) cout << x << " " << y << '\n';
#define vii vector<int> 
#define vll vector<ll>
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
#define Alamgir ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
using namespace std;
void dfs(int node, vector<int> adj[],vector<int> &visited,stack<int> &st){
    visited[node]=1;
    for(auto u:adj[node]){
        if(!visited[node]){
            dfs(u,adj,visited,st);
        }
    }
    st.push(node);
}
void solve(){
    int n,m; cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        // adj[v].pb(u);
    }
    stack<int> st;
    vector<int> visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,adj,visited,st);
        }
    }
    while(!st.empty()){
        cout<< st.top() << " ";
        st.pop();
    }
}
love{
    Alamgir
    int t; 
    // cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;    
}
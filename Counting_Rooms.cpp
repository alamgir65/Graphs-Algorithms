#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1003;
vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
bool visited[1003][1003];
vector<vector<char>> adj(N,vector<char>(N));
int n,m; 
bool isValid(int i,int j){
    return (i<n && i>=0 && j<m && j>=0);
}
void dfs(int i,int j){
    visited[i][j]=true;
    for(auto d:dir){
        int ni=i+d.first,nj=j+d.second;
        if(isValid(ni,nj) && !visited[ni][nj] && adj[ni][nj]=='.'){
            dfs(ni,nj);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>adj[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]=='.' && !visited[i][j]){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

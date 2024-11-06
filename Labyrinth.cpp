#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=1003;
vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
bool visited[1003][1003];
vector<vector<char>> adj(N,vector<char>(N));
int level[N][N];
int n,m; 
bool isValid(int i,int j){
    return (i<n && i>=0 && j<m && j>=0);
}
pii parent[N][N];

void bfs(int si,int sj){
    queue<pii> q;
    q.push({si,sj});
    visited[si][sj]=true;
    level[si][sj]=0;
    parent[si][sj]={-1,-1};
    while(!q.empty()){
        int i=q.front().first,j=q.front().second;
        q.pop();
        for(auto d:dir){
            int ni=i+d.first,nj=j+d.second;
            if(isValid(ni,nj) &&!visited[ni][nj] && adj[ni][nj]!='#'){
                visited[ni][nj]=true;
                q.push({ni,nj});
                level[ni][nj]=level[i][j]+1;
                parent[ni][nj]={i,j};
            }
        }
    }
}


int main(){
    cin>>n>>m;
    int si,sj,di,dj; // Starting and destination coordinates
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>adj[i][j];
            if(adj[i][j]=='A') si=i,sj=j;
            if(adj[i][j]=='B') di=i,dj=j;
        }
    }

    bfs(si,sj);
    if(!visited[di][dj]){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
        cout<<level[di][dj]<<endl;
        vector<pii> path;
        pii curr={di,dj};
        while(!(curr.first==si && curr.second==sj)){
            path.push_back(curr);
            curr=parent[curr.first][curr.second];
        }
        path.push_back({si,sj});
        reverse(path.begin(), path.end());
        // for(auto it:path){
        //     cout<<it.first+1<<" "<<it.second+1<<endl;
        // }
        string ans;
        for(int i=1;i<path.size();i++){
            if(path[i].first==path[i-1].first){
                if(path[i-1].second == path[i].second+1) ans += "L";
                else ans += "R";
            }else{
                if(path[i-1].first == path[i].first+1) ans += "U";
                else ans += "D";
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}

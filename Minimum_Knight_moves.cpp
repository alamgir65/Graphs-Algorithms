#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool visited[8][8];
int level[8][8];
vector<pair<int,int>> dir = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
bool isValid(int i,int j){
    return (i>=0 && i<8 && j>=0 && j<8);
}
void reset_level_visited(){
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            visited[i][j]=0,level[i][j]=0;
}
void bfs(int si,int sj){
    queue<pair<int,int>> q;
    q.push({si,sj});
    visited[si][sj]=0;
    level[si][sj]=0;

    while(!q.empty()){
        int i=q.front().first,j=q.front().second;
        q.pop();
        for(auto d:dir){
            int ni=i+d.first,nj=d.second+j;
            if(isValid(ni,nj) && !visited[ni][nj]){
                visited[ni][nj]=true;
                level[ni][nj] = level[i][j]+1;
                q.push({ni,nj});
            }
        }
    }
}
int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        reset_level_visited();
        string x,y; cin>>x>>y;
        int si,sj,di,dj;
        si=x[0]-'a',sj=x[1]-'1',di=y[0]-'a',dj=y[1]-'1';
        bfs(si,sj);
        cout<<level[di][dj]<<endl;
    }
    return 0;
}

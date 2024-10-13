//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    int n,m;
    bool isValid(int i,int j){
        return (i<n && i>=0 && j<m && j>=0);
    }
    vector<pair<int,int>> dir={{0,1},{0,-1},{-1,0},{1,0}};
    int bfs(vector<vector<int>> &adj,vector<vector<int>> &visited,int ans,queue<pair<pair<int,int>,int>> &q){
        while(!q.empty()){
            int u=q.front().first.first;
            int v=q.front().first.second;
            int w=q.front().second;
            q.pop();
            ans = max(ans,w);
            for(auto d:dir){
                int i=u + d.first;
                int j=v + d.second;
                if(isValid(i,j) && !visited[i][j] && adj[i][j]==1){
                    visited[i][j]=1;
                    adj[i][j]=2;
                    q.push({{i,j},w+1});
                }
            }
        }
        return ans;
    }
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        vector<vector<int>> adj=grid;
        n=grid.size();
        m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        
        int ans = bfs(adj,visited,0,q);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(adj[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  int n,m;
  bool isValid(int i,int j){
      return (i<n && i>=0 && j<m && j>=0);
  }
  vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
  
  void dfs(int sr,int sc,int newColor,int initialColor,vector<vector<int>> &adj,vector<vector<int>> &visited){
      visited[sr][sc]=1;
      adj[sr][sc]=newColor;
      for(auto d:dir){
          int r=sr + d.first;
          int c=sc + d.second;
          if(isValid(r,c) && !visited[r][c] && adj[r][c]==initialColor){
              dfs(r,c,newColor,initialColor,adj,visited);
          }
      }
  }
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        n=image.size();
        m=image[0].size();
        vector<vector<int>> adj(n, vector<int>(m));
        vector<vector<int>> visited(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                adj[i][j]=image[i][j];
            }
        }
        int initialColor=adj[sr][sc];
        dfs(sr,sc,newColor,initialColor,adj,visited);
        return adj;
        
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends
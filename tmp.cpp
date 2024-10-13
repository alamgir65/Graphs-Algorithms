//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  int visited[1003][1003];
  vector<pair<int,int>> dir={{0,-1},{-1,0},{0,1},{1,0}};
  int n,m;
  bool isValid(int i,int j){
      return (i<n && i>=0 && j<m && j>=0);
  }
  void bfs(int r,int c,int color,vector<vector<int>> &image,int initialColor){
      queue<pair<int,int>> q;
      visited[r][c]=1;
      q.push({r,c});
      while(!q.empty()){
          int nR=q.front().first,nC=q.front().second;
          q.pop();
          image[nR][nC]=color;
          for(auto d:dir){
              int i=nR+d.first;
              int j=nC+d.second;
              if(isValid(i,j) && !visited[i][j] && image[i][j]==initialColor){
                  visited[i][j]=1;
                  q.push({i,j});
              }
          }
      }
  }
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        n=image.size();
        m=image[0].size();
        int initialColor=image[sr][sc];
        bfs(sr,sc,newColor,image,initialColor);
        return image;
        // Code here
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
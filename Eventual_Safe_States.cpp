//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  bool dfs(int node,vector<int> adj[],vector<int> &visited,vector<int> &pathVisited,vector<int> &check){
      visited[node]=1;
      pathVisited[node]=1;
      check[node]=0;
      for(auto child:adj[node]){
          if(!visited[child]){
              if(dfs(child,adj,visited,pathVisited,check)==true){
                  check[child]=0;
                  return true;
              }
          }
          else if(pathVisited[child]){
              check[child]=0;
              return true;
          }
      }
      check[node]=1;
      pathVisited[node]=0;
      return false;
  }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V,0);
        vector<int> pathVisited(V,0),check(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,pathVisited,check);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(check[i]==1) ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
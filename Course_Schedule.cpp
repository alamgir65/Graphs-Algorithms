// Problem Link : https://www.geeksforgeeks.org/problems/course-schedule/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=course-schedule
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int> adj[N];
	    for(auto u:prerequisites){
	        adj[u[1]].push_back(u[0]);
	    }
	    int inDegree[N]={0};
	    for(int i=0;i<N;i++){
	        for(auto v:adj[i]) inDegree[v]++;
	    }
	    queue<int> q;
	    for(int i=0;i<N;i++) if(inDegree[i]==0) q.push(i);
	    vector<int> ans;
	    while(!q.empty()){
	        int u=q.front();
	        q.pop();
	        ans.push_back(u);
	        for(auto v:adj[u]){
	            inDegree[v]--;
	            if(inDegree[v]==0) q.push(v);
	        }
	    }
	    if(ans.size()==N) return ans;
	    else return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    
cout << "~" << "\n";
}
    
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[N];
	    for(auto u:prerequisites){
	        adj[u.first].push_back(u.second);
	    }
	    int inDegree[N]={0};
	    for(int i=0;i<N;i++){
	        for(auto v:adj[i]) inDegree[v]++;
	    }
	    queue<int> q;
	    for(int i=0;i<N;i++) if(inDegree[i]==0) q.push(i);
	    int cnt=0;
	    while(!q.empty()){
	        int u=q.front();
	        q.pop();
	        cnt++;
	        for(auto v:adj[u]){
	            inDegree[v]--;
	            if(inDegree[v]==0) q.push(v);
	        }
	    }
	    return cnt==N;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends
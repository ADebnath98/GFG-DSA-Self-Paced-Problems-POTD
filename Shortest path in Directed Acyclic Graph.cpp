//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int, int>>adj[N];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v, wt});
        }
        vector<int>ans(N, INT_MAX);
        ans[0]=0;
        queue<pair<int, int>>q;
        q.push({0, 0});
        while(!q.empty()){
            int node=q.front().first;
            int wt=q.front().second;
            q.pop();
            
            for(auto it:adj[node]){
                int adjN=it.first;
                int adjW=it.second;
                if(adjW+wt<ans[adjN]){
                    ans[adjN]=adjW+wt;
                    q.push({adjN, ans[adjN]});
                }
            }
        }
        for(int i=0; i<N; i++){
            if(ans[i]==INT_MAX){
                ans[i]=-1;
            }
        }
        return ans;
     }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
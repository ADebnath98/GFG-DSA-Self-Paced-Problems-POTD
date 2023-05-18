//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int f(int i,int j,int n,int m,vector<vector<int>>& matrix,vector<vector<int>>&vis){
          if(i>=n || i<0 || j>=m || j<0){
              return 0;
          }
          if(matrix[i][j]==0 || vis[i][j]){
              return 1;
          }
          vis[i][j]=1;
          
          int l=f(i,j-1,n,m,matrix,vis);
          int r=f(i,j+1,n,m,matrix,vis);
          int u=f(i-1,j,n,m,matrix,vis);
          int d=f(i+1,j,n,m,matrix,vis);
          return (l && r && u && d);
    }
    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        // Code here
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && matrix[i][j]){
                   cnt+= f(i,j,n,m,matrix,vis);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends
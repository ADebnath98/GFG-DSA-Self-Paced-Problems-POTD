//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//User function Template for C++

class Solution{   
public:
    int dir[5] = {-1, 0, 1, 0, -1};
    void dfs(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &visited){
        int n = mat.size();
        int m = mat[0].size();
        visited[i][j] = 1;
        
        for(int k = 0; k<4; k++){
            int x = i + dir[k];
            int y = j + dir[k + 1];
            if(x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && mat[x][y] >= mat[i][j]){
                dfs(mat, x, y, visited);
            }
        }
    }
    
    int water_flow(vector<vector<int>> &mat,int n,int m){
    // Write your code here.
       vector<vector<int>> indian(n, vector<int>(m, 0)), arabian(n, vector<int>(m, 0));
       
       for(int i = 0; i<n; i++){
           dfs(mat, i, 0, indian);
           dfs(mat, i, m - 1, arabian);
       }
       
       for(int j = 0; j<m; j++){
           dfs(mat, 0, j, indian);
           dfs(mat, n - 1, j, arabian);
       }
       
       int ans = 0;
       for(int i = 0; i<n; i++){
           for(int j = 0; j<m; j++){
               if(indian[i][j] && arabian[i][j]) ans++;
           }
       }
       
       return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends
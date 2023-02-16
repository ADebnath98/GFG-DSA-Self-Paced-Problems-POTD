//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int dfs(int i,vector<int> &arr,int n,vector<int> &vis,vector<int> &dp){
        if(i<0 or i>=n) 
        return 1;// out of bound means not stuck in infinite loop
        if(dp[i]!=-1) 
        return dp[i];// The index is marked previously as good/bad
        if(vis[i]) 
        return 0;// The index is not marked as good/bad and is revisited -> cycle detected
        vis[i]=1;
        return dp[i]=dfs(i+arr[i],arr,n,vis,dp);
    }
    int goodStones(int n,vector<int> &arr){
        // Code here
        vector<int> vis(n,0),dp(n,-1);
        for(int i=0;i<n;i++){
            if(!vis[i])
            dfs(i,arr,n,vis,dp);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            // dp[i] = 1 -> good stone
            // dp[i] = 0 -> bad stone
            if(dp[i]) ans++;
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
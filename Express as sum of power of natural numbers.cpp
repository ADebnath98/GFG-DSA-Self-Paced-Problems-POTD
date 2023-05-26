//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int mod=1e9+7;
    int ways(int n,int x,int index,int high,vector<vector<long long>> &dp){
        if(n==0) return 1;
        if(index>high) return 0;
        if(n<0) return 0;
        if(dp[n][index]!=-1) return dp[n][index];
        long long int zz=pow(index,x);
        int selected=ways(n-zz,x,index+1,high,dp);
        int not_selected=ways(n,x,index+1,high,dp);
            return dp[n][index]=(selected+not_selected)%mod;
    }
    int numOfWays(int n, int x)
    {
        int Highest=pow(n,1.0/x);
        vector<vector<long long>> dp (n+1,vector<long long>(Highest+1,-1));
        return ways(n,x,1,Highest,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends
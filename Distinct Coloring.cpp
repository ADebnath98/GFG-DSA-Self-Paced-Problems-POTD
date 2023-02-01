//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int n, int r[], int g[], int b[]){
        long long int dp[3][n];
        dp[0][n-1]=r[n-1];
        dp[1][n-1]=g[n-1];
        dp[2][n-1]=b[n-1];
        for(int i=n-2; i>=0; i--){
            dp[0][i]=r[i]+min(dp[1][i+1], dp[2][i+1]);
            dp[1][i]=g[i]+min(dp[0][i+1], dp[2][i+1]);
            dp[2][i]=b[i]+min(dp[0][i+1], dp[1][i+1]);
        }
        return min(dp[0][0], min(dp[1][0], dp[2][0]));
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    long long solve(int i,int prev,vector<int>&A,int n,vector<vector<long long>>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }
        if(prev==0){
            dp[i][prev]=max(A[i]+solve(i+1,0,A,n,dp),solve(i+1,1,A,n,dp));
        }
        else{
            dp[i][prev]=A[i]+solve(i+1,0,A,n,dp);
        }
        return dp[i][prev];
    }
  
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        vector<vector<long long>>dp(N,vector<long long >(2,-1));
        return max(solve(0,0,A,N,dp),solve(1,1,A,N,dp));
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
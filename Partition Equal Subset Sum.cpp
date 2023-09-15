//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool cp(int& N, int i, int a[], int target, vector<vector<int>>& dp){
        if(target == 0)
            return true;
        
        if(i >= N)
            return false;
           
        if(target >= a[i]){
            bool take = cp(N,i+1,a,target - a[i], dp);
            if(take)
                return dp[i][target] = true;
        }
        
        bool notTake = cp(N,i+1,a,target, dp);
        return dp[i][target] = notTake;
    }
    
    bool equalPartition(int N, int a[])
    {
        int sum = 0;
        for(int i = 0; i<N;++i){
            sum += a[i];
        }
        if(sum % 2 != 0) // If the sum is odd, it's impossible to partition into equal subsets.
            return false;
            
        int target = sum/2;
        vector<vector<int>> dp(N,vector<int>(target+1,-1));
        return cp(N,0,a,target, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
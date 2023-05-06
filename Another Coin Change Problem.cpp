//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
        // code here
        vector<vector<int>> dp;
    bool solve(int N, int k, int target, vector<int> &coins)
    {
        
        if(k == 0 && target == 0)
            return dp[target][k] = true;
        if(dp[target][k] != -1)
            return dp[target][k];
  
        bool ans = false;
        for(int i = 0; i <= N; i++)
        {
            if(coins[i] <= target && k > 0)
            {
                ans = ans || solve(N,k-1,target-coins[i],coins);
            }
        }
        return dp[target][k] = ans;
    }
    bool makeChanges(int N, int K, int target, vector<int> &coins) 
    {
       dp = vector<vector<int>>(target+1,vector<int>(K+1,-1));      
       return solve(N-1,K,target,coins); // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends
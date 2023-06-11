//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int binaryfun(int i, vector<vector<int>>&arr)
    {
            int lo= i+1;
            int hi=arr.size()-1;
            int ans=-1;
            while(lo<=hi)
            {
                  int mid=lo+ (hi-lo)/2;
                  if(arr[i][1] <=arr[mid][0])
                  {
                       ans=mid;
                       hi=mid-1;
                  }
                  else
                  {
                       lo=mid+1;
                  }
            }
        return ans;
    }
    int rec(int i, vector<vector<int>>&arr,vector<int>&dp)
    {
          if(i==arr.size())
          return 0;
          if(dp[i]!=-1)
          return dp[i];
          
          int skip= rec(i+1,arr,dp);
          
          int j= binaryfun(i,arr);
          
          int take= arr[i][2];
          if(j!=-1)
          take += rec(j,arr,dp);
          
          dp[i]= max(take,skip);
          return dp[i];
    }
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        // Write your code here.
        sort(intervals.begin(),intervals.end());
        vector<int>dp(n,-1);
        return rec(0,intervals,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends
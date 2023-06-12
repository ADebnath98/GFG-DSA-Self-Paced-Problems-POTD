//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    vector<int> dp;
    int solve(int RLen,int price[],int n){
      
      if(RLen==0){
          return 0;
      }
      if(dp[RLen]!=-1){
          return dp[RLen];
      }
      int ans=0;
      for(int len=0;len<n;len++){
          if(len+1<=RLen){
              ans=max(ans,price[len]+solve(RLen-len-1,price,n));
          }
      }
      return dp[RLen]=ans;
  }
    int cutRod(int price[], int n) {
        //code here
        dp.resize(n+1,-1);
        return solve(n,price,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
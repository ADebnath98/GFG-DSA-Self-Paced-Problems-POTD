//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> leastPrimeFactor(int n) 
    {
        vector<int>ans;
        ans.push_back(0);
        ans.push_back(1);
        if(n==1)
        {
            return ans;
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=i;j++)
            {
                if(i%j==0)
                {
                    ans.push_back(j);
                    break;
                }
            }
        }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
        int minOperation(string s) {
        int mx = 0,n = s.size();
        for(int i=1;i<=n/2;i++) {
            for(int j = i;j<=n - i;j++) {
                if(s.substr(j-i, i) == s.substr(j, i)) {
                    mx = max(mx, i);
                    break;
                }
            }
        }
        return mx == 0?n:n -mx + 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends
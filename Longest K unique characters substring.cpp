//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    vector<int> freq (26, 0);
        
        int start = 0, end = 0, ans = -1, n = s.size(), unique = 0;
        
        while(end < n) {
            if(freq[s[end] - 'a'] == 0)   unique++;
            
            freq[s[end] - 'a']++;
            
            
            while(unique > k) {
                if(freq[s[start] - 'a'] == 1) {
                    unique--;
                }
                
                freq[s[start++] - 'a']--;
            }
            
            if(unique == k) ans = max(ans, end - start + 1);
            end++;
        }
        
        return ans;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends
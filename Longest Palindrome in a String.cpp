//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int expandAroundCenter(string s, int left, int right, int n) {
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

string longestPalin(string s) {
    int n = s.length();
    int start = 0, maxLength = 0;
  
    
    for (int i = 0; i < n; i++) {
        int len1 = expandAroundCenter(s, i, i,n);
        int len2 = expandAroundCenter(s, i, i + 1,n);
        int length = max(len1, len2);
        if (length > maxLength) {
            maxLength = length;
            start = i - (length - 1) / 2;
        }
    }
    
    return s.substr(start, maxLength);
}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
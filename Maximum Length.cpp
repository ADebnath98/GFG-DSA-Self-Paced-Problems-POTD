//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) 
    {
        vector <int> v;
        v.push_back(a); v.push_back(b); v.push_back(c);
        sort(v.begin(),v.end());
        int x = v[0]+v[1];
        if ((x*2)+2 >= v[2])
        {
            return x+v[2];
        }
        else return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
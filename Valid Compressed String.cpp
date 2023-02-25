//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string s, string t) {
        int n=s.length();
        int m=t.length();
        int i=0;
        int j=0;
        while(i<n&&j<m)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else if(isdigit(t[j]))
            {
                int num=0;
                while(isdigit(t[j]))
                {
                    num=num*10+(t[j]-'0');
                    j++;
                }
                
                i+=num;
            }
            else
            return 0;
        }
        if(i==n&&j==m)
        return 1;
        else 
        return 0;
      
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends
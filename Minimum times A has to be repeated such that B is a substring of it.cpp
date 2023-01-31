//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {

  public:
    int minRepeats(string A, string B) {
        // code here
        string N="";
        int count=0;
       while(N.size()<=B.size()*2)
       {
           N+=A;
           count++;
           size_t found = N.find(B);
           if (found != string::npos)
           return count;
       }
       return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends
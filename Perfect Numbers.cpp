//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
     long long sum;
        for(int i=1;i<=sqrt(N);i++)
        {
            sum=0;
           sum= pow(2,i)*(pow(2,i+1)-1);
           if(sum==N)
            return 1;
        }
            return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
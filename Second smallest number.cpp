//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        int num[D];
        for (int i = D - 1; i > 0; i--) {
            int d = min(S - 1, 9);
            num[i] = d;
            S -= d;
        }
        if (S > 9) {
            return "-1";
        }
        num[0] = S;
        for (int i = D - 1; i > 0; i--) {
            if (num[i] != 0 && num[i - 1] != 9) {
                num[i] -= 1;
                num[i - 1] += 1;
                string res = "";
                for (int j = 0; j < D; j++) {
                    res += to_string(num[j]);
                }
            return res;
            }
        }
        return "-1";
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
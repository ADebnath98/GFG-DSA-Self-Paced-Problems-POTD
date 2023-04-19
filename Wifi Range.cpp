//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string s, int x){
        int pending=0,relax=0;
        for(auto &ch:s)
        {
            if(ch=='1')
            {
                pending=0;
                relax=x;
            }
            else
            {
                if(relax) relax--;
                else if(pending==x) return false;
                else pending++;
            }
        }
        return pending?false:true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends
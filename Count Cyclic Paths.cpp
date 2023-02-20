Time Complexity: O(n)
Space Complexity: O(1)

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    const int mod = 1e9+7;
    int countPaths(int n){
        long long int ans = 0;
        for(int i = 1; i < n; i++)
        {
            ans = ((ans%mod)*3)%mod;
            if(i%2 == 1) ans = (ans + 3)%mod;
            else ans = ans - 3;
        }
        return ans%mod;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends
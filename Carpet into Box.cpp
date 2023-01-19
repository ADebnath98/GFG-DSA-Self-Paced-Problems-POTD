//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findMoves(int a, int b, int c, int d){
        int moves=0;
        while(a>c || b>d){
            if(a>c) moves++; a/=2;
            if(b>d) moves++; b/=2;
        }
        return moves;
    }
    int carpetBox(int a, int b, int c, int d){
        return min(findMoves(a,b,c,d), findMoves(b,a,c,d));
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
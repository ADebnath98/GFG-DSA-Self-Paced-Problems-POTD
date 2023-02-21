TC : O(1) , SC : O(1)

Approach : 

Step 1 : Find the max distance from cell filled with 1 and the max(all 4 distances to all corners) will be the answer.


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        
         if (N == 1 && M == 1)
        {
            return 0;
        }
        int ans = 0;
        int X = x - 1;
        int Y = y - 1;
        // top left 
        ans = max(ans,X + Y);
        // bottom left
        ans = max(ans,(N - (X + 1)) + Y);
        // top right
        ans = max(ans,X + (M - (Y + 1)));
        // bottom right
        ans = max(ans,(N - (X + 1)) + (M - (Y + 1)));
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
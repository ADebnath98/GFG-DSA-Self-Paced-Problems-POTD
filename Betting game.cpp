//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
        int betBalance(string result)
        {
            // code here
            
            int sum = 4, bet = 1;
            for(int i = 0; i<result.size(); i++){
                if(sum<bet)
                return -1;
                if(result[i] == 'L'){
                    sum -= bet;
                    bet *= 2;
                }
                else{
                    sum += bet;
                    bet = 1;
                }
            }
            return sum;
        }
    
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string result;
        cin>>result;
        
        Solution ob;
        cout<<ob.betBalance(result)<<endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int solve(int i, int j, string str)
    {
        if(i==str.size() || j==str.size())
		        return 0;
		        
	    if(str[i]==str[j] && i!=j)
	    {
	        return 1+solve(i+1,j+1,str);
	    }
	    
	    return max(solve(i,j+1,str),solve(i+1,j,str));
    }
        
	int LongestRepeatingSubsequence(string str){
	    // Code here
	    
	    int n = str.size();
		    
		vector<vector<int>> dp(n+1,vector<int>(n+1));
	    int i,j;
	    
	    for(i=n-1;i>=0;i--)
	    {
	        for(j=n-1;j>=0;j--)
	        {
	            if(str[i]==str[j] && i!=j)
	                dp[i][j] = 1+dp[i+1][j+1];
	            else
	                dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
	        }
	    }
	    
	    return dp[0][0];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
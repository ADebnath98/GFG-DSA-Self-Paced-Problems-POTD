//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	private:
const int mod = 1e9 + 7;
    long solve(int i, string &s, vector<int> &dp) {
        
        if(i == s.size()) {
            return 1;
        }
        
        if(dp[i] != -1) {
            return dp[i];
        }
        
        long one = 0;
        if(s[i] >= '1' && s[i] <= '9') {
            one = solve(i+1, s, dp);
        }
        
        long two = 0;
        if(i < s.size()-1 && s[i] != '0' && s.substr(i, 2) >= "10" && s.substr(i, 2) <= "26") {
            two = solve(i+2, s, dp);
        }
        
        return dp[i] = (one + two)%mod;
    }
    
public:
	int CountWays(string str){
	    
	    vector<int> dp(str.size(), -1);
	    return (int)solve(0, str, dp);
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
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
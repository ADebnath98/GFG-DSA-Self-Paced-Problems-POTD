//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int MOD = 1e9+7;
	long long inv(long long int i){
	    
	    if(i == 1)
	    return 1;
	    return (MOD - ((MOD/i)*inv(MOD%i))%MOD+MOD)%MOD;
	}
	int compute_value(int n)
	{
	    // Code here
	    long long int ans = 1, nCr = 1;
	    for(int r  = 1; r <= n; r++){
	        nCr = ((nCr*(n+1 - r))%MOD)*inv(r)%MOD;
	        ans = (ans + (nCr*nCr)%MOD)%MOD;
	    }
	    return ans%MOD;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
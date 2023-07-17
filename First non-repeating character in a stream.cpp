//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		     vector<int> freq(26,0);
            queue<char> Q;
            int n=A.size();
            string result(n,'#');
            
            for(int i=0;i<n;i++)
            {
                int idx=A[i]-'a';
                freq[idx]++;
                
                if(freq[idx]==1)
                    Q.push(A[i]);
                
                while(Q.size()>0 && freq[Q.front()-'a']>1)
                    Q.pop();
                
                if(Q.size()>0)
                    result[i]=Q.front();
            }
            return result;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
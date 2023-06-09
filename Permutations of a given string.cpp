//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    map<char, int> mp;
		    for(char c : S) mp[c]++;
		    vector<string> ans;
		    perm(S, 0, ans, mp);
		    return ans;
		}
		
		void perm(string &s, int idx, vector<string>& ans, map<char, int>& mp) {
		    if(idx == s.length()) {
		        ans.push_back(s);
		        return;
		    }
		    
		    for(auto entry : mp) {
		        char c = entry.first;
		        int cnt = entry.second;
		        if(cnt == 0) continue;
		        mp[c]--;
		        s[idx] = c;
		        perm(s, idx+1, ans, mp);
		        mp[c]++;
		    }
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
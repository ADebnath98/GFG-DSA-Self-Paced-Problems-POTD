//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        unordered_map<char, int> mp;
        for(auto c : S) mp[c]++; //counting frequency of each char
        int s = 0, e = S.size()-1;
        bool f = false;
        while(s<=e) {
            if(!f) { //if not revresed
                if(mp.at(S[s]) > 1) {   
                    mp[S[s]]--;
                    S[s] = '#';
                    f = true;
                }
                s++;
            }
            else {
                if(mp.at(S[e]) > 1) {
                    mp[S[e]]--;
                    S[e] = '#';
                    f = false;
                }
                e--;
            }
        }
        if(f) reverse(S.begin(), S.end());
        string ans = "";
        for(auto c : S) {
            if(c != '#') ans += c;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
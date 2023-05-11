//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        // code here
        int n= s.size();
        for(int i=0;i<n/2;i++){
            if((s[i]=='?' or s[n-i-1]=='?') and s[i]!=s[n-i-1]){
                if(s[i]!='?'){
                    s[n-i-1]= s[i];
                }
                else{
                    s[i]=s[n-i-1];
                }
            }
            else if(s[i]!=s[n-i-1] and s[i]!='?' and s[n-i-1]!='?'){
                return -1;
            }
            
        }
        int ans=0;
        char prev='?';
        for(int i=0;i<n;i++){
            
            if(s[i]!='?')
            {
                prev=s[i];
                break;
            }
            
        }
        for(int i=0;i<n/2;i++){
            if(s[i]=='?'){
                s[i]=prev;
                s[n-i-1]= prev;
            }
            else{
                prev=s[i];
            }
        }
        
       // cout<<s[0];
        for(int i=1;i<n;i++){
         //   cout<<s[i]<<" ";
            ans+= abs((s[i]-'a')-(s[i-1]-'a'));
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
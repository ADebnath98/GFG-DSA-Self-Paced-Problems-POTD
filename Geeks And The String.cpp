//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    string removePair(string s) {
       stack<int>st;
        for(int i =0;i<s.size();i++){
            if(!st.empty() && st.top()==s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        
        string sl = "";
        while(!st.empty()){
           sl+=st.top();
            st.pop();
        }
        reverse(sl.begin(),sl.end());
        if(sl=="")
        sl+="-1";
        return sl;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}
// } Driver Code Ends
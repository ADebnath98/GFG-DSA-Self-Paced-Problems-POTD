//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            stack<string>st;
            string temp="";
            for(int i=0;i<s.size();i++){
                if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                    st.push(temp);
                    st.push(string(1, s[i]));
                    temp="";
                }
                else if(i==s.size()-1){
                    if(temp.size()==0){
                        st.push(string(1, s[i]));
                    }
                    else{
                        temp+=s[i];
                        st.push(temp);
                    }
                }
                else
                temp+=s[i];
            }
            string ans;
            while(!st.empty()){
                ans+=st.top();
                st.pop();
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
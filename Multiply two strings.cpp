//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string add(string s1, string s2){
        int i = s1.length()-1;
        int j = s2.length()-1;
        string ans = "";
        int carry = 0;

        while(i >= 0 && j >= 0){
            int digit = (s1[i] - '0') + (s2[j] - '0') + carry;
            ans += (digit % 10) + '0';
            carry = digit / 10;
            i--, j--;
        }

        while(i >= 0){
            int digit = (s1[i] - '0') + carry;
           ans += (digit % 10) + '0';
            carry = digit / 10;
            i--;
        }

        while(j >= 0){
            int digit = (s2[j] - '0') + carry;
            ans += (digit % 10) + '0';
            carry = digit / 10;
            j--;
        }

        if(carry != 0){
            ans += (carry) + '0';
        }

        reverse(ans.begin(),ans.end());
        for(int i=0; i<ans.length(); i++){
            if(ans[i]!='0')
            return ans.substr(i);
        }
        
        return "0";
        
    }

    string multiply(string s, int a){
        int carry = 0;
        int n = s.length();
        string ans = "";

        for(int i=n-1; i>=0; i--){
            if(s[i] == '-'){
                continue;
            }

            int digit = (s[i] - '0') * a + carry;
            ans += (digit % 10) + '0';
            carry = digit / 10;

        }
        if(carry != 0){
            ans += (carry + '0');
        }
        reverse(ans.begin(), ans.end());
        // cout<<ans<<endl;
        return ans;
    }

    
    string multiplyStrings(string num1, string num2) {
       //Your code here
        string ans = "";
        string zero = "";
        
        bool a1 = 0, a2 = 0;
        
        for(auto it : num1){
            if(it == '-'){
                a1 = true;
            }
        }
        for(auto it : num2){
            if(it == '-'){
                a2 = true;
            }
        }

        for(int i=num2.length()-1; i>=0; i--){
            if(num2[i] == '-'){
                continue;
            }
            int a = num2[i] - '0';
            string curr = multiply(num1, a);
            curr += zero;
            zero += '0';

            //cout<<curr<<endl;
            ans = add(ans, curr);
        }
        if((a1 && a2) || (!a1 && !a2))
           return ans;
        
        return "-" + ans;
    }
};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findNumber(long long N){
        // Code here

        string ans="";
        while(N){
            if(N%5==1){
                ans+='1';
                N/=5;
            }
            else if(N%5==2){
                ans+='3';
                N/=5;
            }
            else if(N%5==3){
                ans+='5';
                N/=5;
            }
            else if(N%5==4){
                ans+='7';
                N/=5;
            }
            else if(N%5==0){
                ans+='9';
                N=N/5-1;
            }
        }
        reverse(ans.begin(),ans.end());
        long long res = stol(ans);
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
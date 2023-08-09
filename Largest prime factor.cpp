//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        // code here
        
        vector <int>ans;
        for(int i=2;i<=N;i++)
        {
            while(N%i==0)
            {
                ans.push_back(i);
                N=N/i;
            }
        }
        int maxi=-1;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]>maxi)
            {
                maxi=ans[i];
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here 
        int st=0;
        int end=0;
        int ans=0;
        
        while(end!=n)
        {
            if(m>0)
            {
                if(arr[end]=='O')
                {
                    m--;
                }
            }
            else
            {
                if(arr[end]=='O')
                {
                    while(arr[st]!='O')
                    {
                        st++;
                    }
                    st++;
                }
            }
            ans=max(ans,end-st+1);
            end++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        // Code here
        
        map<int,int> mp;
        int ans=-1,prev=0,range=0;
        
        for(auto x:intervals)
        {
            mp[x[0]]++;
            mp[x[1]+1]--;
        }
        
        for(auto x:mp)
        {
            if(mp[range]>=k)
            {
                ans=max(ans,x.first-1);
            }
            mp[x.first]=x.second+prev;
            prev=mp[x.first];
            
            range=x.first;

            if(mp[x.first]>=k)
                ans=x.first;
        }
        
        if(mp[range]>=k)
        {
            ans=max(ans,range-1);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
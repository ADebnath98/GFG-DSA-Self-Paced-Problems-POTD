//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long find(int pos,int ind,vector<int>& temp,map<int,pair<int,int>>& mp,vector<vector<long long>>& dp,int indication)
    {
        if(ind==temp.size()) return 0;
        if(dp[ind][indication]!=-1) return dp[ind][indication];
        pair<int,int> val=mp[temp[ind]];
        int left=val.first;
        int right=val.second;
        long long one=0,two=0;
        one = abs(pos-left)+abs(left-right)+find(right,ind+1,temp,mp,dp,1);
        if(ind==temp.size()-1) one+=abs(right);
        two = abs(pos-right)+abs(left-right)+find(left,ind+1,temp,mp,dp,0);
        if(ind==temp.size()-1) two+=abs(left);
        return dp[ind][indication]=min(one,two);
    }
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
       map<int,pair<int,int>> mp;
       vector<int> temp;
       for(int i=0;i<n;i++)
       {
           if(mp.find(types[i])==mp.end())
           {
               mp[types[i]]={locations[i],locations[i]};
               temp.push_back(types[i]);
           }
           else
           {
               mp[types[i]].first=min(locations[i],mp[types[i]].first);
               mp[types[i]].second=max(locations[i],mp[types[i]].second);
           }
       }
       sort(temp.begin(),temp.end());
       vector<vector<long long>> dp(temp.size(),vector<long long>(2,-1));
       return find(0,0,temp,mp,dp,0);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
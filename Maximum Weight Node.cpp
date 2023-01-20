//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)

  {

      // code here

       unordered_map<int,int> mp;

      for(int i=0;i<N;i++){

          mp[i]=0;

      }

      for(int i=0;i<N;i++){

          if(Edge[i]!=-1)mp[Edge[i]]+= i;

      }

      int maxWt=-1;

      int ans=0;

      for(auto x:mp){

          if(ans==-1){

              maxWt=x.second;

              ans=x.first;

          }else{

              if(x.second==maxWt){

                  ans=max(ans,x.first);

              }else if(x.second>maxWt){

                  maxWt=x.second;

                  ans=x.first;

              }

          }

      }

      return ans;

  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends
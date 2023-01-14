//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
  vector<int> maximumToys(int N,vector<int> A,int Q,vector<vector<int>> Queries){
      // code here
    vector<int> ans(Q);
    vector<long long> prefix(N);
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++)
    {
        arr[i] = {A[i], i};
    }
    sort(arr.begin(), arr.end());
    unordered_map<int, int> mp;
    for (int i = 0; i < N; i++)
    {
        mp[arr[i].second] = i;
    }
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i].first;
        prefix[i] = sum;
    }
    for (int m = 0; m < Q; m++)
    {
        int money = Queries[m][0];
        int k = Queries[m][1];
        int idx = upper_bound(prefix.begin(), prefix.end(), money) - prefix.begin();
        vector<int> v(k);
        for (int i = 0; i < k; i++)
        {
            v[i] = mp[Queries[m][i + 2] - 1];
        }
        sort(v.begin(), v.end());
        int count = 0, j;
        for (int i = 0; i < k; i++)
        {
            j = v[i];
            if (j < idx)
            {
                count++;
                money += arr[j].first;
                idx = upper_bound(prefix.begin(), prefix.end(), money) - prefix.begin();
            }
        }
        ans[m] = idx - count;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    int N;
    cin>>N;
    vector<int>A(N);
    for(auto &i:A){
      cin>>i;
    }
    int Q;
    cin>>Q;
    vector<vector<int>> Queries(Q);
    for(int i=0;i<Q;i++){
      int x,y;
      cin>>x>>y;
      Queries[i].push_back(x);
      Queries[i].push_back(y);
      for(int j=0;j<Queries[i][1];j++){
        cin>>x;
        Queries[i].push_back(x);
      }
    }
    Solution obj;
    auto ans =obj.maximumToys(N,A,Q,Queries);
    for(auto i:ans)
      cout<<i<<" ";
    cout<<endl;
 }
}
// } Driver Code Ends
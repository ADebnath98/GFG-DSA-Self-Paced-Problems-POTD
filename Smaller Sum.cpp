//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<int> gg(n,0);
        iota(begin(gg),end(gg),0);
        auto cmp = [&](int &a,int &b)
        {
            return arr[a]<arr[b];
        };
        sort(begin(gg),end(gg),cmp);
        vector<long long> ans(n,0);
        
        long long sum = 0, tmp = arr[gg[0]];
        
        for(int i=1;i<n;i++)
        {
            if(arr[gg[i-1]]==arr[gg[i]])
            {
                tmp+=arr[gg[i]];
            }
            else
            {
                sum+=tmp;
                tmp=arr[gg[i]];
            }
            ans[gg[i]]=sum;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends
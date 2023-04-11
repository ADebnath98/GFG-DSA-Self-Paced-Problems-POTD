//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        
        int i = 0, j = n/2, ans = 0;
        
        sort(begin(arr), begin(arr)+j);
        sort(begin(arr)+j, end(arr));
        
        while(i < n/2) {
            if(j < n and arr[i] >= 5*arr[j])j++;
            else {
                ans += j-(n/2);
                i++;
            }
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
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends
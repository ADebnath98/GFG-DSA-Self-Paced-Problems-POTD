//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        vector<int>suf(n);
        suf[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        suf[i]=max(suf[i+1],arr[i]);
        
        int ans=0;
        for(int i=0;i<n-1;i++){
            int low=i+1;
            int high=n-1;
            int mid;
            int index=i;
            while(low<=high){
                mid=low+(high-low)/2;
                if(suf[mid]>=arr[i]){
                    index=mid;
                    low=mid+1;
                }
                else high=mid-1;
            }
            ans=max(ans,index-i);
        }
        return ans;// code here
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int>v(n,0);
        for (int i = 0;i<n;i++){
            v[arr[i]]++;
            
        }
        vector<int>v1={};
        for (int j = 0;j<n;j++){
            if (v[j]>1){
                v1.push_back(j);
            }
        }
        if (v1.size()){
            return v1;
        }
        else 
          return {-1} ;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
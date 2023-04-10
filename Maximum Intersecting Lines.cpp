//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> l, int n) {
        // Code here
        map<int,int> m;
        
        for(int i=0;i<n;i++){
            m[l[i][0]] += 1;
            m[l[i][1]+1] -= 1;
        }
        int c=0,pre_sum=0;
        for(auto x: m){
            pre_sum += x.second;
            c = max(c,pre_sum);
        }
        return c;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends
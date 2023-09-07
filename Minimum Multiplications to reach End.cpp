//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    const int mod = 100000;
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        queue<pair<int, int>> q;
        q.push({start, 0});
        vector<int> vis(mod, 0);
        vis[start] = 1;
        while (!q.empty())
        {
            auto tp = q.front();
            q.pop();
            int curr = tp.first;
            int step = tp.second;
            if (curr == end)
            {
                return step;
            }
            for (int x : arr)
            {
                int imd = (1LL * x * curr) % mod;
                if (!vis[imd])
                {
                    vis[imd] = 1;
                    q.push({imd, step + 1});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
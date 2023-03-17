//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &arr) {
    vector<long long int> count;
    for(int i=0; i<n; i++){
        int cnt = 0;
        if(arr[i] == 0){
            while(i<n && arr[i] == 0){
                cnt++;
                i++;
            }
            count.push_back(cnt);
        }
    }
    long long int ans = 0;
    for(int i=0; i<count.size(); i++){
        //long long int a = count[i]; 
        ans+=(((count[i])*(count[i]+1))/2);
    }
    return ans;
}

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
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends
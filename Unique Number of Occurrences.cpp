//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[]) {
        unordered_map<int, int> frequencyCount;
        for (int i = 0; i < n; i++) {
            frequencyCount[arr[i]]++;
        }
        unordered_map<int, int> uniqueFrequencies;
        for (const auto& pair : frequencyCount) {
            if (uniqueFrequencies.find(pair.second) != uniqueFrequencies.end()) {
                return false;
            }
            uniqueFrequencies[pair.second] = 1;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        //in this problem we have to find the max sum from using these two array
        //brute force is to sum all the pair from the two given array and sort them and return k largest elment
        // time complexity of this approch is O(n^2logn)
        // efficient approach to use priority queue it gives the kth largest as its top k eelments
        // here we used set as visited set to check which element is visited or not.
        vector<int>ans;
        sort(A.begin(),A.end(),greater<int>());
        sort(B.begin(),B.end(),greater<int>());
        set<pair<int,int>>s;
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({A[0]+B[0],{0,0}});
    
        for(int i=0;i<K;i++)
        {
            pair<int,pair<int,int>>p=pq.top();
            pq.pop();
            ans.push_back(p.first);
            if (p.second.first + 1 < A.size() && s.find({p.second.first+1, p.second.second}) == s.end()) {
           pq.push({A[p.second.first+1]+B[p.second.second],{p.second.first+1,p.second.second}});
s.insert({p.second.first+1,p.second.second});
}
            
            if(p.second.second+1<A.size()&&s.find({p.second.first,p.second.second+1})==s.end()){
            pq.push({A[p.second.first]+B[p.second.second+1],{p.second.first,p.second.second+1}});
            s.insert({p.second.first,p.second.second+1});
                
            }
        }
        return ans;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
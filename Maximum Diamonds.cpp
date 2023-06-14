//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int A[], int N, int K) {
        // code here
         priority_queue<int> maxHeap;

    for (int i = 0; i < N; i++) {
        maxHeap.push(A[i]);
    }

    long long maxDiamonds = 0;

    
    while (K > 0) {
        
        int diamonds = maxHeap.top();
        maxHeap.pop();
        maxDiamonds += diamonds;
        diamonds /= 2;
        maxHeap.push(diamonds);
        K--;
    }

    return maxDiamonds;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends
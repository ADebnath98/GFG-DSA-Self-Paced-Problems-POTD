//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
    
        int freq[26]={0};
        int maxf=0;
        for(auto i:tasks)
        {
            freq[i-'A']++;
            maxf=max(maxf,freq[i-'A']);
        }
        int maxfcount = 0;
        for(int i=0; i<26; i++){
            if(freq[i]==maxf)maxfcount++;
        }
        
     int time = (maxf-1)*(K+1)+maxfcount;
      return max(time,N);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends
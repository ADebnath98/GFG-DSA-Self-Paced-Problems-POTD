//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        
        // Check if N is divisible by size
        if(N%groupSize) return false;
        
        // Create a map of card to frequency
        map<int,int>m;
        for(auto x:hand) m[x]++;
        
        // Procedurally distribute the cards into
        // groups of consecutive cards. If at any
        // point a card is needed but not found
        // return false.
        int ng=N/groupSize;
        for(int i=0;i<ng;i++){
            int st=(m.begin())->first;
            for(int j=0;j<groupSize;j++){
                if(!m.count(st)) return false;
                m[st]--;
                if(m[st]==0) m.erase(st);
                st++;
            }
        }
        
        // Return true when all groups formed
        // successfully.
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int decimalToBinary(int N){
        vector<int> v;
        while(N!=0){
            v.push_back(N%2);
            N/=2;
        }
        reverse(v.begin(),v.end());
        int a=0;
        for(auto i:v){
            if(i==1){
                a++;
            }
        }
        return a;
    }
    int setBits(int N) {
        return decimalToBinary(N); 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends
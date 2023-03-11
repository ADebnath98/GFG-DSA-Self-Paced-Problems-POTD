//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> solveQueries(int n, int num, vector<int> &a, vector<vector<int>> &Q) {
        
        int count = 0;
        int freq[n];
        map<int, int> m;
        vector<int> ans;
        
        for(int i = n - 1; i >= 0; i--)
        {
            m[a[i]]++;
            freq[i] = m[a[i]];
        }
        
        
        for(int i = 0; i < num; i++)
        {
            for(int j = Q[i][0]; j <= Q[i][1]; j++)
            {
                if(freq[j] == Q[i][2])
                {
                    count++;
                }
            }
            
            ans.push_back(count);
            count = 0;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends
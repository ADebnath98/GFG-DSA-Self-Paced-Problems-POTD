//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        vector<int> adj[N+1];
        for(int i=1; i<N; i++){
            adj[P[i]].push_back(i+1);
        }
        
        long long ans = LLONG_MIN;
        for(int i=1; i<=N; i++){
            ans = max(ans, dfs(i, adj, A, 0));
        }
        
        return ans;
    }
    
    long long dfs(int node, vector<int> adj[], vector<int> &A, bool f){
        long long ans = LLONG_MIN;
        for(int child: adj[node]){
            ans = max(ans, dfs(child, adj, A, !f));
        }
        
        long long nodeVal = A[node-1];
        if(f)
            nodeVal = -nodeVal;
        if(ans == LLONG_MIN)
            return nodeVal;
        return ans + nodeVal;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
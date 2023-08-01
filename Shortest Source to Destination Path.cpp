//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int bfs(int X,int Y,int N,int M,vector<vector<int>> a, vector<vector<int>>&v1,int rows[],int cols[]){
        queue<pair<int,int>>q1;
        q1.push({0,0});
        q1.push({-1,-1});
        int count=0;
        while(q1.size()>1){
            if(q1.front().first==-1){
                q1.pop();
                count++;
                q1.push({-1,-1});
            }
            else{
                int l1=q1.front().first;
                int l2=q1.front().second;
                v1[l1][l2]=1;
                if(l1==X && l2==Y){
                    return count;
                }
                for(int i=0;i<4;i++){
                    if(l1+rows[i]>=0 && l1+rows[i]<N && l2+cols[i]>=0 && l2+cols[i]<M && a[l1+rows[i]][l2+cols[i]]==1 && v1[l1+rows[i]][l2+cols[i]]==0)
                    {   v1[l1+rows[i]][l2+cols[i]]=1;
                        q1.push({l1+rows[i],l2+cols[i]});
                    }
                }
                q1.pop();
            }
        }
        return -1;
    }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        vector<vector<int>>v1(N,vector<int>(M,0));
        int rows[]={1,0,-1,0};
        int cols[]={0,-1,0,1};
        int l=bfs(X,Y,N,M,A,v1,rows,cols);
        return l;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends
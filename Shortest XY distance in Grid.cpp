//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(N,vector<bool>(M,0));
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(grid[i][j]=='Y')
                {
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        // x,y -> (x-1)(y) , (x,y+1) , (x+1,y) , (x,y-1)
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        int steps=0;
        while(!q.empty())
        {
            int qsize=q.size();
            while(qsize--)
            {
                 auto it=q.front();
                 q.pop();
                 int x=it.first,y=it.second;
                 
                 if(grid[x][y]=='X') return steps;
                 
                 for(int k=0;k<4;k++)
                 {
                     int adji=x+dx[k],adjj=y+dy[k];
                     if(adji>=0 && adjj>=0 && adji<N && adjj<M && !visited[adji][adjj])
                     {
                         q.push({adji,adjj});
                         visited[adji][adjj]=true;
                     }
                 }
            }
           steps++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends
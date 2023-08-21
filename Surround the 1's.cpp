//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int res=0;
        vector<pair<int,int>> p{{0,1},{1,0},{0,-1},{-1,0},{-1,1},{1,1},{1,-1},{-1,-1}};
        int r=matrix.size(),c=matrix[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==1){
                    int cnt=0;
                    for(auto t: p){
                        int x=i+t.first;
                        int y=j+t.second;
                        if(x<r and y<c and x>=0 and y>=0 and matrix[x][y]==0){
                            cnt++;
                        }
                    }
                    if(cnt%2==0 and cnt!=0) {
                        res++;
                    }
                }
            }
        }
        return res;
    
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
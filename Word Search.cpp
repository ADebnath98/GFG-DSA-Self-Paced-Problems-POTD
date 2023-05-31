//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    bool helper(vector<vector<char>>& board,string word,vector<vector<bool>>& vis,int i,int j,int len){
        int n=board.size();
        int m=board[0].size();
    
        //base cases
       if(len==word.length()){
           return true;
       }
       if(i<0||j<0||i>=n||j>=m){
           return false;
       }
       if(board[i][j]!=word[len] ){
           return false;
       }
       if(vis[i][j]==true){
           return false;
       }
       
       vis[i][j] = true;

        if (helper(board, word, vis, i - 1, j, len + 1) || 
            helper(board, word, vis, i, j + 1, len + 1) ||
            helper(board, word, vis, i + 1, j, len + 1) ||
            helper(board, word, vis, i, j - 1, len + 1)) {
            return true;
        }

        vis[i][j] = false;

        return false;
    }
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size();
        int m=board[0].size();
        
       vector<vector<bool>> vis(n,vector<bool>(m,false));
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                
                if(word[0]==board[i][j] && (helper(board,word,vis,i,j,0))){
                    return true;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends
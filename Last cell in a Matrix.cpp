//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    bool check(int x , int y , int r , int c){
        if(x < 0 || x >= c || y < 0 || y >= r)
            return false;
        return true;
    }
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int r, int c){
        int iterx = 0 , itery = 0 , dr = 0;
        int dry[] = {0 , 1 , 0 , -1};
        int drx[] = {1 , 0 , -1 , 0};
        while(check(iterx , itery , r , c)){
            if(matrix[itery][iterx]){
                dr = (dr + 1) % 4;
                matrix[itery][iterx] = 0;
            }
            iterx += drx[dr];
            itery += dry[dr];
        }
        return {itery - dry[dr] , iterx - drx[dr]};
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends
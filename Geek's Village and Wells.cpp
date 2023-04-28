//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        int r=c.size();
        int co=c[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>res(r,vector<int>(co,INT_MAX));
        vector<vector<int>>v(r,vector<int>(co,-1));
        for(int i=0 ; i<r ; i++){
            for(int j=0 ; j<co ; j++){
                if(c[i][j]=='W'){
                    v[i][j]=0;
                    res[i][j]=0;
                    q.push({i,j});
                }
                else if(c[i][j]=='N'){
                    res[i][j]=0;//giving -1 for rest. area , later we will put 0 in res matrix;
                }
            }
        }
        while(q.size()!=0){
            // check for 2 things boundary condition and greatness;
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(j-1>=0 && v[i][j-1]==-1 && res[i][j-1]>res[i][j]){
                v[i][j-1]=0;
                res[i][j-1]=res[i][j]+1*2;
                q.push({i,j-1});
            }
            
            if(j+1<co && v[i][j+1]==-1 && res[i][j+1]>res[i][j]){
                v[i][j+1]=0;
                res[i][j+1]=res[i][j]+1*2;
                q.push({i,j+1});
            }
            if(i-1>=0 && v[i-1][j]==-1 && res[i-1][j]>res[i][j]){
                v[i-1][j]=0;
                res[i-1][j]=res[i][j]+1*2;
                q.push({i-1,j});
            }
            if(i+1<r && v[i+1][j]==-1 && res[i+1][j]>res[i][j]){
                v[i+1][j]=0;
                res[i+1][j]=res[i][j]+1*2;
                q.push({i+1,j});
            }
        }
        for(int i=0 ; i<r ; i++){
            for(int j=0 ; j<co ; j++){
                if(c[i][j]=='.'){
                    res[i][j]=0;
                }
                else if(res[i][j]==INT_MAX){
                    res[i][j]=-1;
                }
            }
        }
        return res;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		 vector<int>ans;
   
   int rowStart =0;
   int rowEnd = n-1;
   
   int colStart = 0;
   int colEnd = m-1;
   
   while(rowStart <= rowEnd && colStart<=colEnd){
       
       //left to right
       for(int i=colStart; i<=colEnd; i++){
           ans.push_back(a[rowStart][i]);
       }
       rowStart++;
       
       //top to bottom
       for(int i=rowStart; i<=rowEnd; i++){
           ans.push_back(a[i][colEnd]);
       }
       colEnd--;
       
       if(rowStart<=rowEnd){
           for(int i=colEnd; i>=colStart; i--){
               ans.push_back(a[rowEnd][i]);
           }
           rowEnd--;
       }
       
       if(colStart <= colEnd){
           for(int i=rowEnd; i>=rowStart; i--){
               ans.push_back(a[i][colStart]);
           }
           colStart++;
       }
   }
   
   return ans[k-1];
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends
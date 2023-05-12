//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        int cnt=0;
        bool f=0;
        for(int i = 0 ; i < arr.size() ; ){
            if(arr[i]==0){
                f=1;
                while(i<n && arr[i]==0){
                    i++;
                }
            }
            else{
                while(i<n && arr[i]!=0){
                    i++;
                }
                cnt++;
            }
        }
        return f==1? cnt:-1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
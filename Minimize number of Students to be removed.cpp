//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    
  private:
    int binary_search(vector<int>arr,int target){
        int l,h,m,ans;
        l=0;
        h=arr.size()-1;
        ans=-1;
        
        while(l<=h){
            m=l+((h-l)>>1);
            if( arr[m] >= target ){
                ans=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        
        if(ans==-1){
            return 0;
        }
        
        return ans;
        
    }
  public:
    int removeStudents(int H[], int N) {
        // code here
        vector<int>arr;
        
        arr.push_back(H[0]);
        
        for(int i=0;i<N;i++){
            if(H[i]>arr.back()){
                arr.push_back(H[i]);
            }
            else{
                int index=binary_search(arr,H[i]);
                arr[index]=H[i];
            }
        }
        return N-arr.size();
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends
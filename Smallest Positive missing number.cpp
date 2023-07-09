//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        for(int i=0; i<n; i++)
        {
            // cout<<i<<endl;
            while(arr[i]>=1 && arr[i]<=n && arr[i]!=arr[arr[i]-1])
            {
                swap(arr[arr[i]-1],arr[i]);
                // i--;
            }
        }
        // for(auto it: arr) cout<<it<<endl;
        // for(int i=0; i<n; i++)
        // cout<<arr[i]<<" ";
        // cout<<endl;
        for(int i=0; i<n; i++)
        {
            if(arr[i]!=i+1) return i+1;
        }
        return n+1;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends
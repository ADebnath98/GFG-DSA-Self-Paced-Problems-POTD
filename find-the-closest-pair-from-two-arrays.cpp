//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        int left = 0;
        int right = m-1;
        int ans = INT_MAX;
        int ans1,ans2;
        while(right >= 0 && left<n){
            int sum = arr[left] + brr[right];
            if(abs(sum-x) < ans){
                ans = abs(sum-x);
                ans1 = arr[left];
                ans2 = brr[right];
            }
            if(sum > x){
                right--;
            }
            else {
                left++;
            }
        }
        return {ans1,ans2};
    
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends


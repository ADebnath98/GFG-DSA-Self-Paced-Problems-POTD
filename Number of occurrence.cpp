//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int l=0, r=n-1;
	    int cnt=0;
	    int i;
	    if(x<arr[l]) return 0;
	    if(x>arr[r]) return 0;
	    while(l<r)
	    {
	        if(arr[l]==x) {i=l;cnt++;break;}
	        if(arr[r]==x) {i=r;cnt++;break;}
	        int mid = (l+r)/2;
	        if(arr[mid]==x) {i=mid;cnt++;break;}
	        else if(arr[mid]>x) r--;
	        else l++;
	    }
	    //left and right pointers of the ith index x
	    l=i-1, r=i+1;
	    int flag=0;
	    while(l>0 || r<n)
	    {
	        if(l>0 && arr[l]==x) {cnt++;l--;flag=1;}
	        if(r<n && arr[r]==x) {cnt++;r++;flag=1;}
	        if(flag==0) break;
	        flag=0;
	    }
	    return cnt;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
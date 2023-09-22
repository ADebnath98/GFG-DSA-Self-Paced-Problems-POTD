//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int> ans(2);
        int i = 0;
        while(i<n and arr[i] != x){ i++;}
        if(i == n) return {-1,-1};
        ans[0] = i;
        int num = -1;
        
        while(i<n)
        {
            if(arr[i] == x) num = i;
            i++;
        }
        
        ans[1] = num;
        
        return ans;
        
        /*vector<int> ans(2,-1);
        int i=0,j=n-1;
        
        while(i<=j)
        {
            int mid = i+(j-i)/2;
            if(arr[mid]==x)
            {
                if(ans[0]==-1) ans[0] = mid;
                else if(ans[0] > mid) ans[0] = mid;
                else if(ans[1] < mid) ans[1] = mid;
                if(arr[i]==x || arr[j]==x)
                {
                    if(arr[i]==x and ans[0] > i) ans[0] = i;
                    if(arr[j]==x and ans[1] < j) ans[1] = j;
                }
                i++;
                j--;
            }
            else if(arr[mid]>x) j=mid-1;
            else if(arr[mid]<x) i=mid+1;
        }
        return ans;*/
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
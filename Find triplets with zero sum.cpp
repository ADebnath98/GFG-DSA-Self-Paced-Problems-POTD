//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
           int i = 0,  j = 1 , k = n-1;
        sort(arr , arr+n); //sort
        while(i < k)
        {    int sum = arr[i] + arr[j] + arr[k];
             if(sum == 0) return true;
             else if(sum > 0) k--;
             else j++;
             if(j>=k)
             {
                 i++;
                 j = i+1;
                 if(j == k)
                      return false;
                 k = n-1;
             }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends
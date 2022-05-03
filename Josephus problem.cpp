// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    
    int jos(int n, int k)
    {
       //Your code here
    if(n==1)
        return 0;
    else    
        return (jos(n-1, k)+k)%n;
    }
    int josephus(int n,int k)
    {
        return jos(n,k)+1;
    }
};



// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    long long gcd(long long int a, long long int b)
    {
        if(b == 0)
        return a;
        return gcd(b, a%b);
        
    }
    
    long long getSmallestDivNum(long long n)
    {
        long res = 1;
        for(long i = 2; i <= n; i++)
        {
            res = (res*i)/gcd(res, i);
        }
        return res;
    }

};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<< ob.getSmallestDivNum(n)<<endl;
    }
    return 0;
}
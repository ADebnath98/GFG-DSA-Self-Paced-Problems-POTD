//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[]) {
        unordered_map<int, unordered_map<int, int>> freq;
        int res = 0;
        for(int i = 0; i < n; i++) {
            int num = numerator[i], den = denominator[i];
            int gcd = __gcd(num, den);
            num /= gcd, den /= gcd;
            
            int resNum = den - num;
            int resDen = den;
            
            res += freq[resNum][resDen];
            freq[num][den]++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

 // } Driver Code Ends
class Solution{
    public:
    //You need to complete this fucntion
    const long long m = 1e9+7;
    long long count(int n, int r){
        long ans = 1;
       while(r>0){
           if(r&1){
               ans = (ans*n%m)%m;
        }
        n = (n%m*n%m)%m;
        r >>= 1;
       }
       return ans;
    }
    long long power(int N,int R)
    {
       //Your code here
       return count(N,R);
       
        
    }

};

// { Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}  // } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int countbits(long long int n){
      if(n<=0)
      return 0;
      if(n==1)
      return 1;
     long long int x=n;
    long long int i=0;
while(pow(2,i)<=x){
        i++;
        
    }
    i-=1;
    return(pow(2,i-1)*i)+(n-pow(2,i)+1)+countbits(n-pow(2,i));
  }
    long long countBits(long long N) {
        long long ans=countbits(N);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
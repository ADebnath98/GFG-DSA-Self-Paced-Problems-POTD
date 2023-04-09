//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long 
const  int m=1e9+7;
class Solution {
  public:
    ll inverse(ll a,ll b,ll m){
        ll ans=1;
        while(b){
            if(b&1) ans=(ans*1LL*a)%m;
            a=(a*1LL*a)%m;
            b=b/2;
        }
        return ans%m;
    }
    int bestNumbers(int n, int a, int b, int c, int d) {
        ll v[n+1]={1};
        ll sum=0;
        for(int i=1;i<=n;i++){
            v[i]=(v[i-1]*1LL*i)%m;
        }
        for(int i=0;i<=n;i++){
            int  s1=i*a+(n-i)*b;
            bool check=1;
            while(s1){
                if(s1%10!=c&& s1%10!=d){
                    check=0;
                    break;
                }
                s1=s1/10;
            }
            if(check){
                ll r=(v[n]*1LL*inverse((v[i]),m-2,m))%m;
                r=(r*1LL*inverse(v[n-i],m-2,m))%m;
                sum=(sum+r)%m;
            }
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int A;
        scanf("%d",&A);
        
        
        int B;
        scanf("%d",&B);
        
        
        int C;
        scanf("%d",&C);
        
        
        int D;
        scanf("%d",&D);
        
        Solution obj;
        int res = obj.bestNumbers(N, A, B, C, D);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
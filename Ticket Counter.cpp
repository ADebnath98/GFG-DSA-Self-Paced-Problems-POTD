//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        deque<int> dq;
        for(int i=1;i<=N;i++) dq.push_back(i);
        bool flag=true;
        int ans=-1;
        while(!dq.empty()){
            if(flag==true){
                int i=K;
                while(!dq.empty() && i--){
                    ans=dq.front();
                    dq.pop_front();
                }
                if(dq.empty()){
                    return ans;
                }
                flag=false;
                
                
            }
            else if(flag==false){
                int i=K;
                while(!dq.empty() && i--){
                    ans=dq.back();
                    dq.pop_back();
                }
                if(dq.empty()){
                    return ans;
                }
                flag=true;
            }
            
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
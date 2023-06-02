C++ Solution DFS Seive of sieve of eratosthenes

Approach:

Step1: Take a vector<int>vis(n+1,0)-> represents whether the node is visited of not (0 for not visited and 1 for visited)

Step2: Take an integer maxi which represents the maximum size of group

Step3: Iterate over each non visited node wiht an integer teamsize and run a dfs function on it which traverse through the childs of each node and get the size of group.

Step4: In each iteration of nodes take the maximum value of teamsize (maxi=max(maxi,teamsize))

Step5: If maxi==1 then we have to return the value -1 (as per question). Else return the (maxi-1)th prime number which we got from above sieve of eratosthenes method.


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    vector<int>prime;
    void precompute(){
        // seive is done here...
        vector<bool>isprime(1e6+1,true);
        isprime[0]=false;
        isprime[1]=false;
        for(int i=2;i<1e6+1;i++)
        {
            if(isprime[i]==true)
            {
                prime.push_back(i);
                int j=2*i;
                while(j<1e6+1)
                {
                    isprime[j]=false;
                    j=j+i;
                }
            }
        }
    }
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,int &teamsize){
        teamsize++; // value of teamsize is increased...
        vis[node]=1;
        for(auto child:adj[node]){
            if(vis[child]==0){
                dfs(child,adj,vis,teamsize);
            }
        }
    }
    int helpSanta(int n,int m,vector<vector<int>>&g){
        vector<int>vis(n+1,0);
        int maxi=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                int teamsize=0; //initializing the teamsize variable...
                dfs(i,g,vis,teamsize); //dfs function to traverse through each connected nodes....
                maxi=max(maxi,teamsize); //maximizing the team size...
            }
        }
        if(maxi==1){
            return -1;
        }
        return prime[maxi-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends
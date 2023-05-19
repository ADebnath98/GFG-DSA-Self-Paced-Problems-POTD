//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        sort(range.begin(),range.end());
        int ind=0;
        // merge intervals
        for(int i=1;i<n;i++){
            if(range[ind][1]>= range[i][0]){
                range[ind][1]= max(range[ind][1],range[i][1]);
            }
            else{
                ind++;
                range[ind]=range[i];
            }
        }
        vector<int> ans(q,-1);
        for(int i=0;i<q;i++){
            int x=queries[i];
            for(int j=0;j<=ind;j++){
                if(range[j][1]-range[j][0]+1>=x){
                    ans[i]= range[j][0]+ x -1;
                    break;
                }
                x-= range[j][1]-range[j][0]+1;
            }
        }
        return ans;
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
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends
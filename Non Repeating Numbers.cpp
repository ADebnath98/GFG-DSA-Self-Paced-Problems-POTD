//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        vector<int> ans ;
        int i=0;

      //sort the vector
        sort(nums.begin(),nums.end());

        int n = nums.size();
        while(i<n-1){
            if(nums[i]==nums[i+1])
            {
                i = i+2;
            }
            else{
                ans.push_back(nums[i]);
              
                i=i+1;
            }
        
        }
       //to handle last case , if unique elment comes in last.
        if(ans.size()==1)
        ans.push_back(nums[n-1]);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
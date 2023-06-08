//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void fxn(int n, int x, vector<int>& nums, vector<int>& ans, int k){
        if(nums.size() == 1) return;
        int digit_1 = k /x;
        if(k%x > 0) digit_1 ++;
        ans.push_back(nums[digit_1 - 1]);
        auto it = find(nums.begin(), nums.end(), nums[digit_1 - 1]);
        nums.erase(it);
        fxn(n-1, x/(n-1), nums, ans, (k-1)%x + 1);
        return;
    }
    string kthPermutation(int n, int k)
    {
        // calculate the factorial n
        long long fact = 1;
        for(int i = 1; i <= n; i++){
            fact*= i;
        }
        // here x = fact/n;
        vector<int>nums(n);
        for(int i = 0; i < n; i++){
            nums[i] = i+1;
        }
        
        vector<int>ans;
        
        fxn(n, fact/n, nums, ans, k);
        ans.push_back(nums[0]);
        
        // the whole thing we have to do now is to create a string with the respective values.
        string s = "";
	   // int arr[]= { 1, 3, 4, 5,4,2,2};
	    for(auto it : ans){
	    	s+= to_string(it);

	}
       return s;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
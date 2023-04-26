//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& v){
        // Write your code here.
        int a = 0,b = 0;
        for(int i = 0;i<m;i++)
        {
            int curr_a = a,curr_b = b;
            if(v[i]==0)
            {
                if(i && v[i-1]==0)
                {
                    curr_a = b + 1;
                    curr_b = max(a,b);
                }else if(i && v[i-1]==1){
                    curr_a = a;
                    curr_b = b;
                }else{
                    curr_a = max(a,b) + 1;
                    curr_b = max(a,b);
                }
            }else{
                if(i && v[i-1]==0)
                {
                    curr_a = a - 1;
                    curr_b = b;
                }
            }
            a = curr_a,b= curr_b;
        }
        return (a>=n || b>=n);
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends
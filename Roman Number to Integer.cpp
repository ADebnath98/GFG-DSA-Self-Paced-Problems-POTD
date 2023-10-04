//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        vector<pair<char, int>>v= 
        {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int sum=0;
        int prevValue=0;
        for (int i=str.size()-1;i>=0;i--) 
        {
            int currentValue=0;

            for (auto pair:v) 
            {
                if (pair.first==str[i]) 
                {
                    currentValue=pair.second;
                    break;
                }
            }

            if (currentValue<prevValue) 
            {
                sum-=currentValue;
            } 
            else 
            {
                sum+=currentValue;
            }
            prevValue=currentValue;
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends
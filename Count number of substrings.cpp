//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long substrAtMostK(string s,int k){
        int n = s.size();
        int i = 0;
        int j = 0;
        vector<int> hash(26,0);
        int cnt = 0;
        int res = 0;
        while(j<n){
           hash[s[j]-'a']++;
           if(hash[s[j]-'a']==1){//first time entered in hash so one distinct character enters
               cnt++;
           }
           if(cnt>k){
               while(cnt>k){
                   hash[s[i]-'a']--;
                   if(hash[s[i]-'a']==0){
                       cnt--;
                   }
                   i++;
               }
           }
           res+=(j-i+1);
           j++;
        }
        return res;
    }
    long long int substrCount (string s, int k) {
    	//code here.
    	return substrAtMostK(s,k) - substrAtMostK(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends
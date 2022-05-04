// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    vector<string>keypad{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void generate(int a[], int i, int n, string out, vector<string>&v)
    {
        if(i == n)
        {
            v.push_back(out);
            return;
        }
        int digit = a[i];
        for(int k = 0; keypad[digit][k]!= '\0'; k++)
        {
            generate(a, i+1, n, out+keypad[digit][k], v);
        }
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string>v;
        generate(a,0,N,"",v);
        return v;
    }
};




// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends
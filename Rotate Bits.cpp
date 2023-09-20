//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            //code here.
            // Convert the integer N to its binary representation with 16 bits
            bitset<16> binaryN(n);
            


            // Adjust d to be within the range [0, 15]
            d %= 16;
            if(d < 0){
                d += 16;
            }
            


            // Rotate the binary representation to the left by D positions
            bitset<16> rotatedLeft = (binaryN << d) | (binaryN >> (16 - d));
            


            // Rotate the binary representation to the right by D positions
            bitset<16> rotatedRight = (binaryN >> d) | (binaryN << (16 - d));
            


            // Convert the rotated binary representations back to decimal
            int LeftDecimal = rotatedLeft.to_ulong();
            int RightDecimal = rotatedRight.to_ulong();
            


            return {LeftDecimal, RightDecimal};
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
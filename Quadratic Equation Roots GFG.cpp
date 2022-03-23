#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) {
        double x1,x2;
        double D = sqrt(b*b - 4*a*c);
        
        if(D>=0)
        {
            x1 = (-b+D)/(2.0*a);
            x2 = (-b-D)/(2.0*a);
            return {floor(max(x1,x2)), floor(min(x1,x2))};
    }
    else
    return {-1};
    }
};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        Solution ob;
        vector<int> roots = ob.quadraticRoots(a, b, c);
        if (roots.size() == 1 && roots[0] == -1)
            cout << "Imaginary";
        else
            for (int i = 0; i < roots.size(); i++) cout << roots[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
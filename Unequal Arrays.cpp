//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends


class Solution {
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
        long long sumA = 0 , sumB = 0;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        vector<int> oddB,oddA,evenA,evenB;
        for(int i=0;i<N;i++)
        {
            sumA += A[i];
            sumB += B[i];
            if(A[i] & 1)
            oddA.push_back(A[i]);
            else
            evenA.push_back(A[i]);
            if(B[i] & 1)
            oddB.push_back(B[i]);
            else
            evenB.push_back(B[i]);
        }
        if(sumA != sumB || oddA.size() != oddB.size() || evenA.size() != evenB.size())
        return -1;
        long long ans = 0;
        for(int i=0;i<oddA.size();i++)
        {
           ans += abs(oddA[i] - oddB[i]);
        }
        for(int i =0; i<evenA.size();i++)
        {
           ans += abs(evenA[i] - evenB[i]);
        }
        
        ans = ans/4;
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
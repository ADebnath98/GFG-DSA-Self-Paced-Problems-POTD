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
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        unordered_set<int>s;
        
        vector<int>left;
        vector<int>right;
        
        left.push_back(0);//for first element on left there will always be 0 elements ie 0 distinct elements
        
        
        for(int i=0;i<N;i++)
        {
            int num= A[i];
            
            s.insert(num);
            left.push_back(s.size());
            
            
         }
         left.pop_back();
         
         s.clear();
         
         right.push_back(0);
         //for rightmost element there will always be 0 distinct element
         
         
         for(int i=N-1;i>=0;i--)
         {
             int num = A[i];
             
             s.insert(num);
             right.push_back(s.size());
             
         }
        
    right.pop_back();
    reverse(right.begin(),right.end());
    
    vector<int>v;
    
    for(int i=0;i<N;i++)
    {
        int res= left[i]-right[i];
        v.push_back(res);
        
        
    }
        return v;
        
        
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
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends
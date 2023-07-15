//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    int  recu(stack<int>&s,int x)
      {
             if(s.size()==0)
                return 0;
                int y=s.top();
                 s.pop();
                int r=1+recu(s, x);
                if(r!=x)
                {
                    s.push(y);
                }
                return r;
      }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
         int x=ceil((sizeOfStack+1)/2);
         int y=sizeOfStack;
        int x1= recu(s,x);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends
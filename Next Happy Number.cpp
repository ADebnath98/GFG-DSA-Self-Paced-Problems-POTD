APPROACH :

We need to find the smallest next number greater than n that is a happy number.
However, It's not a kind of question in which we can apply binary search and return the answer, We have to check all values greater than n until we find a happy number. It is confirmed that there exists a happy number greater than n, just as there always exists a prime number greater than n (just for the sake of example :))
Now, let's define some base cases to return the answer, otherwise, the loop will never end.
We can take all values less than 10 as base values.
 

Now, let's have a look on the image below to understand the base cases easily.



 

It is clear from the image that for the values 2, 3, 4, 5, 6, 8, and 9, the loop will never end, as they repeat the same cycle again and again. Thus, we return false for these values, indicating that the current number is not a happy number.
It is also clear that if we reach 1 or 7, it means that the current number is a happy number.                                       '




//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool solve(int n){
        if(n==1 || n==7)return true;
        if(n==2 || n==4 || n==8 || n==3 || n==9 || n==5 || n==6)return false;
        int sq_sum=0;
        while(n){
            int x=n%10;
            sq_sum+=(x*x);
            n/=10;
        }
        return solve(sq_sum);
    }
    int nextHappy(int n){
        while(true){
            n++;
            if(solve(n))return n;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    bool isPrime(int n){
        if (n == 1)
            return false;
        
        if (n == 2 || n == 3)
            return true;
        
        if (n % 2 == 0 || n % 3 == 0)
            return false;
    
        for (int i = 5; i <= sqrt(n); i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    
    int prime(int n){
        
        if(isPrime(n))
            return n;
        
        if (n == 1)
            return 2;
        
        int high_prime = INT_MAX;
        int low_prime = 0;
        
        for(int i=n-1; i>1; i--){
            if(isPrime(i)){
                low_prime = i;
                break;
            }
        }
        
        for(int i=n+1; i<=n*n; i++){
            if(isPrime(i)){
                high_prime = i;
                break;
            }
        }
        
        int l_p = n-low_prime;
        int h_p = high_prime-n;
        
        if(l_p>h_p || low_prime<=1)
            return high_prime;
        return low_prime;
    }
    
    Node *primeList(Node *head){
        Node* temp = head;
        while(temp!=NULL){
            temp->val = prime(temp->val);
            temp = temp->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/

// } Driver Code Ends
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
class Solution{
public:
    int size(Node*head)
{
    int n=0;
    while(head != NULL)
    {
        n++;
        head=head->next;
        
    }
    return n;
}

int getNthFromLast(Node *head, int k)
{
       int n=size(head);
       k=n-k+1;
       if(k<0) return -1;
       int j=1;
       Node*temp=head;
       int ans;
       
       while(temp)
       {
           
           if(j==k) 
           {
              ans=temp->data;
              return ans;
           }
           j++;
           temp=temp->next;
           
           
       }
       
       return -1;
       
}
};



//{ Driver Code Starts.

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
    cout<<obj.getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
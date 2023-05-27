//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    struct Node* reverse(struct Node * list)
    {
        struct Node *curr=list;
        struct Node *prev=NULL;
        struct Node *forward=NULL;
        while(curr!=NULL)
        {
            forward=curr->next;
           curr->next=prev;
           prev=curr;
           curr=forward;
        }
        return prev;
    }
    struct Node* modifyTheList(struct Node *head)
    {
        if(head==NULL || head->next==NULL) return head;
       struct Node * temp=head;
       int c=0;
       while(temp!=NULL)
       {
           c++;
           temp=temp->next;
       }
       int n=(c)/2;
       
       struct Node* x=head;
       struct Node *y=NULL;
       while(n>0)
       {
           n--;
           y=x;
           x=x->next;
       }
       y->next=NULL;
      struct Node* i=reverse(x);
      struct Node* m=i;
      struct Node* j=head;
      
      while(j!=NULL)
      {
        
         i->data=i->data-j->data; 
         i=i->next;
         
         j=j->next;
      }
      struct Node* k=reverse(head);
     struct Node* l=m;
     while(l->next!=NULL)
     {
         l=l->next;
     }
      l->next=k;
      return m;
       
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends
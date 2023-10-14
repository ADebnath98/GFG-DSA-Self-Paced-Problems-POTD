//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    void V1(Node *root1, vector<int> &B1){
        if(root1 == NULL) return;
        V1(root1->left,B1);
        B1.push_back(root1->data);
        V1(root1->right,B1);
    }
    void V2(Node *root2, vector<int> &B2){
        if(root2 == NULL) return;
        V2(root2->left,B2);
        B2.push_back(root2->data);
        V2(root2->right,B2);
    }
    
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     vector<int>B1;
     vector<int>B2;
     vector<int> ans;
     V1(root1,B1);
     V2(root2,B2);
     unordered_map<int,int> map;
     for(int i=0;i<B1.size();i++){
         map[B1[i]]++;
     }
     int i=0;
     while(i<B2.size()){
        // for(auto x:map){
            if(map.find(B2[i])!=map.end())
               ans.push_back(B2[i]);
        // }
        i++;
     }
     return ans;
    }
};




//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root1 = buildTree(s);

        getline(cin,s);
        Node* root2 = buildTree(s);
        Solution ob;
        vector <int> res = ob.findCommon(root1, root2);
        for (int i : res)
            cout << i << " ";
        cout<< endl;
    }

	return 1;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
    int  n = 1e9;
public:
    int mnn(Node *root){
        while(root->left) root = root->left;
        return root->data;
    }
    int mxx(Node *root){
        while(root->right) root = root->right;
        return root->data;
    }
    vector<int> traverse(Node *root, int target){
        if(root == NULL) return {0,0,1};
        
        auto p = traverse(root->left, target);
        auto q = traverse(root->right, target);
        vector<int> r(3,0);
        
        if(p[2] and q[2]){
            if(p[0]==0 and q[0]==0){
                r[0] = 1;
                r[1] = root->data;
                r[2] = 1;
            }
            else if(p[0]!=0 and q[0]==0){
                r[0] = p[0]+1;
                r[1] = p[1]+root->data;
                if(mxx(root->left) < root->data) r[2] = 1;
            }
            else if(p[0]==0 and q[0]!=0){
                r[0] = q[0]+1;
                r[1] = q[1]+root->data;
                if(mnn(root->right) > root->data) r[2] = 1;
            }
            else if(p[0]!=0 and q[0]!=0){
                r[0] = p[0]+q[0]+1;
                r[1] = p[1]+q[1]+root->data;
                if(mxx(root->left) < root->data and mnn(root->right) > root->data) r[2] = 1;
            }
            if(r[0]<n and r[1]==target and r[2]) n=r[0];
        }
        
        return r;
    }
    int minSubtreeSumBST(int target, Node *root) {
        traverse(root, target);
        
        if(n == 1e9) return -1;
        return n;
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends
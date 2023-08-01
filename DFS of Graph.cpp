//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph
    void performDFS(int currentNode, vector<int> adjacencyList[], vector<int>& dfsTraversal, vector<int>& visited) {
    // Mark the current node as visited
    visited[currentNode] = 1;

    // Add the current node to the DFS traversal result
    dfsTraversal.push_back(currentNode);

    // Traverse all the adjacent nodes of the current node
    for (int adjacentNode : adjacencyList[currentNode]) {
        // If the adjacent node is not visited yet, perform DFS on it
        if (!visited[adjacentNode]) {
            performDFS(adjacentNode, adjacencyList, dfsTraversal, visited);
        }
    }
}

//Here is the Function to return the DFS traversal of the graph starting from the 0th vertex    

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
    vector<int> dfsTraversal;
    vector<int> visited(V, 0); // Array to keep track of visited nodes, initialized to 0 (not visited)

    // Start the DFS traversal from vertex 0
    performDFS(0, adj, dfsTraversal, visited);

    return dfsTraversal;
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
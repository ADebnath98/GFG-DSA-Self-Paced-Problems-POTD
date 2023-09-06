//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    // Function to perform Depth First Search (DFS) starting from vertex v.
    void DFS(vector<int> adj[], vector<bool>& visited, int v)
    {
        visited[v] = true;

        for(int adjVertex : adj[v])
        {
            if(!visited[adjVertex])
                DFS(adj, visited, adjVertex);
        }
    }

    // Function to find a Mother Vertex in the Graph.
    int findMotherVertex(int V, vector<int>adj[])
    {
        vector<bool> visited(V, false);
        int lastVisited = 0;

        // Perform DFS for each vertex to find the last visited vertex.
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                DFS(adj, visited, i);
                lastVisited = i;
            }
        }

        // Reset visited array and perform DFS again from the last visited vertex.
        fill(visited.begin(), visited.end(), false);
        DFS(adj, visited, lastVisited);

        // Check if the last visited vertex is a mother vertex.
        for(bool v : visited)
        {
            if(!v)
                return -1; // No mother vertex found.
        }

        return lastVisited;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
#include <iostream>
#include <vector>
using namespace std;

class DeliveryGraph {
private:
    int n;                        // number of locations
    vector<vector<int>> adj;      // adjacency list

public:
    DeliveryGraph(int nodes) {
        n = nodes;
        adj.resize(n);
    }

    // Add delivery connection (edge)
    void addRoute(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);      // undirected route
    }

    // DFS function
    void dfs(int start, vector<bool>& visited) {
        visited[start] = true;
        cout << start << " ";

        for(int next : adj[start])
            if(!visited[next])
                dfs(next, visited);
    }

    // Show full delivery route from starting restaurant
    void showRoutes(int start) {
        vector<bool> visited(n, false);
        cout << "\nDelivery Route from " << start << ":\n";
        dfs(start, visited);
    }
};

int main() {
    int nodes, edges, u, v, start;

    cout << "Enter number of locations (nodes): ";
    cin >> nodes;

    DeliveryGraph g(nodes);

    cout << "Enter number of delivery connections (edges): ";
    cin >> edges;

    cout << "\nEnter connected locations (u v):\n";
    for(int i = 0; i < edges; i++) {
        cin >> u >> v;
        g.addRoute(u, v);
    }

    cout << "\nEnter starting restaurant for delivery: ";
    cin >> start;

    g.showRoutes(start);

    return 0;
}

// 📌 Algorithm
// Start
// Input number of locations (nodes)
// Create a graph using an adjacency list
// Input number of delivery connections (edges)
// For each edge:
// Read u and v
// Insert v into adjacency list of u
// Insert u into adjacency list of v (undirected graph)
// Input starting restaurant/location
// Initialize a visited[] array of size n, all values = false
// Call DFS(start):
// Mark current node as visited
// Print the node (delivery reached here)
// For each neighbor of current node:
// If not visited → recursively call DFS(neighbor)
// Stop when all reachable locations are visited
// End

// 🧾 Pseudo Code

// START

// INPUT nodes
// CREATE adjacency list adj[n]

// INPUT edges
// FOR i = 1 TO edges:
//     INPUT u, v
//     adj[u].append(v)
//     adj[v].append(u)

// FUNCTION DFS(start, visited[]):
//     visited[start] = TRUE
//     PRINT start
    
//     FOR each location next in adj[start]:
//         IF visited[next] == FALSE THEN
//             CALL DFS(next, visited)

// FUNCTION showRoutes(start):
//     INITIALIZE visited[n] = {FALSE}
//     PRINT "Delivery Route from start:"
//     CALL DFS(start, visited)

// MAIN:
//     INPUT start
//     CALL showRoutes(start)

// END


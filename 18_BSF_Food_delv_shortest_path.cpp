#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, e;
    cout << "Enter number of locations: ";
    cin >> n;

    vector<vector<int>> graph(n);   // adjacency list
    cout << "Enter number of routes: ";
    cin >> e;

    cout << "Enter connected paths (u v):\n";
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);      // undirected
    }

    int start, dest;
    cout << "Enter starting point: ";
    cin >> start;
    cout << "Enter destination: ";
    cin >> dest;

    // -------- BFS to find shortest path --------
    vector<bool> visited(n,false);
    vector<int> parent(n,-1);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(cur == dest) break;   // stop when reached

        for(int next : graph[cur]) {
            if(!visited[next]) {
                visited[next] = true;
                parent[next] = cur;
                q.push(next);
            }
        }
    }

    // -------- Print path --------
    if(!visited[dest]) {
        cout << "No route found!";
        return 0;
    }

    cout << "\nShortest Path: ";
    int x = dest;
    vector<int> path;
    while(x != -1) {
        path.push_back(x);
        x = parent[x];
    }

    for(int i = path.size()-1; i >= 0; i--)
        cout << path[i] << (i?" -> ":"");

    cout << "\nTotal steps: " << path.size()-1;
}


// ✅ Algorithm (Step-by-Step)
// Start.
// Input number of locations (nodes) n.
// Create an adjacency list graph[n].
// Input number of routes (edges) e.
// For each route (u, v):
// Add v to adjacency list of u.
// Add u to adjacency list of v (because the graph is undirected).
// Input start location and dest location.
// Initialize:
// visited[n] = false for all nodes
// parent[n] = -1 for all nodes
// Queue q
// Mark start as visited and push it to queue.
// While queue is not empty:
// Remove front element cur
// If cur == dest, stop BFS
// For each neighbor next of cur:
// If next is not visited:
// Mark visited
// Set parent[next] = cur
// Push next into the queue
// If dest was never visited → print "No route found" and stop.
// Otherwise, backtrack from dest using parent[] to reconstruct the path.
// Print the path and total steps.
// End.

// 📌 Pseudocode

// START

// INPUT n
// CREATE adjacency list graph of size n

// INPUT e
// FOR i = 1 to e
//     INPUT u, v
//     graph[u].append(v)
//     graph[v].append(u)
// END FOR

// INPUT start
// INPUT dest

// CREATE visited[n] initialized to false
// CREATE parent[n] initialized to -1
// CREATE empty queue q

// visited[start] = true
// ENQUEUE start to q

// WHILE q is not empty
//     cur = DEQUEUE q
//     IF cur == dest
//         BREAK
//     END IF

//     FOR each neighbor next in graph[cur]
//         IF visited[next] == false
//             visited[next] = true
//             parent[next] = cur
//             ENQUEUE next
//         END IF
//     END FOR
// END WHILE

// IF visited[dest] == false
//     PRINT "No route found"
//     STOP
// END IF

// // Reconstruct shortest path
// INITIALIZE empty list path
// SET x = dest
// WHILE x != -1
//     ADD x to path
//     x = parent[x]
// END WHILE

// PRINT "Shortest Path: " in reverse order of path
// PRINT "Total steps = size(path) - 1"

// END


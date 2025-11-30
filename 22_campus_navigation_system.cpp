#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
    int n = 5; // number of buildings
    vector<string> names = {"Library", "Canteen", "Lab", "Admin", "Hostel"};

    // Adjacency list (undirected graph)
    vector<vector<int>> adj(n);
    adj[0].push_back(2); adj[2].push_back(0); // Library - Lab
    adj[2].push_back(4); adj[4].push_back(2); // Lab - Hostel
    adj[1].push_back(0); adj[0].push_back(1); // Canteen - Library
    adj[3].push_back(4); adj[4].push_back(3); // Admin - Hostel

    int start = 1; // Canteen
    int end = 4;   // Hostel

    // BFS variables
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int cur = q.front(); q.pop();

        if(cur == end) break;

        for(int next : adj[cur]) {
            if(!visited[next]) {
                visited[next] = true;
                parent[next] = cur;
                q.push(next);
            }
        }
    }

    // Reconstruct path
    if(!visited[end]) {
        cout << "No path found!\n";
        return 0;
    }

    vector<int> path;
    int x = end;
    while(x != -1) {
        path.push_back(x);
        x = parent[x];
    }

    cout << "Shortest path from " << names[start] << " to " << names[end] << ":\n";
    for(int i = path.size()-1; i >= 0; i--) {
        cout << names[path[i]];
        if(i != 0) cout << " -> ";
    }
    cout << endl;
}



// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// int main(){
//     vector<vector<int>> g(5); // 5 buildings

//     // Connections given
//     g[0]={2};        // Library–Lab
//     g[2]={0,4};      // Lab–Hostel
//     g[1]={0};        // Canteen–Library
//     g[3]={4};        // Admin–Hostel
//     g[4]={2,3};

//     int start=1, end=4; // Canteen → Hostel
//     vector<int> parent(5,-1);
//     vector<bool> vis(5,false);

//     queue<int> q;
//     q.push(start); vis[start]=true;

//     while(!q.empty()){
//         int cur=q.front(); q.pop();
//         if(cur==end) break;
//         for(int next:g[cur])
//             if(!vis[next]){ vis[next]=true; parent[next]=cur; q.push(next); }
//     }

//     cout<<"\nShortest Path Canteen → Hostel:\n";
//     int x=end;
//     vector<int> path;
//     while(x!=-1){ path.push_back(x); x=parent[x]; }

//     for(int i=path.size()-1;i>=0;i--){
//         cout<<path[i];
//         if(i) cout<<" -> ";
//     }
// }


// 🔷 Algorithm (BFS Shortest Path Between Two Buildings)
// Start
// Store building connections in an adjacency list
// Take start and end building indexes
// Create:
// visited[] array initialized to false
// parent[] array initialized to –1
// Empty queue q
// Mark start as visited and push it into queue
// While queue is not empty:
// Pop cur from queue
// If cur == end, stop BFS
// For every neighbor next of cur:
// If next not visited:
// Mark visited
// Set parent[next] = cur
// Push next in queue
// If end is not visited → no path exists
// Else, reconstruct path by moving backward using parent[] from end to start
// Print path in forward order
// Stop

// 🔷 Pseudocode
// INPUT number of buildings n
// STORE building names
// CREATE adjacency list graph with n nodes

// SET start = index of starting building
// SET end = index of destination building

// INITIALIZE visited[n] = false
// INITIALIZE parent[n] = -1
// CREATE empty queue q

// visited[start] = true
// q.enqueue(start)

// WHILE q is not empty
//     cur = q.dequeue()

//     IF cur == end
//         BREAK

//     FOR each neighbor next in graph[cur]
//         IF visited[next] == false
//             visited[next] = true
//             parent[next] = cur
//             q.enqueue(next)
// END WHILE

// IF visited[end] == false
//     PRINT "No path found"
//     EXIT

// CREATE empty list path
// x = end
// WHILE x != -1
//     ADD x to path
//     x = parent[x]

// PRINT "Shortest Path:"
// FOR i = path.last_index → 0
//     PRINT building_name[path[i]]
//     IF i != 0 PRINT " -> "

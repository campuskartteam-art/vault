#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, vector<vector<int>>& graph, int n) {
    vector<int> level(n+1, -1);      // distance from starting node
    queue<int> q;

    q.push(start);
    level[start] = 0;                // starting user distance = 0

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(int v : graph[u]) {      // check all connected friends
            if(level[v] == -1) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }

    cout << "\nFriend suggestions for user " << start << ":\n";
    bool found = false;
    for(int i = 1; i <= n; i++) {
        if(level[i] == 2) {          // level 2 = friend of friend
            cout << i << " ";
            found = true;
        }
    }

    if(!found) cout << "No suggestions available.";
    cout << endl;
}

int main() {
    int n, u, v;
    cout << "Enter number of users: ";
    cin >> n;

    vector<vector<int>> graph(n+1);   // adjacency list (graph)

    cout << "Enter friend connections (edges):\n";
    for(int i = 0; i < n-1; i++) {    // taking sample edges
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int user;
    cout << "\nSuggest friends for user: ";
    cin >> user;

    BFS(user, graph, n);
    return 0;
}

// ✅ Algorithm

// Objective: Suggest friends to a user using BFS by finding all nodes at distance = 2 (friend-of-friend).
// Input the number of users n.
// Create an adjacency list graph to store connections.
// Input friendships and store edges in the graph.
// Ask for the user whose friends need to be suggested.
// Run BFS starting from the given user:
// Create array level[] initialized with −1 (unvisited).
// Set level[start] = 0 and push start into queue.
// While queue is not empty:
// Pop front node u.
// For each connected user v
// If v is unvisited → set level[v] = level[u] + 1 and push v into queue.
// After BFS completes:
// Traverse level[] array.
// If level[i] == 2, then i is suggested friend.
// Display all suggested friends; if none found, print message.

// 🧾 Pseudo-code

// START

// INPUT n   // number of users
// CREATE graph as adjacency list of size n

// FOR i = 1 TO n-1 DO
//     INPUT u, v
//     ADD v to graph[u]
//     ADD u to graph[v]
// END FOR

// INPUT start  // user requesting suggestions

// INITIALIZE level[1..n] with -1
// CREATE empty queue q

// SET level[start] = 0
// ENQUEUE start into q

// WHILE q is NOT empty DO
//     u = DEQUEUE q
//     FOR each friend v in graph[u] DO
//         IF level[v] == -1 THEN
//             SET level[v] = level[u] + 1
//             ENQUEUE v into q
//         END IF
//     END FOR
// END WHILE

// PRINT "Friend suggestions for user start:"
// found = FALSE

// FOR i = 1 TO n DO
//     IF level[i] == 2 THEN
//         PRINT i
//         found = TRUE
//     END IF
// END FOR

// IF found == FALSE THEN
//     PRINT "No suggestions available."

// END


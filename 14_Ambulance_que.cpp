#include <iostream>
#include <queue>
using namespace std;

class Case {
public:
    string name;
    int priority;

    Case(string n, int p) {
        name = n;
        priority = p;
    }
};
struct Compare {
    bool operator()(Case const& c1, Case const& c2) {
        return c1.priority < c2.priority;  
    }
};
int main() {
    priority_queue<Case, vector<Case>, Compare> pq;

    int choice;
    do {
        cout << "\n--- Ambulance Dispatch System ---\n";
        cout << "1. Add Emergency Case\n";
        cout << "2. Dispatch Next Ambulance\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            string name;
            int p;
            cout << "Enter patient name: ";
            cin >> name;
            cout << "Enter priority (1-10): ";
            cin >> p;
            pq.push(Case(name,p));
            cout << "Case added.\n";
        }

        else if(choice == 2) {
            if(pq.empty()) {
                cout << "No emergency cases waiting!\n";
            } else {
                Case top = pq.top();
                pq.pop();
                cout << "\n Ambulance dispatched for: " << top.name;
                cout << " (Priority = " << top.priority << ")\n";
            }
        }

    } while(choice != 3);

    return 0;
}


// ✅ Algorithm
// Start
// Create a max priority queue pq to store emergency cases
// (Higher priority number → treated first)
// Repeat until user chooses Exit:
// Display menu
// 1. Add Emergency Case
// 2. Dispatch Next Ambulance
// 3. Exit
// Input user's choice
// If choice = 1 (Add Case):
// Input patient name and priority level
// Create a Case object with (name, priority)
// Insert it into the priority queue
// Display "Case added"
// If choice = 2 (Dispatch Case):
// If priority queue is empty
// → display "No emergency cases waiting"
// Else
// Remove highest-priority case (top element)
// Display name and priority of dispatched case
// If choice = 3
// Exit program
// End

// 🧾 Pseudo-code

// START

// CREATE priority_queue pq   // stores Case objects (max priority first)

// REPEAT
//     DISPLAY menu
//     INPUT choice

//     IF choice = 1 THEN
//         INPUT name
//         INPUT priority
//         CREATE Case (name, priority)
//         INSERT Case into pq
//         PRINT "Case added"

//     ELSE IF choice = 2 THEN
//         IF pq is empty THEN
//             PRINT "No emergency cases waiting"
//         ELSE
//             REMOVE top Case from pq
//             PRINT "Ambulance dispatched for case name and priority"
//         END IF

// UNTIL choice = 3

// END

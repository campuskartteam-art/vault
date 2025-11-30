#include <iostream>
using namespace std;

#define SIZE 5  // size of circular queue

class CircularQueue {
    string queue[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    // Add passenger to queue
    void boardPassenger(string name) {
        if ((rear + 1) % SIZE == front) {
            cout << "Queue Full! No more passengers can board.\n";
        }
        else {
            if (front == -1) front = 0;  // first passenger
            rear = (rear + 1) % SIZE;
            queue[rear] = name;
            cout << name << " boarded the bus.\n";
        }
    }

    // Remove passenger from queue
    void exitPassenger() {
        if (front == -1) {
            cout << "Queue Empty! No passenger to exit.\n";
        }
        else {
            cout << queue[front] << " exited the bus.\n";
            if (front == rear)    // last passenger exits
                front = rear = -1;
            else
                front = (front + 1) % SIZE;
        }
    }

    // Display current status
    void displayQueue() {
        if (front == -1) {
            cout << "No passengers in the queue.\n";
            return;
        }
        cout << "\nPassengers currently in queue: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue bus;
    int choice;
    string name;

    do {
        cout << "\n--- BUS TICKET COUNTER MENU ---\n";
        cout << "1. Passenger Board\n2. Passenger Exit\n3. Display Queue\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter passenger name: ";
                cin >> name;
                bus.boardPassenger(name);
                break;

            case 2:
                bus.exitPassenger();
                break;

            case 3:
                bus.displayQueue();
                break;

            case 4:
                cout << "End of Simulation.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 4);

    return 0;
}

// ✅ Algorithm (Step-by-Step)
// Initialization
// Start
// Set front = -1, rear = -1
// Create queue[SIZE]
// Operation 1: Board Passenger
// Input name
// Check Queue Full condition:
// If (rear + 1) % SIZE == front → Print "Queue Full" and stop
// Else
// If front == -1 → set front = 0 (first passenger)
// Set rear = (rear + 1) % SIZE
// Insert name at queue[rear]
// Print "name boarded the bus"
// Operation 2: Exit Passenger
// Check Queue Empty condition:
// If front == -1 → Print "Queue Empty" and stop
// Else
// Print "queue[front] exited the bus"
// If front == rear → set front = rear = -1 (queue becomes empty)
// Else → set front = (front + 1) % SIZE
// Operation 3: Display Queue
// If front == -1 → Print "No passengers in queue" and stop
// Else
// Set i = front
// While i != rear
// Print queue[i]
// Set i = (i + 1) % SIZE
// Print last element queue[rear]
// Termination
// Repeat operations until user chooses Exit (choice = 4)
// Stop

// 🧾 Pseudo Code

// START
// DECLARE queue[SIZE], front = -1, rear = -1

// REPEAT
//     DISPLAY menu
//     INPUT choice

//     CASE 1: // Board Passenger
//         INPUT name
//         IF (rear + 1) % SIZE == front THEN
//             PRINT "Queue Full"
//         ELSE
//             IF front == -1 THEN
//                 front = 0
//             ENDIF
//             rear = (rear + 1) % SIZE
//             queue[rear] = name
//             PRINT name + " boarded"
//         ENDIF

//     CASE 2: // Exit Passenger
//         IF front == -1 THEN
//             PRINT "Queue Empty"
//         ELSE
//             PRINT queue[front] + " exited"
//             IF front == rear THEN
//                 front = -1
//                 rear = -1
//             ELSE
//                 front = (front + 1) % SIZE
//             ENDIF
//         ENDIF

//     CASE 3: // Display Queue
//         IF front == -1 THEN
//             PRINT "No passengers in queue"
//         ELSE
//             i = front
//             WHILE TRUE
//                 PRINT queue[i]
//                 IF i == rear THEN
//                     BREAK
//                 ENDIF
//                 i = (i + 1) % SIZE
//             ENDWHILE
//         ENDIF

//     CASE 4:
//         PRINT "End of Simulation"

//     DEFAULT:
//         PRINT "Invalid Choice"
// END REPEAT UNTIL choice == 4

// STOP

#include <iostream>
#include <list>   // for chaining
using namespace std;

class ParcelSystem {
private:
    static const int SIZE = 10;     // hash table size
    list<int> table[SIZE];          // array of linked lists

public:
    // Hash Function
    int hashFunction(int trackingNo) {
        return trackingNo % SIZE;
    }

    // Insert Parcel
    void insertParcel(int trackingNo) {
        int index = hashFunction(trackingNo);
        table[index].push_back(trackingNo);
        cout << "Parcel Added at Slot " << index << endl;
    }

    // Search Parcel
    void searchParcel(int trackingNo) {
        int index = hashFunction(trackingNo);
        for(int x : table[index]) {
            if(x == trackingNo) {
                cout << "Parcel Found in Slot " << index << endl;
                return;
            }
        }
        cout << "Parcel NOT found!" << endl;
    }

    // Display All Parcels
    void display() {
        cout << "\n--- Railway Parcel Records ---\n";
        for(int i = 0; i < SIZE; i++) {
            cout << "Slot " << i << ": ";
            for(int x : table[i])
                cout << x << " -> ";
            cout << "NULL\n";
        }
    }
};

int main() {
    ParcelSystem ps;
    int choice, trackingNo;

    while(true) {
        cout << "\n1. Add Parcel\n2. Search Parcel\n3. Display All\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Tracking Number: ";
                cin >> trackingNo;
                ps.insertParcel(trackingNo);
                break;
            case 2:
                cout << "Enter Tracking Number to Search: ";
                cin >> trackingNo;
                ps.searchParcel(trackingNo);
                break;
            case 3:
                ps.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!";
        }
    }
}

// 📌 Algorithm
// Start
// Create a hash table of fixed size (SIZE = 10), each index storing a linked list
// Repeat the menu operations:
// 1. Add Parcel
// 2. Search Parcel
// 3. Display All
// 4. Exit
// If Add Parcel:
// Input tracking number
// Compute index = tracking number % SIZE
// Insert tracking number into linked list at that index
// Display "Parcel Added"
// If Search Parcel:
// Input tracking number
// Compute index = tracking number % SIZE
// Traverse linked list at that index
// If found → Display "Parcel Found"
// Else → Display "Parcel NOT found"
// If Display All:
// For each slot from 0 to SIZE–1
// Print all values in linked list in that slot
// If Exit → Terminate program
// Otherwise, show "Invalid input"
// End

// 🧾 Pseudo Code
// START

// DEFINE SIZE = 10
// DECLARE hashTable[SIZE] as array of linked lists

// FUNCTION hashFunction(trackingNo):
//     RETURN trackingNo % SIZE

// FUNCTION insertParcel(trackingNo):
//     index = hashFunction(trackingNo)
//     INSERT trackingNo at end of hashTable[index]
//     PRINT "Parcel Added at Slot ", index

// FUNCTION searchParcel(trackingNo):
//     index = hashFunction(trackingNo)
//     FOR each item in hashTable[index]:
//         IF item == trackingNo THEN
//             PRINT "Parcel Found in Slot ", index
//             RETURN
//     PRINT "Parcel NOT found"

// FUNCTION display():
//     PRINT "Railway Parcel Records"
//     FOR i = 0 TO SIZE-1:
//         PRINT "Slot ", i, ": "
//         FOR each element in hashTable[i]:
//             PRINT element + " -> "
//         PRINT "NULL"

// MAIN PROGRAM:
//     DECLARE choice, trackingNo
//     LOOP forever
//         DISPLAY menu
//         INPUT choice

//         SWITCH(choice):
//             CASE 1:
//                 INPUT trackingNo
//                 CALL insertParcel(trackingNo)
//                 BREAK

//             CASE 2:
//                 INPUT trackingNo
//                 CALL searchParcel(trackingNo)
//                 BREAK

//             CASE 3:
//                 CALL display()
//                 BREAK

//             CASE 4:
//                 EXIT program

//             DEFAULT:
//                 PRINT "Invalid choice"
//         END SWITCH
//     END LOOP

// END

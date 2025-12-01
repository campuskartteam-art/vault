#include <iostream>
using namespace std;

#define SIZE 10   // hash table size

// Insert SKU using linear probing
void insertSKU(int hashTable[], int sku) {
    int index = sku % SIZE;
    int start = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;

        if (index == start) {
            cout << "Hash table is full! Cannot insert.\n";
            return;
        }
    }
    hashTable[index] = sku;
    cout << "Inserted successfully!\n";
}

// Search SKU
void searchSKU(int hashTable[], int sku) {
    int index = sku % SIZE;
    int start = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == sku) {
            cout << "SKU found at index " << index << endl;
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start) break;
    }
    cout << "SKU NOT found!\n";
}

// Display Hash Table
void display(int hashTable[]) {
    cout << "\nHash Table:\n";
    for (int i = 0; i < SIZE; i++)
        cout << i << " → " << hashTable[i] << endl;
}

int main() {
    int hashTable[SIZE];

    // Initialize hash table with -1 (empty)
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    int choice, sku;

    while (true) {
        cout << "\n===== PRODUCT LOOKUP USING HASHING =====";
        cout << "\n1. Insert SKU";
        cout << "\n2. Search SKU";
        cout << "\n3. Display Hash Table";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter SKU to insert: ";
                cin >> sku;
                insertSKU(hashTable, sku);
                break;

            case 2:
                cout << "Enter SKU to search: ";
                cin >> sku;
                searchSKU(hashTable, sku);
                break;

            case 3:
                display(hashTable);
                break;

            case 4:
                cout << "Thank you! Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}



// ✅ Algorithm (Short)

// Initialize hashTable with -1.

// Insert SKU

// Compute index = SKU % SIZE

// If slot empty → store SKU

// Else → linear probe (index + 1) % SIZE until empty slot found

// Search SKU

// Compute index = SKU % SIZE

// While slot not empty:

// If SKU matches → found

// Else probe next (index + 1) % SIZE

// If loop completes → not found

// Display

// Print all hash table elements

// Exit

// Stop the program

// 🔹 Pseudo Code (Short)
// Initialize hashTable[i] = -1

// REPEAT
//   Print menu
//   Input choice

//   IF choice = 1 THEN        // Insert
//       Input sku
//       index = sku % SIZE
//       WHILE hashTable[index] ≠ -1 DO
//            index = (index + 1) % SIZE
//       END WHILE
//       hashTable[index] = sku

//   ELSE IF choice = 2 THEN   // Search
//       Input sku
//       index = sku % SIZE
//       start = index
//       found = FALSE
//       WHILE hashTable[index] ≠ -1 DO
//            IF hashTable[index] = sku THEN found = TRUE; BREAK
//            index = (index + 1) % SIZE
//            IF index = start THEN BREAK
//       END WHILE
//       IF found THEN Print "Found" ELSE Print "Not found"

//   ELSE IF choice = 3 THEN   // Display
//       FOR i = 0 TO SIZE-1 PRINT hashTable[i]

// UNTIL choice = 4    // Exit

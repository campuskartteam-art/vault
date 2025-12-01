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

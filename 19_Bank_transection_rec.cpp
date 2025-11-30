#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Structure to store each transaction
struct Transaction {
    string type;
    int amount;
};

int main() {
    queue<Transaction> q;
    int n;
    int balance = 0;

    cout << "Enter number of transactions: ";
    cin >> n;

    // Taking user input for transactions
    for (int i = 0; i < n; i++) {
        Transaction t;
        cout << "\nEnter transaction type (Deposit/Withdraw): ";
        cin >> t.type;

        cout << "Enter amount: ";
        cin >> t.amount;

        q.push(t); // Add transaction to queue
    }

    cout << "\nProcessing Transactions...\n";

    // Processing transactions in FIFO order
    while (!q.empty()) {
        Transaction t = q.front();
        q.pop();

        if (t.type == "Deposit" || t.type == "deposit") {
            balance += t.amount;
            cout << "Processed: Deposit " << t.amount 
                 << " | Balance = " << balance << endl;
        }
        else if (t.type == "Withdraw" || t.type == "withdraw") {
            balance -= t.amount;
            cout << "Processed: Withdraw " << t.amount
                 << " | Balance = " << balance << endl;
        }
        else {
            cout << "Invalid transaction type! Skipped.\n";
        }
    }

    cout << "\nFinal Balance = " << balance << endl;
    return 0;
}

// ✅ Algorithm
// Start.
// Initialize balance = 0.
// Input number of transactions n.
// Create an empty queue q.
// Repeat n times:
// Input transaction type (Deposit / Withdraw).
// Input amount.
// Store type and amount in a structure object t.
// Push t into queue.
// While queue is not empty:
// Remove the front transaction t.
// If transaction type is Deposit:
// Add amount to balance.
// Display transaction and updated balance.
// Else if transaction type is Withdraw:
// Subtract amount from balance.
// Display transaction and updated balance.
// Else:
// Display "Invalid transaction type".
// After all transactions are processed, print final balance.
// End.


// 📌 Pseudocode
// START

// SET balance = 0
// INPUT n
// CREATE empty queue q

// FOR i = 1 TO n
//     INPUT type
//     INPUT amount
//     CREATE transaction t with (type, amount)
//     ENQUEUE t into q
// END FOR

// PRINT "Processing Transactions..."

// WHILE queue q is not empty
//     t = FRONT of q
//     DEQUEUE q

//     IF t.type = "Deposit" OR "deposit"
//          balance = balance + t.amount
//          PRINT "Processed: Deposit", t.amount, "Balance =", balance
//     ELSE IF t.type = "Withdraw" OR "withdraw"
//          balance = balance - t.amount
//          PRINT "Processed: Withdraw", t.amount, "Balance =", balance
//     ELSE
//          PRINT "Invalid transaction type! Skipped"
//     END IF
// END WHILE

// PRINT "Final Balance =", balance

// END

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> bookStack;
    int choice;
    string book;

    while(true) {
        cout << "\n--- Book Return Bin ---\n";
        cout << "1. Return Book (Push)\n";
        cout << "2. Process Returned Book (Pop)\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter book name: ";
                cin >> book;
                bookStack.push(book);
                cout << "Book returned to bin!\n";
                break;
            
            case 2:
                if(bookStack.empty()) {
                    cout << "No books to process!\n";
                } else {
                    cout << "Processing: " << bookStack.top() << endl;
                    bookStack.pop();
                }
                break;

            case 3:
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}

// 📌 Algorithm
// Start
// Create an empty stack named bookStack
// Repeat forever:
// Display menu
// 1. Return Book
// 2. Process Returned Book
// 3. Exit
// Take user's choice
// If choice = 1 (Return book):
// Input book name
// Push book onto bookStack
// Display "Book returned to bin"
// If choice = 2 (Process book):
// If stack is empty
// → display "No books to process"
// Else
// Display book at top of stack (top())
// Remove that book from stack (pop())
// If choice = 3
// → Terminate the program
// If invalid choice
// → Display "Invalid choice"
// End

// 🧾 Pseudo-code

// START

// DECLARE stack bookStack
// DECLARE choice, book

// LOOP forever
//     DISPLAY menu
//     INPUT choice

//     SWITCH choice
//         CASE 1:
//             INPUT book
//             PUSH book into bookStack
//             PRINT "Book returned to bin"
//             BREAK

//         CASE 2:
//             IF bookStack is empty THEN
//                 PRINT "No books to process"
//             ELSE
//                 PRINT "Processing: " + TOP(bookStack)
//                 POP bookStack
//             ENDIF
//             BREAK

//         CASE 3:
//             EXIT program

//         DEFAULT:
//             PRINT "Invalid choice"
//     END SWITCH
// END LOOP

// END

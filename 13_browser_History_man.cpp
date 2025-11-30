#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> backStack, forwardStack;
    string currentPage = "Home";  // browser opens at Home

    int choice;
    do {
        cout << "\n--- Browser History Menu ---\n";
        cout << "1. Open New Page\n";
        cout << "2. Back\n";
        cout << "3. Forward\n";
        cout << "4. Show Current Page\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            cout << "Enter page URL: ";
            string url;
            cin >> url;
            
            backStack.push(currentPage);    // save current page
            currentPage = url;              // move to new page
            while(!forwardStack.empty())    // clear forward stack
                forwardStack.pop();

            cout << "Opened: " << currentPage << endl;
        }

        else if(choice == 2) {
            if(backStack.empty())
                cout << "No history to go back!\n";
            else {
                forwardStack.push(currentPage);
                currentPage = backStack.top();
                backStack.pop();
                cout << "Moved Back to: " << currentPage << endl;
            }
        }

        else if(choice == 3) {
            if(forwardStack.empty())
                cout << "No forward pages!\n";
            else {
                backStack.push(currentPage);
                currentPage = forwardStack.top();
                forwardStack.pop();
                cout << "Moved Forward to: " << currentPage << endl;
            }
        }

        else if(choice == 4) {
            cout << "Current Page: " << currentPage << endl;
        }

    } while(choice != 5);

    return 0;
}

// ✅ Algorithm
// Initialize
// currentPage = "Home"
// backStack and forwardStack as empty stacks
// Display menu continuously until user selects Exit:
// 1. Open New Page
// 2. Back
// 3. Forward
// 4. Show Current Page
// 5. Exit
// If user selects Open New Page
// Read new URL
// Push currentPage into backStack
// Set currentPage = new URL
// Clear forwardStack (because new page breaks forward history)
// If user selects Back
// If backStack is empty → print "No history to go back"
// Else:
// Push currentPage into forwardStack
// Set currentPage = top of backStack
// Pop from backStack
// If user selects Forward
// If forwardStack is empty → print "No forward pages"
// Else:
// Push currentPage into backStack
// Set currentPage = top of forwardStack
// Pop from forwardStack
// If user selects Show Current Page
// Print currentPage
// Exit when user enters 5.

// 🧾 Pseudo-code

// START

// SET currentPage = "Home"
// INITIALIZE empty stacks backStack, forwardStack

// REPEAT
//     DISPLAY browser menu
//     INPUT choice

//     IF choice = 1 THEN
//         INPUT new URL
//         PUSH currentPage onto backStack
//         SET currentPage = new URL
//         CLEAR forwardStack
//         PRINT "Opened new page"

//     ELSE IF choice = 2 THEN
//         IF backStack is empty THEN
//             PRINT "No history to go back"
//         ELSE
//             PUSH currentPage onto forwardStack
//             SET currentPage = TOP of backStack
//             POP backStack
//             PRINT "Moved Back to currentPage"
//         END IF

//     ELSE IF choice = 3 THEN
//         IF forwardStack is empty THEN
//             PRINT "No forward pages"
//         ELSE
//             PUSH currentPage onto backStack
//             SET currentPage = TOP of forwardStack
//             POP forwardStack
//             PRINT "Moved Forward to currentPage"
//         END IF

//     ELSE IF choice = 4 THEN
//         PRINT currentPage
//     END IF

// UNTIL choice = 5

// END

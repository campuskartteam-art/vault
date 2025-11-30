#include <iostream>
#include <string>
using namespace std;

class Seat {
public:
    int row, col;
    string name;
};

int main() {
    int rows = 5, cols = 6;
    int n;

    cout << "How many seats you want to book? ";
    cin >> n;

    Seat booked[50];  // Only store booked seats (Sparse)

    for(int i = 0; i < n; i++) {
        cout << "\nEnter row, column and passenger name: ";
        cin >> booked[i].row >> booked[i].col >> booked[i].name;
    }

    cout << "\n--- Seat Layout ---\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            bool flag = false;

            // Check if seat is booked
            for(int k = 0; k < n; k++) {
                if(booked[k].row == i && booked[k].col == j)
                    flag = true;
            }

            if(flag) cout << "1 ";  // Booked
            else     cout << "0 ";  // Empty
        }
        cout << endl;
    }

    cout << "\n--- Booked Seats with Passenger Name ---\n";
    for(int i = 0; i < n; i++) {
        cout << "Seat (" << booked[i].row << "," << booked[i].col
             << ") -> " << booked[i].name << endl;
    }

    return 0;
}
// ✅ Algorithm
// Start
// Initialize number of rows = 5 and columns = 6
// Declare an integer n for number of seats to book
// Declare an array booked[50] to store booked seat information (row, column, passenger name)
// Display: “How many seats you want to book?”
// Input n
// For each seat from 1 to n
// Input row, column, and passenger name
// Store into booked array
// Display seat layout
// For i from 0 to rows−1
// For j from 0 to cols−1
// Set flag = false
// For k from 0 to n−1
// If booked[k].row == i and booked[k].col == j → set flag = true
// If flag is true → print 1 (seat booked)
// Else → print 0 (seat empty)
// Display list of booked seats with passenger names
// End

// 📝 Pseudocode

// START

// SET rows = 5, cols = 6
// DECLARE n
// DECLARE array booked[50] of Seat (row, col, name)

// PRINT "How many seats you want to book?"
// READ n

// FOR i = 0 TO n - 1 DO
//     PRINT "Enter row, column and passenger name"
//     READ booked[i].row, booked[i].col, booked[i].name
// END FOR

// PRINT "--- Seat Layout ---"

// FOR i = 0 TO rows - 1 DO
//     FOR j = 0 TO cols - 1 DO
//         SET flag = false

//         FOR k = 0 TO n - 1 DO
//             IF booked[k].row == i AND booked[k].col == j THEN
//                 flag = true
//             END IF
//         END FOR

//         IF flag == true THEN
//             PRINT "1 "
//         ELSE
//             PRINT "0 "
//         END IF
//     END FOR
//     PRINT new line
// END FOR

// PRINT "--- Booked Seats with Passenger Name ---"

// FOR i = 0 TO n - 1 DO
//     PRINT "Seat (" booked[i].row "," booked[i].col ") -> " booked[i].name
// END FOR
// END

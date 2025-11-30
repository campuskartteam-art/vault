#include <iostream>
#include <string>
using namespace std;

// Class to store absence information (Sparse Element)
class Absence {
public:
    int student;       // student index
    int day;           // day index
    string name;       // student name
};

int main() {
    int students, days, absCount;

    cout << "Enter number of students: ";
    cin >> students;

    cout << "Enter number of days: ";
    cin >> days;

    cout << "Enter number of absences to record: ";
    cin >> absCount;

    Absence A[100];   // Sparse array storing only absentees

    cout << "\nEnter absence records as -> student_no  day_no  student_name\n";
    for(int i = 0; i < absCount; i++) {
        cout << "Record " << i+1 << ": ";
        cin >> A[i].student >> A[i].day >> A[i].name;
    }

    // ==================== Display Sparse Absence Records ====================
    cout << "\n===== Sparse Attendance (Only Absentees) =====\n";
    for(int i = 0; i < absCount; i++) {
        cout << "Student " << A[i].student 
             << " was absent on Day " << A[i].day
             << " -> Name: " << A[i].name << endl;
    }

    // ==================== Display Full Attendance Matrix ====================
    cout << "\n===== Full Attendance Matrix =====\n";
    cout << "0 = Present | 1 = Absent\n";

    for(int i = 0; i < students; i++) {
        for(int j = 0; j < days; j++) {
            bool absent = false;

            // Check if student i was absent on day j
            for(int k = 0; k < absCount; k++) {
                if(A[k].student == i && A[k].day == j) {
                    absent = true;
                    break;
                }
            }
            cout << (absent ? "1 " : "0 ");
        }
        cout << endl;
    }

    int count =0;
    for(int i=0;i<students;i++){

        if(A[i].day==1) count ++;

    }

    return 0;
}

// ✅ Algorithm
// Start
// Input number of students → students
// Input number of days → days
// Input number of absences → absCount
// Declare array A[100] to store absence records (student index, day index, student name)
// For each absence record from 1 to absCount
// Input student number, day number, and student name
// Store in array A
// Display sparse absence records (only absent students)
// Display full attendance matrix (0 = present, 1 = absent)
// Repeat for each student i from 0 to students−1
// For each day j from 0 to days−1
// Set absent = false
// Compare each stored absence record
// If record matches (student i , day j), set absent = true
// Print 1 if absent else print 0
// Initialize count = 0
// Count how many students were absent on day 1 using loop
// End

// 📝 Pseudocode
// START

// INPUT students
// INPUT days
// INPUT absCount

// DECLARE array A[100] of Absence (student, day, name)

// PRINT "Enter absence records (student_no day_no student_name)"
// FOR i = 0 TO absCount-1 DO
//     READ A[i].student, A[i].day, A[i].name
// END FOR

// PRINT "===== Sparse Attendance (Only Absentees) ====="
// FOR i = 0 TO absCount-1 DO
//     PRINT "Student", A[i].student, "absent on Day", A[i].day, "->", A[i].name
// END FOR

// PRINT "===== Full Attendance Matrix ====="
// PRINT "0 = Present | 1 = Absent"

// FOR i = 0 TO students-1 DO
//     FOR j = 0 TO days-1 DO
//         SET absent = false

//         FOR k = 0 TO absCount-1 DO
//             IF A[k].student == i AND A[k].day == j THEN
//                 absent = true
//             END IF
//         END FOR

//         IF absent == true THEN
//             PRINT "1 "
//         ELSE
//             PRINT "0 "
//         END IF
//     END FOR
//     PRINT newline
// END FOR

// SET count = 0
// FOR i = 0 TO students-1 DO
//     IF A[i].day == 1 THEN
//         count = count + 1
//     END IF
// END FOR

// END
